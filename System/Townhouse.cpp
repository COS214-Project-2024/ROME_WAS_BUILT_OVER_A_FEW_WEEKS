#include <iostream>

#include "Townhouse.h"

Townhouse::Townhouse(int capacity) : ResidentialBuilding(DEFAULT_TOWNHOUSE_CAPACITY) {
    this->cost = DEFAULT_TOWNHOUSE_COST;
}

Townhouse::~Townhouse() {
    // EMPTY
}

std::string Townhouse::getResidentialBuildingType() {
    return "Townhouse";
}