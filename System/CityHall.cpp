#include "CityHall.h"
#include "LowSatisfactionHandler.h"
#include "MediumSatisfactionHandler.h"
#include "HighSatisfactionHandler.h"
#include "CityMap.h"
#include "Railway.h"
#include "Airport.h"
#include "PoliticalSystem.h"

CityHall* CityHall::cityHall = 0;

CityHall::CityHall(){
    popeCoins = 100;
    numCitizens = 0;
    citySatisfaction = 100;
    railway = new Railway();
    airport = new Airport();

    // Set up the Chain of Responsibility
    LowSatisfactionHandler* lowHandler = new LowSatisfactionHandler(nullptr);
    MediumSatisfactionHandler* mediumHandler = new MediumSatisfactionHandler(lowHandler);
    HighSatisfactionHandler* highHandler = new HighSatisfactionHandler(mediumHandler);
    this->chainOfResponsibility = highHandler;
}

// SINGLETON
CityHall *CityHall::getInstance(){
    if (cityHall == 0){
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
    residentialSatisfaction = (numResidentialComplexes*residentialSatisfaction - oldSatisfaction + newSatisfaction) / numResidentialComplexes;
}

float CityHall::getRailwayBonus(){
    return (railway->getLevel() * railway->getSatisfactionMultiplier()); // level & multiplier
}

float CityHall::getAirportBonus(){
    return (airport->getLevel() * airport->getSatisfactionMultiplier()); // level & multiplier
}

float CityHall::calculateHomelessnessDeduction(){
    int numberHomelessPeople = cityCapacity - numCitizens;

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

void CityHall::placeStructure(int x, int y, CityMap* cityMap) {
    // call base class function which assigns it to the map
    CityStructure::placeStructure(x, y, cityMap); 
    this->cityMap->setCityHall(this);
}

void CityHall::removeStructure() {
    cityMap->removeStructure(x, y);
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
        return false;
    }
    popeCoins = popeCoins - coins;
    return true;
}


void CityHall::increaseCapacity(int capacity){
    cityCapacity = cityCapacity + capacity;
}

void CityHall::decreaseCapacity(int capacity){
    cityCapacity = cityCapacity - capacity;
}


