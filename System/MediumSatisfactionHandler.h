#ifndef MEDIUMSATISFACTIONHANDLER_H
#define MEDIUMSATISFACTIONHANDLER_H

#include "SatisfactionHandler.h"

class MediumSatisfactionHandler: public SatisfactionHandler{
    public:
        MediumSatisfactionHandler(SatisfactionHandler* nextHandler);
        void handle(int curSatisfaction, CityHall* cityHall) override;
};

#endif