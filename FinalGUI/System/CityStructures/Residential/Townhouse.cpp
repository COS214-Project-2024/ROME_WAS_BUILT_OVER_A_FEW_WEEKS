#include <iostream>

#include "Townhouse.h"

Townhouse::Townhouse() : ResidentialBuilding(DEFAULT_TOWNHOUSE_CAPACITY) {
    this->cost = DEFAULT_TOWNHOUSE_COST;
    this->woodCost = 75;
    this->steelCost = 75;
    this->concreteCost = 75;
}

Townhouse::~Townhouse() {
    // EMPTY
}

std::string Townhouse::getStructureType(){
    return "Townhouse";
}
