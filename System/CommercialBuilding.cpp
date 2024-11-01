#include <iostream>

#include "CityMap.h"
#include "CommercialBuilding.h"


CommercialBuilding::CommercialBuilding(int radiusOfEffect) : radiusOfEffect(radiusOfEffect) {

}

CommercialBuilding::~CommercialBuilding() {
    // EMPTY
}

std::string CommercialBuilding::getStructureType() {
    return "Commercial";
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

void CommercialBuilding::newResidentialComplexWasAdded(ResidentialComplex* complex) {
    // INFO of the commercial building
    int radiusOfEffect = this->getRadiusOfEffect();
    int x_of_Commercial = this->getX();
    int y_of_Commercial = this->getY();

    // INFO of the residential complex
    int x_of_Residential = complex->getX();
    int y_of_Residential = complex->getY();

    // determine if the residential complex is within the radius of effect
    if (x_of_Residential >= x_of_Commercial - radiusOfEffect && x_of_Residential <= x_of_Commercial + radiusOfEffect && y_of_Residential >= y_of_Commercial - radiusOfEffect && y_of_Residential <= y_of_Commercial + radiusOfEffect) {
        complex->newCommercialBuildingWasAdded(); // func name doesnt make sense but its just a setter
    }
}
