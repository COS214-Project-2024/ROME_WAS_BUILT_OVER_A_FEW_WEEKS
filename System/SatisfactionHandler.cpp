#include "SatisfactionHandler.h"

float SatisfactionHandler::handleTax(int curSatisfaction, CityHall* cityHall){
    // Countdown maybe of when player loses?
    return 0;
}

void SatisfactionHandler::handlePopulation(int curSatisfaction, CityHall *cityHall){
    // Countdown maybe of when player loses?
    return;
}

void SatisfactionHandler::addHandler(SatisfactionHandler *nextHandler){
    this->nextHandler = nextHandler;
}