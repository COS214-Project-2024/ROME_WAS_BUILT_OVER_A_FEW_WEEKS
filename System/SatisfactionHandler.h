#ifndef SATISFACTIONHANDLER_H
#define SATISFACTIONHANDLER_H

class SatisfactionHandler{
    protected:
        SatisfactionHandler* nextHandler;
        float chanceOfPopulationChange;
        float incomeAffectionRate;
    public:
        void handle(int curSatisfaction);
};

#endif