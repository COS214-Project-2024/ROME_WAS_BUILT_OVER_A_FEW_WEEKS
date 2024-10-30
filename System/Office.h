#ifndef OFFICE_H
#define OFFICE_H

#include "CommercialBuilding.h"

class Office : public CommercialBuilding {
private:
    int numEmployed;
    double taxRatePerPerson;
    int employmentCapacity;
public:
    Office(int radiusOfEffect);
    virtual ~Office();
    //int calculateTotalTaxes() override;
};

#endif