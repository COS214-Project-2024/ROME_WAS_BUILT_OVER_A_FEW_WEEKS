#include "HighSatisfactionHandler.h"
#include <random>


HighSatisfactionHandler::HighSatisfactionHandler(SatisfactionHandler *nextHandler){
    this->nextHandler = nextHandler;
    chanceOfPopulationChange = 48;
    incomeAffectionRate = 1;
}


void HighSatisfactionHandler::handlePopulation(int curSatisfaction, CityHall* cityHall){
    // Pass the request down the chain if satisfaction is lower than 80
    if (curSatisfaction < 80){
        if (nextHandler == NULL){
            SatisfactionHandler::handlePopulation(curSatisfaction, cityHall);
            return;
        }
        nextHandler->handlePopulation(curSatisfaction, cityHall);
    }
    
    // Random functions
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random1(1, 100);
    std::uniform_int_distribution<> random2(1, 10);
    std::uniform_int_distribution<> random3(-10, 10);
    std::uniform_int_distribution<> random4(0, 1);

    float changePopulation = random1(gen); // Random number

    // If random number is below chanceOfPopulationChange then population should change
    if (changePopulation <= chanceOfPopulationChange){
        int numNewCitizenMultiplier = random2(gen);
        int numNewCitizens = (cityHall->getNumCitizens() * numNewCitizenMultiplier)/100.f;

        for (float i = 0.5; i < numNewCitizens; i++){
            bool doBirth = random4(gen);

            if (doBirth){
                cityHall->birth();
            }else{
                cityHall->immigrate();
            }
        }
    }
}


float HighSatisfactionHandler::handleTax(int curSatisfaction, CityHall *cityHall){
    if (curSatisfaction < 80){
        if (nextHandler == NULL){
            return SatisfactionHandler::handleTax(curSatisfaction, cityHall);
        }
        return nextHandler->handleTax(curSatisfaction, cityHall);
    }



    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random1(-10, 10);

    incomeAffectionRate += random1(gen) * 0.01;
    return incomeAffectionRate*cityHall->getTaxRateResidential()*cityHall->getNumCitizens();
}