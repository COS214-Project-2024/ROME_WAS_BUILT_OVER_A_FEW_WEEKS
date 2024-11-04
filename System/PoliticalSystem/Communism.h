#ifndef COMMUNISM_H
#define COMMUNISM_H
#include "PoliticalSystem.h"

class Communism : public PoliticalSystem { 
public:
    Communism();
    virtual std::string getSystemName();
    virtual int getTaxRateResidential();
    virtual int getTaxRateCommercial();
    virtual int getTaxRateIndustrial();
    virtual double getBudgetSplit();
    virtual int getCitizenSatisfactionImpact();
    ~Communism();
};

#endif