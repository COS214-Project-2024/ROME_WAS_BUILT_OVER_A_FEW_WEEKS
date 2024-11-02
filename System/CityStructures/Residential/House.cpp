#include <iostream>

#include "House.h"

#include "../../GameSimulation.h"

sf::Texture* House::texture = new sf::Texture();

House::House() : ResidentialBuilding(DEFAULT_HOUSE_CAPACITY) {
    this->cost = DEFAULT_HOUSE_COST;

    static bool isLoaded = false;

    if (!isLoaded){
        texture->loadFromFile("../../../images/spr_House.png");
        isLoaded = true;
    }

    sprite->setTexture(*texture);
}

House::~House() {
    // EMPTY
}

std::string House::getResidentialBuildingType() {
    return "House";
}