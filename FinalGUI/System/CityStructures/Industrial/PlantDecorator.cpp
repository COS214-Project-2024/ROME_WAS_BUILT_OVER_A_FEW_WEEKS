#include "PlantDecorator.h"
#include <iostream>

PlantDecorator::PlantDecorator() {
    plant = nullptr;
}

PlantDecorator::PlantDecorator(Plant* plant) : plant(plant) {
    this->plant = plant;
}

PlantDecorator::~PlantDecorator() {
    plant = nullptr;
}

int PlantDecorator::getRadiusOfEffect() {
    return plant->getRadiusOfEffect();
}

std::string PlantDecorator::getPlantType() {
    return plant->getPlantType();
}