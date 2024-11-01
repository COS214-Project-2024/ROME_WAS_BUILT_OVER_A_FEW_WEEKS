#ifndef MEDIUMSATISFACTIONHANDLER_H
#define MEDIUMSATISFACTIONHANDLER_H

#include "SatisfactionHandler.h"

class MediumSatisfactionHandler: public SatisfactionHandler{
    public:
        MediumSatisfactionHandler(SatisfactionHandler* nextHandler);
        void handlePopulation(int curSatisfaction, CityHall* cityHall) ;
        float handleTax(int curSatisfaction, CityHall* cityHall) ;
};

#endif