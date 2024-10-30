#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "IndustrialBuilding.h"

class Warehouse : public IndustrialBuilding {
    private:
        int numEmployees;
        double taxRatePerPerson;
        int employmentCapacity;

    public:
        Warehouse();
        virtual ~Warehouse();
        //int calculateTotalTaxes() override;
};

#endif