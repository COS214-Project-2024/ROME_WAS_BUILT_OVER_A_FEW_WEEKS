#include <iostream>

#include "Colosseum.h"

sf::Texture* Colosseum::texture = new sf::Texture();

Colosseum::Colosseum() : Landmark(DEFAULT_COLOSSEUM_RADIUS) {
    this->cost = DEFAULT_COLOSSEUM_COST;

    static bool isLoaded = false;

    if (!isLoaded){
        texture->loadFromFile("../../../images/spr_Monument.png");
        isLoaded = true;
    }

    sprite->setTexture(*texture);
}

Colosseum::~Colosseum() {
    // EMPTY
}

std::string Colosseum::getLandmarkType() {
    return "Colosseum";
}