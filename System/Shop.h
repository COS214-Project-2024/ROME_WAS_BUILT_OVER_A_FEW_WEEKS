#ifndef SHOP_H
#define SHOP_H

#include "CommercialBuilding.h"

class Shop : public CommercialBuilding {
    private:
        int numEmployed;
        double taxRatePerPerson;
        int employmentCapacity;


    public:
        Shop(int numEmployees);
        virtual ~Shop();
        //int calculateTotalTaxes() override;
};

#endif