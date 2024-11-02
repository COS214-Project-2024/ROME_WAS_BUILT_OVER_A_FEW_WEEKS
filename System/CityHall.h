#ifndef CITYHALL_H
#define CITYHALL_H

#include "CityStructures/CityStructure.h"

class SatisfactionHandler;
class PoliticalSystem;
class CityMap;
class Railway;
class Airport;

 
class CityHall: public CityStructure{
    private:
        static CityHall* cityHall; // Singleton
        SatisfactionHandler* chainOfResponsibility;
        PoliticalSystem* politicalSystem;
        Railway* railway;
        Airport* airport;

        int numCitizens;
        int cityCapacity;
        int numResidentialComplexes;
        int numCommercialBuildings;
        int numIndustrialBuildings;
        int popeCoins;
        int wood;
        int steel;
        int concrete;
        int maxWood;
        int maxSteel;
        int maxConcrete;
        static const int MAX_POPE_COINS = 1000000; // 1 million

        float residentialSatisfaction;
        float citySatisfaction;
        
        
        int taxRateResidential; // @Denis, i think we could just use getters for these
        int taxRateCommercial;  // Dont need to store it really
        int taxRateIndustrial;
        double budgetSplit;
        int citizenSatisfactionImpact;



    protected:
        CityHall(); // Singleton

    public:
        static CityHall* getInstance(); // Singleton
        void setPoliticalSystem(PoliticalSystem* politicalSystem);
        void birth();
        void death();
        void emigrate();
        void immigrate();
        int getNumCitizens();
        int getCityCapacity();
        int getNumResidentialBuildings();
        std::string getStructureType();
        int getCost();

        int getCurrSatisfaction();
        float calculateSatisfaction();
        void calculateResidentialSatisfaction(float oldSatisfaction, float newSatisfaction); // Mediator can do this (this is the calculation we were talking about Vansh)
        float getRailwayBonus();
        float getAirportBonus();
        float calculateHomelessnessDeduction();

        void populationChange(int satisfactionLevel); // CHAIN
        float collectTaxes(int satisfactionLevel); // CHAIN

        int getTaxRateResidential();
        int getTaxRateCommercial();
        int getTaxRateIndustrial();
        double getBudgetSplit(); // Higher the percentage the more money goes to the user
        int getCitizenSatisfactionImpact();
        ~CityHall();

        bool placeStructure(int x, int y, CityMap* cityMap);
        void removeStructure();
        void increaseStorageCapacity();

        void increaseNumResidentialComplexes();
        void decreaseNumResidentialComplexes();

        void increaseNumCommercialBuildings();
        void decreaseNumCommercialBuildings();

        void increaseNumIndustrialBuildings();
        void decreaseNumIndustrialBuildings();

        bool addPopeCoins(int coins);
        bool deductPopeCoins(int coins);

        void increaseCapacity(int capacity);
        void decreaseCapacity(int capacity);

        void printCityHallState();
        
};

#endif