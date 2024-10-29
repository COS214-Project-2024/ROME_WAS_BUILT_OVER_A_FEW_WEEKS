#ifndef MEDIUMSATISFACTIONHANDLER_H
#define MEDIUMSATISFACTIONHANDLER_H

#include "SatisfactionHandler.h"

class MediumSatisfactionHandler: public SatisfactionHandler{
    public:
        MediumSatisfactionHandler(SatisfactionHandler* nextHandler);
        void handlePopulation(int curSatisfaction, CityHall* cityHall) override;
        float handleTax(int curSatisfaction, CityHall* cityHall) override;
};

#endif