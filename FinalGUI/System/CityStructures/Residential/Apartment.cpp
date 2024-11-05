#include "Apartment.h"
#include "Apartment.h"

Apartment::Apartment() : ResidentialBuilding(DEFAULT_APARTMENT_CAPACITY) {
    this->cost = DEFAULT_APARTMENT_COST;
    this->woodCost = 100;
    this->steelCost = 100;
    this->concreteCost = 100;
}

Apartment::~Apartment() {
    // EMPTY
}

std::string Apartment::getStructureType(){
    return "Apartment";
}

