#ifndef MONUMENT_H
#define MONUMENT_H

#include "Landmark.h"

class Monument : public Landmark {
private:
    int satisfactionIncrease;
public:
    Monument(int radiusOfEffect);
    virtual ~Monument();
    //int calculateTotalTax() override;
};

#endif