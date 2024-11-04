#include "Plant.h"
#include <iostream>


Plant::Plant(){
    this->radiusOfEffect = DEFAULT_RADIUS_OF_EFFECT;
    cost = 1000; 
    woodCost = 100; 
    steelCost = 100; 
    concreteCost = 100;
}

Plant::~Plant(){
    cityMap = nullptr;
}

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

bool Plant::removeStructure() {
    bool removed = cityMap->removeStructure(x, y);
    if (removed) {
        cityMap->removePlant(this);
        return true;
    }
    else {
        return false;
    }
}

string Plant::getPlantType(){
    return this->plantType;
}

std::string Plant::getStructureType(){
    return "Plant";
}
