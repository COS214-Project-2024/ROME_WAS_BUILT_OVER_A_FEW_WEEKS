#include "Factory.h"
#include <iostream>

Factory::Factory(){
    this->qunatity = 0;
    cost = 0; 
    woodCost = 0; 
    steelCost = 0; 
    concreteCost = 0;
}

Factory::~Factory(){
    // EMPTY
}

string Factory::getFactoryType(){
    return this->factoryType;
}

bool Factory::placeStructure(int x, int y, CityMap *cityMap){
    bool placed = CityStructure::placeStructure(x, y, cityMap);
    if (placed) {
        cityMap->addFactory(this);
        return true;
    }
    else {
        return false;
    }
}

bool Factory::removeStructure(){
    bool removed = cityMap->removeStructure(x, y);
    if (removed) {
        cityMap->removeFactory(this);
        return true;
    }
    else {
        return false;
    }
}

int Factory::getQuantity(){
    return this->qunatity;
}

int Factory::generate(){
    return 0;
}