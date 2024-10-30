#ifndef POLITICALSYSTEM_H
#define POLITICALSYSTEM_H


class PoliticalSystem {
public:
    PoliticalSystem();
    virtual int getTaxRateResidential() = 0;
    virtual int getTaxRateCommercial() = 0;
    virtual int getTaxRateIndustrial() = 0;
    virtual double budgetSplitTaxes() = 0; 
    virtual int politicalAffectOnSatisfaction() = 0; 
    ~PoliticalSystem();
};

#endif