#include <iostream>

#include "House.h"

House::House() : ResidentialBuilding(DEFAULT_HOUSE_CAPACITY) {
    this->cost = DEFAULT_HOUSE_COST;
}

House::~House() {
    // EMPTY
}

std::string House::getResidentialBuildingType() {
    return "House";
}