#ifndef ESTATE_H
#define ESTATE_H

#include "ResidentialBuilding.h"

class Estate : public ResidentialBuilding {
private:
    int numInhabitants;
    double taxRatePerPerson;
public:
    Estate(int capacity);
    virtual ~Estate();
    //int calculateTotalTax() override;
};

#endif