#include "Apartment.h"

sf::Texture* Apartment::texture = new sf::Texture();

Apartment::Apartment() : ResidentialBuilding(DEFAULT_APARTMENT_CAPACITY) {
    this->cost = DEFAULT_APARTMENT_COST;

    static bool isLoaded = false;

    if (!isLoaded){
        texture->loadFromFile("../../../images/spr_Apartment.png");
        isLoaded = true;
    }

    sprite->setTexture(*texture);
}

Apartment::~Apartment() {
    // EMPTY
}

std::string Apartment::getResidentialBuildingType() {
    return "Apartment";
}