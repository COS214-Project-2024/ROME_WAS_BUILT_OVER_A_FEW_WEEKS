#include <iostream>

#include "CityMap.h"
#include "Landmark.h"

Landmark::Landmark(int radiusOfEffect) : radiusOfEffect(radiusOfEffect) {

}

Landmark::~Landmark() {
    this->cityMap = nullptr;
}

int Landmark::getRadiusOfEffect() {
    return this->radiusOfEffect;
}

void Landmark::placeStructure(int x, int y, CityMap* cityMap) {
    CityStructure::placeStructure(x, y, cityMap);
    cityMap->addLandmark(this);
}



