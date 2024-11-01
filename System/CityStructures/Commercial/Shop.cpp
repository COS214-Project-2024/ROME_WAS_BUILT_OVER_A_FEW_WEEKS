#include <iostream>

#include "Shop.h"

Shop::Shop() : CommercialBuilding(DEFAULT_SHOP_RADIUS) {
    this->cost = DEFAULT_SHOP_COST;
}

Shop::~Shop() {
    // EMPTY
}

std::string Shop::getCommercialBuildingType() {
    return "Shop";
}