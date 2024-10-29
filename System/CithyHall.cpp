#include "CithyHall.h"

CityHall::CityHall(){
}

CityHall::CityHall(PoliticalSystem* politicalSystem){
    this->politicalSystem = politicalSystem;
}

void CityHall::setPoliticalSystem(PoliticalSystem* politicalSystem){
    this->politicalSystem = politicalSystem;
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

