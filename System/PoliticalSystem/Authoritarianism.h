#ifndef AUTHORITARIANISM_H
#define AUTHORITARIANISM_H

#include "PoliticalSystem.h"   

class Authoritarianism : public PoliticalSystem {
public:
    Authoritarianism();
    virtual int getTaxRateResidential();
    virtual int getTaxRateCommercial();
    virtual int getTaxRateIndustrial();
    virtual double getBudgetSplit();
    virtual int getCitizenSatisfactionImpact();
    ~Authoritarianism();
};

#endif