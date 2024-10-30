#ifndef MALL_H
#define MALL_H

#include "CommercialBuilding.h"

class Mall : public CommercialBuilding {
    private:
        int numEmployed;
        double taxRatePerPerson;
        int employmentCapacity;

    public:
        Mall(int radiusOfEffect);
        virtual ~Mall();
        //int calculateTotalTaxes() override;
};

#endif