#ifndef CITY_HALL_H
#define CITY_HALL_H

#include "PoliticalSystem.h"

class CityHall {
public:
    CityHall();
    CityHall(PoliticalSystem* politicalSystem);
    void setPoliticalSystem(PoliticalSystem* politicalSystem);
    int getTaxRateResidential();
    int getTaxRateCommercial();
    int getTaxRateIndustrial();
    double getBudgetSplit(); //Higher the percentage the more money goes to the user
    int getCitizenSatisfactionImpact();
    ~CityHall();
private:
    PoliticalSystem* politicalSystem;
    int taxRateResidential;
    int taxRateCommercial;
    int taxRateIndustrial;
    double budgetSplit;
    int citizenSatisfactionImpact;
};

#endif