#include "Warehouse.h"

Warehouse::~Warehouse(){
    delete cityMap;
    cityMap = nullptr;
}

bool Warehouse::placeStructure(int x, int y, CityMap *cityMap){
    bool placed = CityStructure::placeStructure(x, y, cityMap);
    if (placed) {
        cityMap->addWarehouse(this);
        return true;
    }
    else {
        return false;
    }
}

bool Warehouse::removeStructure(){
    bool removed = cityMap->removeStructure(x, y);
    if (removed) {
        cityMap->removeWarehouse(this);
        return true;
    }
    else {
        return false;
    }
}