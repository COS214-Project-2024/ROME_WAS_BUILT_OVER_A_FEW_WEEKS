#include <iostream>

#include "../../CityMap.h"
#include "IndustrialBuilding.h"


IndustrialBuilding::IndustrialBuilding()  {

}

IndustrialBuilding::~IndustrialBuilding() {
    cityMap = nullptr;
}

std::string IndustrialBuilding::getStructureType() {
    return "Industrial";
}

void IndustrialBuilding::placeStructure(int x, int y, CityMap* cityMap) {
    CityStructure::placeStructure(x, y, cityMap);
    cityMap->addIndustrialBuilding(this);
}




