#include <iostream>

#include "Mall.h"

Mall::Mall() : CommercialBuilding(DEFAULT_MALL_RADIUS) {
    this->cost = DEFAULT_MALL_COST;
}

Mall::~Mall() {
    // EMPTY
}

std::string Mall::getCommercialBuildingType() {
    return "Mall";
}
