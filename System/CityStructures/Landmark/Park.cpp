#include <iostream>

#include "Park.h"

sf::Texture* Park::texture = new sf::Texture();

Park::Park() : Landmark(DEFAULT_PARK_RADIUS) {
    this->cost = DEFAULT_PARK_COST;

    static bool isLoaded = false;

    if (!isLoaded){
        texture->loadFromFile("../../../images/spr_Park.png");
        isLoaded = true;
    }

    sprite->setTexture(*texture);
}

Park::~Park() {
    // EMPTY
}

std::string Park::getLandmarkType() {
    return "Park";
}

