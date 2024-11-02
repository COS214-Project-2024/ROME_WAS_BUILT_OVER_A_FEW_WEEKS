#include "Plant.h"

int Plant::getRadiusOfEffect(){
    return this->radiusOfEffect;
}

void Plant::placeStructure(int x, int y, CityMap* cityMap) {
    CityStructure::placeStructure(x, y, cityMap);
    cityMap->addPlant(this);
}

string Plant::getPlantType(){
    return this->plantType;
}
