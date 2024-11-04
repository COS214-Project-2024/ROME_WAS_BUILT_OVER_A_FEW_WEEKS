#include <iostream>

#include "CityHall.h"
#include "SatisfactionHandler/LowSatisfactionHandler.h"
#include "SatisfactionHandler/MediumSatisfactionHandler.h"
#include "SatisfactionHandler/HighSatisfactionHandler.h"
#include "CityMap.h"
#include "BoosterStructures/Railway.h"
#include "BoosterStructures/Airport.h"
#include "PoliticalSystem/PoliticalSystem.h"
#include "BoosterStructures/School.h"
#include "BoosterStructures/Hospital.h"
#include "BoosterStructures/PoliceStation.h"

CityHall* CityHall::cityHall = nullptr;

CityHall::CityHall(){
    
    numCitizens = 0;
    cityCapacity = 0;
    numResidentialComplexes = 0;
    numCommercialBuildings = 0;
    numIndustrialBuildings = 0;
    popeCoins = 1000000;
    residentialSatisfaction = 0;
    citySatisfaction = 100;
    maxWood = 1000000;
    maxSteel = 1000000;
    maxConcrete = 1000000;
    wood = 10000;
    steel = 10000;
    concrete = 10000;
    
    railway = new Railway();
    airport = new Airport();
    school = new School();
    hospital = new Hospital();
    policeStation = new PoliceStation();

    taxRateResidential = 0;
    taxRateCommercial = 0;
    taxRateIndustrial = 0;
    budgetSplit = 0;
    citizenSatisfactionImpact = 0;

    // Set up the Chain of Responsibility
    LowSatisfactionHandler* lowHandler = new LowSatisfactionHandler(nullptr);
    MediumSatisfactionHandler* mediumHandler = new MediumSatisfactionHandler(lowHandler);
    HighSatisfactionHandler* highHandler = new HighSatisfactionHandler(mediumHandler);
    this->chainOfResponsibility = highHandler;
}

// SINGLETON
CityHall *CityHall::getInstance(){
    if (cityHall == nullptr){
        cityHall = new CityHall();
    }

    return cityHall;
}

void CityHall::setPoliticalSystem(PoliticalSystem *politicalSystem){
    this->politicalSystem = politicalSystem;
    getBudgetSplit();
    getTaxRateResidential();
    getTaxRateCommercial();
    getTaxRateIndustrial();
    getCitizenSatisfactionImpact();
}

void CityHall::birth(){
    numCitizens += 1;
}

void CityHall::death(){
    if (numCitizens > 0){
        numCitizens -= 1;
    }
}

void CityHall::emigrate(){
    if (numCitizens > 0){
        numCitizens -= 1;
    }
}

void CityHall::immigrate(){
    numCitizens += 1;
}

int CityHall::getNumCitizens(){
    return numCitizens;
}

int CityHall::getCityCapacity(){
    return cityCapacity;
}

int CityHall::getNumResidentialBuildings(){
    return numResidentialComplexes;
}

int CityHall::getCurrSatisfaction(){
    return citySatisfaction;
}

std::string CityHall::getStructureType(){
    return "CityHall";
}

int CityHall::getCost(){
    return 0;
}

float CityHall::calculateSatisfaction(){

    return residentialSatisfaction + getRailwayBonus() + getAirportBonus() + getSchoolBonus() + getPoliceStationBonus() + getHospitalBonus() - calculateHomelessnessDeduction();
}

void CityHall::calculateResidentialSatisfaction(float oldSatisfaction, float newSatisfaction){
    std::cout << "Old residential satisfaction: " << residentialSatisfaction << std::endl;
    std::cout << "numResidentialComplexes: " << numResidentialComplexes << std::endl;
    std::cout << "oldSatisfaction: " << oldSatisfaction << std::endl;
    std::cout << "newSatisfaction: " << newSatisfaction << std::endl;
    residentialSatisfaction = (numResidentialComplexes*residentialSatisfaction - oldSatisfaction + newSatisfaction) / numResidentialComplexes;
    std::cout << "New residential satisfaction: " << residentialSatisfaction << std::endl;
}

float CityHall::getRailwayBonus(){
    return (railway->getLevel() * railway->getSatisfactionMultiplier()); // level & multiplier
}

float CityHall::getAirportBonus(){
    return (airport->getLevel() * airport->getSatisfactionMultiplier()); // level & multiplier
}

float CityHall::getSchoolBonus(){
    return (school->getLevel() * school->getSatisfactionMultiplier()); // level & multiplier
}

float CityHall::getHospitalBonus(){
    return (hospital->getLevel() * hospital->getSatisfactionMultiplier()); // level & multiplier
}

float CityHall::getPoliceStationBonus(){
    return (policeStation->getLevel() * policeStation->getSatisfactionMultiplier()); // level & multiplier
}


float CityHall::calculateHomelessnessDeduction(){
    int numberHomelessPeople = 0;
    if(numCitizens == 0 || cityCapacity == 0){
        return 0;
    }
    if (numCitizens > cityCapacity){
        numberHomelessPeople = numCitizens - cityCapacity;
    }

    // Homelessness will deduct in proportion to population percentage
    // For example if homelessness accounts for 10% of population, then there will be a 10% deduction
    return (numberHomelessPeople/cityCapacity)*100;
}

void CityHall::populationChange(int satisfactionLevel){
    chainOfResponsibility->handlePopulation(citySatisfaction, this);
}

float CityHall::collectTaxes(int satisfactionLevel){
    return chainOfResponsibility->handleTax(citySatisfaction, this);
}

int CityHall::getTaxRateResidential(){
    taxRateResidential = politicalSystem->getTaxRateResidential();
    return taxRateResidential;
}

int CityHall::getTaxRateCommercial(){
    taxRateCommercial = politicalSystem->getTaxRateCommercial();
    return taxRateCommercial;
}

int CityHall::getTaxRateIndustrial(){
    taxRateIndustrial = politicalSystem->getTaxRateIndustrial();
    return taxRateIndustrial;
}

double CityHall::getBudgetSplit(){
    budgetSplit = politicalSystem->getBudgetSplit();
    return budgetSplit;
}

int CityHall::getCitizenSatisfactionImpact(){
    citizenSatisfactionImpact = politicalSystem->getCitizenSatisfactionImpact();
    citySatisfaction += citizenSatisfactionImpact;
    return citizenSatisfactionImpact;
}

CityHall::~CityHall(){
    delete politicalSystem;
}

bool CityHall::placeStructure(int x, int y, CityMap* cityMap) {
    // call base class function which assigns it to the map
    if (cityMap == nullptr){
        std::cout << "CityMap is null" << std::endl;
        return false;
    }
    cityMap->setCityHall(this);

    bool placed = CityStructure::placeStructure(x, y, cityMap); 
    if (placed) {
        return true;
    }
    else {
        return false;
    }
    
}

bool CityHall::removeStructure() {
    std::cout << "Cannot remove the city hall" << std::endl;
    return false;
}

void CityHall::increaseStorageCapacity(){
    maxWood += 1000;
    maxSteel += 1000;
    maxConcrete += 1000;
}

void CityHall::decreaseStorageCapacity(){
    maxWood -= 1000;
    maxSteel -= 1000;
    maxConcrete -= 1000;
}

void CityHall::increaseNumResidentialComplexes(){
    numResidentialComplexes++;
}
void CityHall::decreaseNumResidentialComplexes(){
    numResidentialComplexes--;
}

void CityHall::increaseNumCommercialBuildings(){
    numCommercialBuildings++;
}
void CityHall::decreaseNumCommercialBuildings(){
    numCommercialBuildings--;
}

void CityHall::increaseNumIndustrialBuildings(){
    numIndustrialBuildings++;
}
void CityHall::decreaseNumIndustrialBuildings(){
    numIndustrialBuildings--;
}

void CityHall::increaseNumFactories(){
    numFactories++;
}

void CityHall::decreaseNumFactories(){
    numFactories--;
}

int CityHall::getNumFactories(){
    return numFactories;
}

void CityHall::generateWood(int generatedAmount){
    int addedWood = generatedAmount* getNumFactories();
    addWood(addedWood);
    std::cout << "GENERATED WOOD: " << addedWood << std::endl;
}

void CityHall::generateSteel(int generatedAmount){
    int addedSteel = generatedAmount* getNumFactories();
    addSteel(addedSteel);
    std::cout << "GENERATED STEEL: " << addedSteel << std::endl;
}

void CityHall::generateConcrete(int generatedAmount){
    int addedConcrete = generatedAmount* getNumFactories();
    addConcrete(addedConcrete);
    std::cout << "GENERATED CONCRETE: " << addedConcrete << std::endl;
}


bool CityHall::addPopeCoins(int coins){
    popeCoins = popeCoins + coins;

    if (popeCoins > MAX_POPE_COINS){ // cap the coins
        popeCoins = MAX_POPE_COINS;
        return false;
    }
    return true;
}

bool CityHall::deductPopeCoins(int coins){
    if (popeCoins - coins < 0){
        std::cout << "Not enough pope coins" << std::endl;
        return false;
    }
    popeCoins = popeCoins - coins;
    std::cout << "Remaining " << popeCoins << " pope coins" << std::endl;
    return true;
}

bool CityHall::addWood(int wood){
    this->wood += wood;
    if(this->wood > maxWood){
        this->wood = maxWood;
        return false;
    }
    return true;
}

bool CityHall::deductWood(int wood){
    if (this->wood - wood < 0){
        std::cout << "Not enough wood" << std::endl;
        return false;
    }
    this->wood = this->wood - wood;
    std::cout << "Remaining " << this->wood << " wood" << std::endl;
    return true;
}

bool CityHall::addSteel(int steel){
    this->steel += steel;
    if(this->steel > maxSteel){
        this->steel = maxSteel;
        return false;
    }
    return true;
}

bool CityHall::deductSteel(int steel){
    if (this->steel - steel < 0){
        std::cout << "Not enough steel" << std::endl;
        return false;
    }
    this->steel = this->steel - steel;
    std::cout << "Remaining " << this->steel << " steel" << std::endl;
    return true;
}

bool CityHall::addConcrete(int concrete){
    this->concrete += concrete;
    if(this->concrete > maxConcrete){
        this->concrete = maxConcrete;
        return false;
    }
    return true;
}

bool CityHall::deductConcrete(int concrete){
    if (this->concrete - concrete < 0){
        std::cout << "Not enough concrete" << std::endl;
        return false;
    }
    this->concrete = this->concrete - concrete;
    std::cout << "Remaining " << this->concrete << " concrete" << std::endl;
    return true;
}

int CityHall::getStorageCapacity(){
    return maxWood;
}

void CityHall::increaseCapacity(int capacity)
{
    std::cout << "Increasing capacity" << std::endl;
    cityCapacity = cityCapacity + capacity;
}

void CityHall::decreaseCapacity(int capacity){
    cityCapacity = cityCapacity - capacity;
}

void CityHall::printCityHallState(){
    std::cout << "\033[1mCity Hall state\033[0m" << std::endl;
    std::cout << "\033[1mPolitical System: \033[0m" << politicalSystem->getSystemName() << std::endl;
    std::cout << "\033[1mNumber of citizens: \033[0m" << numCitizens << std::endl;
    std::cout << "\033[1mCity capacity: \033[0m" << cityCapacity << std::endl;
    std::cout << "\033[1mNumber of residential complexes: \033[0m" << numResidentialComplexes << std::endl;
    std::cout << "\033[1mNumber of commercial buildings: \033[0m" << numCommercialBuildings << std::endl;
    std::cout << "\033[1mNumber of industrial buildings: \033[0m" << numIndustrialBuildings << std::endl;
    std::cout << "\033[1mNumber of factories: \033[0m" << numFactories << std::endl;
    std::cout << "\033[1mPope coins: \033[0m" << popeCoins << std::endl;
    std::cout << "\033[1mWood: \033[0m" << wood << std::endl;
    std::cout << "\033[1mSteel: \033[0m" << steel << std::endl;
    std::cout << "\033[1mConcrete: \033[0m" << concrete << std::endl;
    std::cout << "\033[1mMax wood: \033[0m" << maxWood << std::endl;
    std::cout << "\033[1mMax steel: \033[0m" << maxSteel << std::endl;
    std::cout << "\033[1mMax concrete: \033[0m" << maxConcrete << std::endl;
    std::cout << "\033[1mResidential satisfaction: \033[0m" << residentialSatisfaction << std::endl;
    std::cout << "\033[1mCity satisfaction: \033[0m" << citySatisfaction << std::endl;
    std::cout << "\033[1mTax rate residential: \033[0m" << taxRateResidential << std::endl;
    std::cout << "\033[1mTax rate commercial: \033[0m" << taxRateCommercial << std::endl;
    std::cout << "\033[1mTax rate industrial: \033[0m" << taxRateIndustrial << std::endl;
    std::cout << "\033[1mBudget split: \033[0m" << budgetSplit << std::endl;
    std::cout << "\033[1mCitizen satisfaction impact: \033[0m" << citizenSatisfactionImpact << std::endl;
    std::cout << "\033[1mRailway bonus: \033[0m" << getRailwayBonus() << std::endl;
    std::cout << "\033[1mAirport bonus: \033[0m" << getAirportBonus() << std::endl;
    std::cout << "\033[1mSchool bonus: \033[0m" << getSchoolBonus() << std::endl;
    std::cout << "\033[1mHospital bonus: \033[0m" << getHospitalBonus() << std::endl;
    std::cout << "\033[1mPolice station bonus: \033[0m" << getPoliceStationBonus() << std::endl;
    std::cout << "\033[1mHomelessness deduction: \033[0m" << calculateHomelessnessDeduction() << std::endl;
}