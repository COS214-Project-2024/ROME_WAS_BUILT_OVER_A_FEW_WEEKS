#include <iostream>

#include "CityMap.h"
#include "CommercialBuilding.h"


CommercialBuilding::CommercialBuilding(int radiusOfEffect) : RadiusBuilding(radiusOfEffect) {

}

void CommercialBuilding::placeStructure(int x, int y, CityMap* cityMap) {
    CityStructure::placeStructure(x, y, cityMap);
    cityMap->addCommercialBuilding(this);
}

CommercialBuilding::~CommercialBuilding() {
    // EMPTY
}