#include <iostream>

#include "Wood.h"

Wood::Wood() {
    this->productionTimeInMinutes = 5;
}

Wood::~Wood() {
    std::cout << "Wood destroyed" << std::endl;
}

int Wood::getProductionTimeInMinutes() {
    return this->productionTimeInMinutes;
}

std::string Wood::getMaterialName() {
    return "Wood";
}

