#include <iostream>

#include "Estate.h"

Estate::Estate() : ResidentialBuilding(DEFAULT_ESTATE_CAPACITY) {
    this->cost = DEFAULT_ESTATE_COST;
}

Estate::~Estate() {
    // EMPTY
}

std::string Estate::getResidentialBuildingType() {
    return "Estate";
}

