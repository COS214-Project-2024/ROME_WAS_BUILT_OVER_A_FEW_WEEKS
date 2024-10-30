#ifndef APARTMENT_H
#define APARTMENT_H

#include "ResidentialBuilding.h"

class Apartment : public ResidentialBuilding {
    private: 
        int numInhabitants;
        double taxRatePerUnit;

    public:
        Apartment(int numUnits);
        virtual ~Apartment() {};
        //int calculateTotalTaxes() override;
};

#endif