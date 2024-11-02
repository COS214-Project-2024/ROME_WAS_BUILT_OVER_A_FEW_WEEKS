#include <iostream>

#include "Colosseum.h"

Colosseum::Colosseum() : Landmark(DEFAULT_COLOSSEUM_RADIUS) {
    this->cost = DEFAULT_COLOSSEUM_COST;
}

Colosseum::~Colosseum() {
    // EMPTY
}

std::string Colosseum::getLandmarkType() {
    return "Colosseum";
}