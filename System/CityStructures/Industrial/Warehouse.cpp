#include "Warehouse.h"

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