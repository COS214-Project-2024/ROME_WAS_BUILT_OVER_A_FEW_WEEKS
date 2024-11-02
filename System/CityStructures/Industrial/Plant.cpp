#include "Plant.h"

int Plant::getRadiusOfEffect(){
    return this->radiusOfEffect;
}

bool Plant::placeStructure(int x, int y, CityMap* cityMap) {
    bool placed = CityStructure::placeStructure(x, y, cityMap);
    if (placed) {
        cityMap->addPlant(this);
        return true;
    }
    else {
        return false;
    }
}

string Plant::getPlantType(){
    return this->plantType;
}
