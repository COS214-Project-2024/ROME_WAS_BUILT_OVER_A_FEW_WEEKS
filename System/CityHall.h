#ifndef CITYHALL_H
#define CITYHALL_H

#include "SatisfactionHandler.h"
#include "PoliticalSystem.h"
#include "BoosterStructures.h"
#include "Railway.h"
#include "Airport.h"
 
class CityHall{
    private:
        static CityHall* cityHall; // Singleton
        SatisfactionHandler* chainOfResponsibility;
        PoliticalSystem* politicalSystem;
        Railway* railway;
        Airport* airport;

        int numCitizens;
        int popeCoins;
        float citySatisfaction;
        int cityCapacity;
        int numResidentialBuildings;
        float residentialSatisfaction;

        int taxRateResidential;
        int taxRateCommercial;
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

        int getCurrSatisfaction();
        float calculateSatisfaction();
        void calculateResidentialSatisfaction(float oldSatisfaction, float newSatisfaction); // Mediator can do this (this is the calculation we were talking about Vansh)
        float getRailwayBonus();
        float getAirportBonus();
        float calculateHomelessnessDeduction();

        void populationChange(int satisfactionLevel);
        float collectTaxes(int satisfactionLevel);

        int getTaxRateResidential();
        int getTaxRateCommercial();
        int getTaxRateIndustrial();
        double getBudgetSplit(); // Higher the percentage the more money goes to the user
        int getCitizenSatisfactionImpact();
        ~CityHall();
};

#endif