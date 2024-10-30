#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

#include "ResidentialBuilding.h"


class Townhouse : public ResidentialBuilding {
    private: 
        int numInhabitants;
        double taxRatePerPerson;

    public:
        Townhouse(int numInhabitants);
        virtual ~Townhouse();
       // int calculateTotalTaxes() override;
};

#endif