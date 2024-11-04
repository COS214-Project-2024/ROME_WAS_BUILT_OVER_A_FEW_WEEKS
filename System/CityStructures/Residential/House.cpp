#include <iostream>

#include "House.h"

House::House() : ResidentialBuilding(DEFAULT_HOUSE_CAPACITY) {
    this->cost = DEFAULT_HOUSE_COST;
    this->woodCost = 50;
    this->steelCost = 50;
    this->concreteCost = 50;
}

House::~House() {
    // EMPTY
}

std::string House::getStructureType(){
    return "House";
}
