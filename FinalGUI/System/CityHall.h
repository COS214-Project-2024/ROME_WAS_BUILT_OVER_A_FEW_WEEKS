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
        int numFactories;
        int popeCoins;
        int wood;
        int steel;
        int concrete;
        int maxWood;
        int maxSteel;
        int maxConcrete;
        static const int MAX_POPE_COINS = 1000; // 1 million

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
        int getPopeCoins();
        int getWood();
        int getSteel();
        int getConcrete();
        int getMaxWood();
        int getMaxSteel();
        int getMaxConcrete();

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
        double getBudgetSplit(float taxNum); // Higher the percentage the more money goes to the user
        float getCitizenSatisfactionImpact(float tempSatisfaction);
        ~CityHall();

        bool placeStructure(int x, int y, CityMap* cityMap);
        bool removeStructure();
        void increaseStorageCapacity();

        void increaseNumResidentialComplexes();
        void decreaseNumResidentialComplexes();

        void increaseNumCommercialBuildings();
        void decreaseNumCommercialBuildings();

        void increaseNumIndustrialBuildings();
        void decreaseNumIndustrialBuildings();

        void increaseNumFactories();
        void decreaseNumFactories();
        int getNumFactories();
        void generateWood(int generatedAmount);
        void generateSteel(int generatedAmount);
        void generateConcrete(int generatedAmount);

        bool addPopeCoins(int coins);
        bool deductPopeCoins(int coins);

        bool addWood(int wood);
        bool deductWood(int wood);
        bool addSteel(int steel);
        bool deductSteel(int steel);
        bool addConcrete(int concrete);
        bool deductConcrete(int concrete);
        

        void increaseCapacity(int capacity);
        void decreaseCapacity(int capacity);

        void printCityHallState();
        
};

#endif