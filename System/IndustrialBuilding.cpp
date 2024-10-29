#include <iostream>

#include "CityMap.h"
#include "IndustrialBuilding.h"


IndustrialBuilding::IndustrialBuilding()  {

}

void IndustrialBuilding::placeStructure(int x, int y, CityMap* cityMap) {
    CityStructure::placeStructure(x, y, cityMap);
    cityMap->addBuilding(this);
}


IndustrialBuilding::~IndustrialBuilding() {
    cityMap = nullptr;
}

