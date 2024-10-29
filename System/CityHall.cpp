#include "CityHall.h"

CityHall::CityHall(){
    popeCoins = 100;
    currPopulation = 0;
    citySatisfaction = 100;
    chainHandleCounter = 1000; // This has to reach 0 before requests go through the chain (initially 1000 so that the player has time to prepare)
    chainHandleCounterMax = 100; // This is what chainHandleCounter will be set to once a request has been handled

}

void CityHall::setPoliticalSystem(PoliticalSystem* politicalSystem){
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
    
    return residentialSatisfaction + getRailwayBonus() + getAirportBonus();
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

void CityHall::setCityMap(CityMap *map){
    this->cityMap = map;
}

CityHall::~CityHall(){
    delete politicalSystem;
}