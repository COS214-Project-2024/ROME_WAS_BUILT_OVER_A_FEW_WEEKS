#ifndef HIGHSATISFACTIONHANDLER_H
#define HIGHSATISFACTIONHANDLER_H

#include "SatisfactionHandler.h"

class HighSatisfactionHandler: public SatisfactionHandler{
    public:
        HighSatisfactionHandler(SatisfactionHandler* nextHandler);
        void handle(int curSatisfaction, CityHall* cityHall) override;
};

#endif