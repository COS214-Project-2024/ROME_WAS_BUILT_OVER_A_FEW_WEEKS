#include "LowSatisfactionHandler.h"
#include <random>

#include <iostream>

LowSatisfactionHandler::LowSatisfactionHandler(SatisfactionHandler *nextHandler){
    this->nextHandler = nextHandler;
    chanceOfPopulationChange = 45;
    incomeAffectionRate = 0.6;
}

void LowSatisfactionHandler::handlePopulation(int curSatisfaction, CityHall *cityHall){
        // Pass the request down the chain if satisfaction is lower than 80
    // if (curSatisfaction < 40){
    //     if (nextHandler == NULL){
    //         SatisfactionHandler::handlePopulation(curSatisfaction, cityHall);
    //         return;
    //     }
    //     nextHandler->handlePopulation(curSatisfaction, cityHall);
    // }
    
    // Random functions
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random1(1, 100);
    std::uniform_int_distribution<> random2(1, 10);
    std::uniform_int_distribution<> random3(-10, 10);
    std::uniform_int_distribution<> random4(0, 1);

    float changePopulation = random1(gen); // Random number

    std::cout << changePopulation << std::endl;

    // If random number is below chanceOfPopulationChange then population should change
    if (changePopulation <= chanceOfPopulationChange){
        double numNewCitizenMultiplier = random2(gen);
        double numNewCitizens = (cityHall->getNumCitizens() * numNewCitizenMultiplier)/100.f;

        std::cout <<  "==== " << numNewCitizens << std::endl;

        for (float i = 0.5; i < numNewCitizens; i++){
            bool doDeath = random4(gen);

            if (doDeath){
                cityHall->death();
            }else{
                cityHall->emigrate();
            }
        }
    }
}

float LowSatisfactionHandler::handleTax(int curSatisfaction, CityHall *cityHall){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random1(1, 10);

    incomeAffectionRate += random1(gen) * 0.01;

    std::cout << "Income Affection Rate: " << incomeAffectionRate << std::endl;

    return incomeAffectionRate*cityHall->getTaxRateResidential()*cityHall->getNumCitizens();
}
