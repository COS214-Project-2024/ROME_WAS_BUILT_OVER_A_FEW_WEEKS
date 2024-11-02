#include <iostream>

#include "Park.h"


Park::Park() : Landmark(DEFAULT_PARK_RADIUS) {
    this->cost = DEFAULT_PARK_COST;
}

Park::~Park() {
    // EMPTY
}

std::string Park::getLandmarkType() {
    return "Park";
}

