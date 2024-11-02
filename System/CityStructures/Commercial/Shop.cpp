#include <iostream>

#include "Shop.h"
#include "../../GameSimulation.h"

sf::Texture* Shop::texture = new sf::Texture();

Shop::Shop() : CommercialBuilding(DEFAULT_SHOP_RADIUS) {
    this->cost = DEFAULT_SHOP_COST;

    static bool isLoaded = false;

    if (!isLoaded){
        texture->loadFromFile("../../../images/spr_Shop.png");
        isLoaded = true;
    }

    sprite->setTexture(*texture);
}

Shop::~Shop() {
    // EMPTY
}

std::string Shop::getCommercialBuildingType() {
    return "Shop";
}