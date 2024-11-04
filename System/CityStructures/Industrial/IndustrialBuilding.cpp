#include <iostream>

#include "../../CityMap.h"
#include "IndustrialBuilding.h"


IndustrialBuilding::IndustrialBuilding()  {

}

IndustrialBuilding::~IndustrialBuilding() {
    delete cityMap;
    cityMap = nullptr;
}

std::string IndustrialBuilding::getStructureType() {
    return "Industrial";
}

bool IndustrialBuilding::placeStructure(int x, int y, CityMap* cityMap) {
    bool placed = CityStructure::placeStructure(x, y, cityMap);
    if (placed) {
        cityMap->addBuilding(this);
        return true;
    }
    else {
        return false;
    }
}

bool IndustrialBuilding::removeStructure() {
    bool removed = cityMap->removeStructure(x, y);
    if (removed) {
        cityMap->removeIndustrialBuilding(this);
        return true;
    }
    else {
        return false;
    }
}



