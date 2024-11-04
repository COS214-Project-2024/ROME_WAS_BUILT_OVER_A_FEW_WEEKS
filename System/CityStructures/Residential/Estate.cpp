#include <iostream>

#include "Estate.h"

Estate::Estate() : ResidentialBuilding(DEFAULT_ESTATE_CAPACITY) {
    this->cost = DEFAULT_ESTATE_COST;
    this->woodCost = 500;
    this->steelCost = 500;
    this->concreteCost = 500;
}

Estate::~Estate() {
    // EMPTY
}

std::string Estate::getStructureType(){
    return getResidentialBuildingType();
}

std::string Estate::getResidentialBuildingType() {
    return "Estate";
}

