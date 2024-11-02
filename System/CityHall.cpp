#include <iostream>

#include "CityHall.h"
#include "SatisfactionHandler/LowSatisfactionHandler.h"
#include "SatisfactionHandler/MediumSatisfactionHandler.h"
#include "SatisfactionHandler/HighSatisfactionHandler.h"
#include "CityMap.h"
#include "BoosterStructures/Railway.h"
#include "BoosterStructures/Airport.h"
#include "PoliticalSystem/PoliticalSystem.h"

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
    maxWood = 1000;
    maxSteel = 1000;
    maxConcrete = 1000;
    
    railway = new Railway();
    airport = new Airport();

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

void CityHall::setPoliticalSystem(PoliticalSystem *politicalSystem)
{
    this->politicalSystem = politicalSystem;
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

    return residentialSatisfaction + getRailwayBonus() + getAirportBonus() - calculateHomelessnessDeduction();
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

float CityHall::calculateHomelessnessDeduction(){
    int numberHomelessPeople = 0;
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

void CityHall::removeStructure() {
    cityMap->removeStructure(x, y);
}

void CityHall::increaseStorageCapacity(){
    maxWood += 100;
    maxSteel += 100;
    maxConcrete += 100;
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
    std::cout << "remaining " << popeCoins << " pope coins" << std::endl;
    return true;
}

bool CityHall::addWood(int wood){
    this->wood += wood;
    return true;
}

bool CityHall::deductWood(int wood){
    if (this->wood - wood < 0){
        std::cout << "Not enough wood" << std::endl;
        return false;
    }
    this->wood = this->wood - wood;
    return true;
}

bool CityHall::addSteel(int steel){
    this->steel += steel;
    return true;
}

bool CityHall::deductSteel(int steel){
    if (this->steel - steel < 0){
        std::cout << "Not enough steel" << std::endl;
        return false;
    }
    this->steel = this->steel - steel;
    return true;
}

bool CityHall::addConcrete(int concrete){
    this->concrete += concrete;
    return true;
}

bool CityHall::deductConcrete(int concrete){
    if (this->concrete - concrete < 0){
        std::cout << "Not enough concrete" << std::endl;
        return false;
    }
    this->concrete = this->concrete - concrete;
    return true;
}

void CityHall::increaseCapacity(int capacity){
    std::cout << "Increasing capacity" << std::endl;
    cityCapacity = cityCapacity + capacity;
}

void CityHall::decreaseCapacity(int capacity){
    cityCapacity = cityCapacity - capacity;
}

void CityHall::printCityHallState(){
    std::cout << "City Hall state" << std::endl;
    std::cout << "Pope coins: " << popeCoins << std::endl;
    std::cout << "Number of citizens: " << numCitizens << std::endl;
    std::cout << "City capacity: " << cityCapacity << std::endl;
    std::cout << "City satisfaction: " << citySatisfaction << std::endl;
    std::cout << "Number of residential complexes: " << numResidentialComplexes << std::endl;
    std::cout << "Number of commercial buildings: " << numCommercialBuildings << std::endl;
    std::cout << "Number of industrial buildings: " << numIndustrialBuildings << std::endl;
    std::cout << "Tax rate residential: " << taxRateResidential << std::endl;
    std::cout << "Tax rate commercial: " << taxRateCommercial << std::endl;
    std::cout << "Tax rate industrial: " << taxRateIndustrial << std::endl;
    std::cout << "Budget split: " << budgetSplit << std::endl;
    std::cout << "Citizen satisfaction impact: " << citizenSatisfactionImpact << std::endl;
    std::cout << "Railway bonus: " << getRailwayBonus() << std::endl;
    std::cout << "Airport bonus: " << getAirportBonus() << std::endl;
    std::cout << "Homelessness deduction: " << calculateHomelessnessDeduction() << std::endl;
}