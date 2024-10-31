#ifndef SATISFACTIONHANDLER_H
#define SATISFACTIONHANDLER_H

#include "CityHall.h"
#include "CityHall.h"

class SatisfactionHandler{
    protected:
        SatisfactionHandler *nextHandler;
        float chanceOfPopulationChange;
        float incomeAffectionRate;
    public:
        virtual float handleTax(int curSatisfaction, CityHall* cityHall);
        virtual void handlePopulation(int curSatisfaction, CityHall* cityHall);
        void addHandler(SatisfactionHandler* nextHandler);
};

#endif