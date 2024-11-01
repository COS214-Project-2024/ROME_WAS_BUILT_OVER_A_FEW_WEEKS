#include <iostream>

#include "CityStructure.h"
#include "CityMap.h"


CityStructure::CityStructure() {
    x = -1;
    y = -1;
    cityMap = nullptr;
}

void CityStructure::placeStructure(int x, int y, CityMap* cityMap) {
    std::cout << "Placing the structure" << std::endl;
    bool placed = cityMap->addStructure(x, y, this);
    if (placed) {
        this->x = x;
        this->y = y;
        this->cityMap = cityMap;
    }
    else {
        std::cout << "Could not place the structure" << std::endl;
    }
    

}

void CityStructure::removeStructure() {
    cityMap->removeStructure(x, y);
    this->x = -1;
    this->y = -1;
    this->cityMap = nullptr;
}

CityStructure::~CityStructure() {
    delete cityMap;
    cityMap = nullptr;
}

int CityStructure::getX() {
    return x;
}

int CityStructure::getY() {
    return y;
}

int CityStructure::getCost() {
    return cost;
}