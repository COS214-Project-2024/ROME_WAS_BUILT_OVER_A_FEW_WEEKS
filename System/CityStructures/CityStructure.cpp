#include <iostream>

#include "CityStructure.h"
#include "../CityMap.h"


CityStructure::CityStructure() {
    x = -1;
    y = -1;
    cityMap = nullptr;
}

bool CityStructure::placeStructure(int x, int y, CityMap* cityMap) {
    std::cout << "Placing the structure" << std::endl;
    bool placed = cityMap->addStructure(x, y, this);
    if (placed) {
        this->x = x;
        this->y = y;
        this->cityMap = cityMap;
        return true;
    }
    else {
        std::cout << "Could not place the structure" << std::endl;
        return false;
    }
    

}

bool CityStructure::removeStructure() {
    bool removed = cityMap->removeStructure(x, y);
    if (removed) {
        x = -1;
        y = -1;
        cityMap = nullptr;
        return true;
    }
    else {
        return false;
    }
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
    //std::cout << "Getting cost" << cost << std::endl;
    return cost;
}

int CityStructure::getWoodCost() {
    return woodCost;
}

int CityStructure::getSteelCost() {
    return steelCost;
}

int CityStructure::getConcreteCost() {
    return concreteCost;
}