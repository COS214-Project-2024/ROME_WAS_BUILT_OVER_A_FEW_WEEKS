#ifndef SATISFACTIONHANDLER_H
#define SATISFACTIONHANDLER_H

#include "CityHall.h"

class SatisfactionHandler{
    protected:
        SatisfactionHandler *nextHandler;
        float chanceOfPopulationChange;
        float incomeAffectionRate;
    public:
        virtual void handle(int curSatisfaction, CityHall* cityHall);
        void addHandler(SatisfactionHandler* nextHandler);
};

#endif