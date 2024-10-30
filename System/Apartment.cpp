#include <iostream>

#include "Apartment.h"

Apartment::Apartment(int capacity) : ResidentialBuilding(DEFAULT_APARTMENT_CAPACITY) {
    this->cost = DEFAULT_APARTMENT_COST;
}

Apartment::~Apartment() {
    // EMPTY
}

std::string Apartment::getResidentialBuildingType() {
    return "Apartment";
}