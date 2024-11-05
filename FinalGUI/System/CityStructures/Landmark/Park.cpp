#include <iostream>

#include "Park.h"

Park::Park() : Landmark(DEFAULT_PARK_RADIUS) {
    this->cost = DEFAULT_PARK_COST;
    woodCost = 1000;
    steelCost = 1000;
    concreteCost = 1000;
}

Park::~Park() {
    // EMPTY
}

std::string Park::getStructureType() {
    return "Park";
}

