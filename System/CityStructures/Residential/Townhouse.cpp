#include <iostream>

#include "Townhouse.h"

#include "../../GameSimulation.h"

Townhouse::Townhouse() : ResidentialBuilding(DEFAULT_TOWNHOUSE_CAPACITY) {
    this->cost = DEFAULT_TOWNHOUSE_COST;
}

Townhouse::~Townhouse() {
    // EMPTY
}

std::string Townhouse::getResidentialBuildingType() {
    return "Townhouse";
}