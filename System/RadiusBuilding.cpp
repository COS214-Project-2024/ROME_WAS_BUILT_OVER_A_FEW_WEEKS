#include <iostream>

#include "CityMap.h"
#include "RadiusBuilding.h"


RadiusBuilding::RadiusBuilding(int radiusOfEffect) : radiusOfEffect(radiusOfEffect) {
    if (radiusOfEffect < 0) {
        std::cout << "Radius of effect cannot be negative" << std::endl;
        radiusOfEffect = 0;
    }
}

RadiusBuilding::~RadiusBuilding() {
    cityMap = nullptr;
}


int RadiusBuilding::getRadiusOfEffect() {
    return radiusOfEffect;
}

void RadiusBuilding::removeStructure() {
    cityMap->removeStructure(x, y);
}


