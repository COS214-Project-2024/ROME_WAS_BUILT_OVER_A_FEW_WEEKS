#include <iostream>

#include "CityMap.h"
#include "CommercialBuilding.h"


CommercialBuilding::CommercialBuilding(int radiusOfEffect) : radiusOfEffect(radiusOfEffect) {

}

CommercialBuilding::~CommercialBuilding() {
    // EMPTY
}

int CommercialBuilding::getRadiusOfEffect() {
    return this->radiusOfEffect;
}

void CommercialBuilding::placeStructure(int x, int y, CityMap* cityMap) {
    CityStructure::placeStructure(x, y, cityMap);
    cityMap->addCommercialBuilding(this);
}

void CommercialBuilding::removeStructure() {
    CityStructure::removeStructure();
    cityMap->removeCommercialBuilding(this);
}
