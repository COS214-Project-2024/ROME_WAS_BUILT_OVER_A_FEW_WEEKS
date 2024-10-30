#ifndef PARK_H
#define PARK_H

#include "Landmark.h"

class Park : public Landmark {
    private:
        int satisfactionIncrease;
    public:
        Park(int radiusOfEffect);
        virtual ~Park();
       // int calculateTotalTaxes() override;
};

#endif



