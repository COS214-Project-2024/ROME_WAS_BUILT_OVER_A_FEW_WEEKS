#include <iostream>

#include "Pantheon.h"

Pantheon::Pantheon() : Landmark(DEFAULT_PANTHEON_RADIUS) {
    this->cost = DEFAULT_PANTHEON_COST;
    woodCost = 1000;
    steelCost = 1000;
    concreteCost = 1000;
}

Pantheon::~Pantheon() {
    // EMPTY
}

std::string Pantheon::getLandmarkType() {
    return "Pantheon";
}