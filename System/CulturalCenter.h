#ifndef CULTURAL_CENTER_H
#define CULTURAL_CENTER_H

#include "Landmark.h"

class CulturalCenter : public Landmark {
private:
    int satisfactionIncrease;
    int numVisitors;
    double taxRatePerVisitor;
public:
    CulturalCenter(int radiusOfEffect);
    virtual ~CulturalCenter();
   // int calculateTotalTaxes() override;
};

#endif