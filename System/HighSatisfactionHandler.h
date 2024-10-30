#ifndef HIGHSATISFACTIONHANDLER_H
#define HIGHSATISFACTIONHANDLER_H

#include "SatisfactionHandler.h"

class HighSatisfactionHandler: public SatisfactionHandler{
    public:
        HighSatisfactionHandler(SatisfactionHandler* nextHandler);
        void handlePopulation(int curSatisfaction, CityHall* cityHall) override;
        float handleTax(int curSatisfaction, CityHall* cityHall) override;
};

#endif