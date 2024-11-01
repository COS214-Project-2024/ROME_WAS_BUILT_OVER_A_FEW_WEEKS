#include <iostream> 

#include "Office.h"

Office::Office() : CommercialBuilding(DEFAULT_OFFICE_RADIUS) {
    this->cost = DEFAULT_OFFICE_COST;
}

Office::~Office() {
    // EMPTY
}

std::string Office::getCommercialBuildingType() {
    return "Office";
}
