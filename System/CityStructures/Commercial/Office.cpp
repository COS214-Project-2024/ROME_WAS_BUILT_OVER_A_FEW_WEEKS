#include <iostream> 

#include "Office.h"

sf::Texture* Office::texture = new sf::Texture();

Office::Office() : CommercialBuilding(DEFAULT_OFFICE_RADIUS) {
    this->cost = DEFAULT_OFFICE_COST;

    static bool isLoaded = false;

    if (!isLoaded){
        texture->loadFromFile("../../../images/spr_Office.png");
        isLoaded = true;
    }

    sprite->setTexture(*texture);
}

Office::~Office() {
    // EMPTY
}

std::string Office::getCommercialBuildingType() {
    return "Office";
}

