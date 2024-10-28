#ifndef CITYHALL_H
#define CITYHALL_H

#include "SatisfactionHandler.h"
//#include "CityMap.h"

class CityHall{
    private:
        static CityHall* cityHall; // Singleton
        //PoliticalSystem* politicalSystem; (CAN'T DO THIS ONE YET)
        SatisfactionHandler* chainOfResponsibility;
        //CityMap* cityMapReference; (CAN'T DO THIS ONE YET)

        int currPopulation;
        int popeCoins;
        int citySatisfaction;
    protected:
        CityHall(); // Singleton
    public:
        static CityHall* getInstance(); // Singleton
        //void setCityMapReference(CityMap* map); (CAN'T DO THIS ONE YET)
        void birth();
        void death();
        void emigrate();
        void immigrate();
        int getCityCapacity();
        int getCurrNumCitizens();
        int getCurrSatisfaction(); // Request to chain of responsibility
        void calculateCitySatisfaction();
        void calculateHousedSatisfaction();
        void calculateHomelessness();
};

#endif