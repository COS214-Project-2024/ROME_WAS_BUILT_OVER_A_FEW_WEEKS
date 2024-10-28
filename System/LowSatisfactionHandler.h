#ifndef LOWSATISFACTIONHANDLER_H
#define LOWSATISFACTIONHANDLER_H

#include "SatisfactionHandler.h"

class LowSatisfactionHandler: public SatisfactionHandler{
    public:
        LowSatisfactionHandler(SatisfactionHandler* nextHandler);
        void handle(int curSatisfaction, CityHall* cityHall) override;
};

#endif