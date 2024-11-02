#include <iostream>

#include "Estate.h"

#include "../../GameSimulation.h"

sf::Texture* Estate::texture = new sf::Texture();

Estate::Estate() : ResidentialBuilding(DEFAULT_ESTATE_CAPACITY) {
    this->cost = DEFAULT_ESTATE_COST;

    static bool isLoaded = false;

    if (!isLoaded){
        texture->loadFromFile("../../../images/spr_Estate.png");
        isLoaded = true;
    }

    sprite->setTexture(*texture);
}


Estate::~Estate() {
    // EMPTY
}

std::string Estate::getResidentialBuildingType() {
    return "Estate";
}

