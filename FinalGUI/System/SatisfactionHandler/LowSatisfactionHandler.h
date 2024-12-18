#ifndef LOWSATISFACTIONHANDLER_H
#define LOWSATISFACTIONHANDLER_H

#include "SatisfactionHandler.h"

class LowSatisfactionHandler: public SatisfactionHandler{
    public:
        LowSatisfactionHandler(SatisfactionHandler* nextHandler);
        float handleTax(int curSatisfaction, CityHall* cityHall) ;
        void handlePopulation(int curSatisfaction, CityHall* cityHall) ;
};

#endif