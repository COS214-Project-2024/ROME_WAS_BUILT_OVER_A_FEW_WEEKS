#include <iostream>

#include "Pantheon.h"

Pantheon::Pantheon() : Landmark(DEFAULT_PANTHEON_RADIUS) {
    this->cost = DEFAULT_PANTHEON_COST;
}

Pantheon::~Pantheon() {
    // EMPTY
}

std::string Pantheon::getLandmarkType() {
    return "Pantheon";
}