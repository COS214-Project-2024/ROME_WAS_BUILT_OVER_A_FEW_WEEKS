#include "CityHall.h"
#include "LowSatisfactionHandler.h"
#include "MediumSatisfactionHandler.h"
#include "HighSatisfactionHandler.h"

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
    return numResidentialBuildings;
}

int CityHall::getCurrSatisfaction(){
    return citySatisfaction;
}

float CityHall::calculateSatisfaction(){

    return residentialSatisfaction + getRailwayBonus() + getAirportBonus() - calculateHomelessnessDeduction();
}

void CityHall::calculateResidentialSatisfaction(float oldSatisfaction, float newSatisfaction){
    residentialSatisfaction = numResidentialBuildings*residentialSatisfaction - oldSatisfaction + newSatisfaction;
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
    return politicalSystem->getTaxRateResidential();
}

int CityHall::getTaxRateCommercial(){
    return politicalSystem->getTaxRateCommercial();
}

int CityHall::getTaxRateIndustrial(){
    return politicalSystem->getTaxRateIndustrial();;
}

double CityHall::getBudgetSplit(){
    return politicalSystem->budgetSplitTaxes();;
}

int CityHall::getCitizenSatisfactionImpact(){
    return politicalSystem->politicalAffectOnSatisfaction();;
}

void CityHall::budgetSplitTaxes(int collectedTaxes){
    popeCoins = popeCoins + collectedTaxes*getBudgetSplit();
}

void CityHall::politicalAffectOnSatisfaction(int satisfactionLevel){
    citySatisfaction = satisfactionLevel + getCitizenSatisfactionImpact();
}

CityHall::~CityHall(){
    delete politicalSystem;
}