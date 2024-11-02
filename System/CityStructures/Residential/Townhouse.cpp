#include <iostream>

#include "Townhouse.h"

#include "../../GameSimulation.h"

sf::Texture* Townhouse::texture = new sf::Texture();

Townhouse::Townhouse() : ResidentialBuilding(DEFAULT_TOWNHOUSE_CAPACITY) {
    this->cost = DEFAULT_TOWNHOUSE_COST;

    static bool isLoaded = false;

    if (!isLoaded){
        texture->loadFromFile("../../../images/spr_TownHouse.png");
        isLoaded = true;
    }

    sprite->setTexture(*texture);
}

Townhouse::~Townhouse() {
    // EMPTY
}

std::string Townhouse::getResidentialBuildingType() {
    return "Townhouse";
}