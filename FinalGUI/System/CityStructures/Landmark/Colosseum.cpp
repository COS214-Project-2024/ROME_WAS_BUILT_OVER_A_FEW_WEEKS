#include <iostream>

#include "Colosseum.h"

Colosseum::Colosseum() : Landmark(DEFAULT_COLOSSEUM_RADIUS) {
    this->cost = DEFAULT_COLOSSEUM_COST;
    woodCost = 1000;
    steelCost = 1000;
    concreteCost = 1000;
}

Colosseum::~Colosseum() {
    // EMPTY
}

std::string Colosseum::getStructureType() {
    return "Colosseum";
}