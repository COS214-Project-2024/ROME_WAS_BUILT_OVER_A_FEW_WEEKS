#include <iostream>

#include "Concrete.h"

Concrete::Concrete() {
    this->productionTimeInMinutes = 15;
}

Concrete::~Concrete() {
    std::cout << "Concrete destroyed" << std::endl;
}

int Concrete::getProductionTimeInMinutes() {
    return this->productionTimeInMinutes;
}

std::string Concrete::getMaterialName() {
    return "Concrete";
}