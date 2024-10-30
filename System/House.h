#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"


class House : public ResidentialBuilding {
    private: 
        int numInhabitants;
        double taxRatePrePerson;

    public:
        House(int numInhabitants);
        virtual ~House();
        //int calulateTotalTaxes() override;
};

#endif