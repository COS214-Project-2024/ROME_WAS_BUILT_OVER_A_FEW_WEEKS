#include <iostream>

#include "CityMap.h"
#include "Landmark.h"

Landmark::Landmark(int radiusOfEffect) : RadiusBuilding(radiusOfEffect) {

}

void Landmark::placeStructure(int x, int y, CityMap* cityMap) {
    CityStructure::placeStructure(x, y, cityMap);
    cityMap->addLandmark(this);
}

Landmark::~Landmark() {
    this->cityMap = nullptr;
}

