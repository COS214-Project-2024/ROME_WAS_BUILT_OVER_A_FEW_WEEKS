#include "CityHall.h"

CityHall* CityHall::cityHall = 0;

CityHall::CityHall(){
    popeCoins = 100;
    numCitizens = 0;
    citySatisfaction = 100;
    railway = new Railway();
    airport = new Airport();
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

int CityHall::getCurrSatisfaction(){
    return citySatisfaction;
}

float CityHall::calculateSatisfaction(){

    return residentialSatisfaction + getRailwayBonus() + getAirportBonus() - calculateHomelessnessDeduction();
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
    return citizenSatisfactionImpact;
}

CityHall::~CityHall(){
    delete politicalSystem;
}