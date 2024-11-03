#include <iostream> 

#include "Office.h"

Office::Office() : CommercialBuilding(DEFAULT_OFFICE_RADIUS) {
    this->cost = DEFAULT_OFFICE_COST;
    this->woodCost = 300;
    this->steelCost = 300;
    this->concreteCost = 300;
}

Office::~Office() {
    // EMPTY
}

std::string Office::getCommercialBuildingType() {
    return "Office";
}

std::string Office::getStructureType(){
    return "Office";
}
