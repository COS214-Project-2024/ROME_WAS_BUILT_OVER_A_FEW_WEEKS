#include <iostream>

#include "Mall.h"
#include "../../GameSimulation.h"

Mall::Mall() : CommercialBuilding(DEFAULT_MALL_RADIUS) {
    this->cost = DEFAULT_MALL_COST;
    this->woodCost = 350;
    this->steelCost = 350;
    this->concreteCost = 350;
}

Mall::~Mall() {
    // EMPTY
}

std::string Mall::getCommercialBuildingType() {
    return "Mall";
}
