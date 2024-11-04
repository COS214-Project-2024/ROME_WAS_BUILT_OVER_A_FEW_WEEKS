#ifndef POLITICALSYSTEM_H
#define POLITICALSYSTEM_H

#include <string>

class PoliticalSystem {
public:
    PoliticalSystem();
    virtual std::string getSystemName() = 0;
    virtual int getTaxRateResidential() = 0;
    virtual int getTaxRateCommercial() = 0;
    virtual int getTaxRateIndustrial() = 0;
    virtual double getBudgetSplit() = 0; 
    virtual int getCitizenSatisfactionImpact() = 0; 
    virtual ~PoliticalSystem();
};

#endif