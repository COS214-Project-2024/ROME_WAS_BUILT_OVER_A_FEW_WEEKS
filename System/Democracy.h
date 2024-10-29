#ifndef DEMOCRACY_H
#define DEMOCRACY_
#include "PoliticalSystem.h"

class Democracy : public PoliticalSystem { 
public:
    Democracy();
    virtual int getTaxRateResidential();
    virtual int getTaxRateCommercial();
    virtual int getTaxRateIndustrial();
    virtual double getBudgetSplit();
    virtual int getCitizenSatisfactionImpact();
    ~Democracy();
};

#endif