#include <iostream>

#include "Steel.h"

Steel::Steel() {
    this->productionTimeInMinutes = 10;
}

Steel::~Steel() {
    std::cout << "Steel destroyed" << std::endl;
}

int Steel::getProductionTimeInMinutes() {
    return this->productionTimeInMinutes;
}

std::string Steel::getMaterialName() {
    return "Steel";
}