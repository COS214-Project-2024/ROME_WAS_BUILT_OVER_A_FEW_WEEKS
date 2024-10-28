#include <iostream>

#include "CityMap.h"
#include "IndustrialBuilding.h"


IndustrialBuilding::IndustrialBuilding(int radiusOfEffect) : RadiusBuilding(radiusOfEffect) {

}

void IndustrialBuilding::placeStructure(int x, int y, CityMap* cityMap) {
    CityStructure::placeStructure(x, y, cityMap);
    cityMap->addIndustrialBuilding(this);
}


IndustrialBuilding::~IndustrialBuilding() {
    cityMap = nullptr;
}

