#include <iostream>

#include "Estate.h"

Estate::Estate(int capacity) : ResidentialBuilding(DEFAULT_ESTATE_CAPACITY) {
    this->cost = DEFAULT_ESTATE_COST;
}

Estate::~Estate() {
    // EMPTY
}

std::string Estate::getResidentialBuildingType() {
    return "Estate";
}

