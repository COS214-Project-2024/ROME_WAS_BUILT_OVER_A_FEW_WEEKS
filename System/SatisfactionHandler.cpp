#include "SatisfactionHandler.h"

void SatisfactionHandler::handle(int curSatisfaction, CityHall* cityHall){
    // This is the default case that will run if all satisfaction handlers skipped the request
    // Start a countdown perhaps of when the player will lose.
    // Or make them lose immediately. We'll still figure this out.
    return; // Just adding this here in case the function gives shit for not having any code
}

void SatisfactionHandler::addHandler(SatisfactionHandler *nextHandler){
    this->nextHandler = nextHandler;
}
