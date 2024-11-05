#include "Factory.h"
#include <iostream>

string Factory::getFactoryType(){
    return this->factoryType;
}

bool Factory::placeStructure(int x, int y, CityMap *cityMap)
{
    bool placed = CityStructure::placeStructure(x, y, cityMap);
    if (placed) {
        cityMap->addFactory(this);
        return true;
    }
    else {
        return false;
    }
}

int Factory::generate(){
    return 0;
}

std::string Factory::getStructureType(){
    return "Factory";
}
