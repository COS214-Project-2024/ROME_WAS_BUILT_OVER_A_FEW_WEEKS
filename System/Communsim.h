#ifndef COMMUNSIM_H
#define COMMUNSIM_H
#include "PoliticalSystem.h"

class Communsim : public PoliticalSystem { 
public:
    Communsim();
    virtual int getTaxRateResidential();
    virtual int getTaxRateCommercial();
    virtual int getTaxRateIndustrial();
    virtual double budgetSplitTaxes();
    virtual int politicalAffectOnSatisfaction();
    ~Communsim();
};

#endif