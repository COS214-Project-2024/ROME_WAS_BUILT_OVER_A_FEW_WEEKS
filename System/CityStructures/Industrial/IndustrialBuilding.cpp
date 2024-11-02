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

bool IndustrialBuilding::placeStructure(int x, int y, CityMap* cityMap) {
    bool placed = CityStructure::placeStructure(x, y, cityMap);
    if (placed) {
        cityMap->addIndustrialBuilding(this);
        return true;
    }else{
        return false;
    }
}




