#include <iostream>

#include "Shop.h"

Shop::Shop() : CommercialBuilding(DEFAULT_SHOP_RADIUS) {
    this->cost = DEFAULT_SHOP_COST;
    this->woodCost = 30;
    this->steelCost = 30;
    this->concreteCost = 30;
}

Shop::~Shop() {
    // EMPTY
}

std::string Shop::getCommercialBuildingType() {
    return "Shop";
}

std::string Shop::getStructureType(){
    return "Shop";
}
