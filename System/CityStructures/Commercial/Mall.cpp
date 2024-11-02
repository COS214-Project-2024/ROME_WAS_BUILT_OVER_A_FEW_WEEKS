#include <iostream>

#include "Mall.h"
#include "../../GameSimulation.h"

Mall::Mall() : CommercialBuilding(DEFAULT_MALL_RADIUS) {
    this->cost = DEFAULT_MALL_COST;
}

Mall::~Mall() {
    // EMPTY
}

std::string Mall::getCommercialBuildingType() {
    return "Mall";
}
