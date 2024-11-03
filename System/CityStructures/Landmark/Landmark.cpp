#include <iostream>

#include "../../CityMap.h"
#include "Landmark.h"

Landmark::Landmark(int radiusOfEffect) : radiusOfEffect(radiusOfEffect) {

}

Landmark::~Landmark() {
    this->cityMap = nullptr;
}

int Landmark::getRadiusOfEffect() {
    return this->radiusOfEffect;
}

bool Landmark::placeStructure(int x, int y, CityMap* cityMap) {
    bool placed = CityStructure::placeStructure(x, y, cityMap);
    if (placed) {
        cityMap->addLandmark(this);
        return true;
    }else{
        return false;
    }
}

void Landmark::removeStructure() {
    CityStructure::removeStructure();
    cityMap->removeLandmark(this);
}

void Landmark::newResidentialComplexWasAdded(ResidentialComplex* complex) {
    // INFO of the landmark
    int radiusOfEffect = this->getRadiusOfEffect();
    int x_of_Landmark = this->getX();
    int y_of_Landmark = this->getY();

    // INFO of the residential complex
    int x_of_Residential = complex->getX();
    int y_of_Residential = complex->getY();

    // determine if the residential complex is within the radius of effect
    if (x_of_Residential >= x_of_Landmark - radiusOfEffect && x_of_Residential <= x_of_Landmark + radiusOfEffect && y_of_Residential >= y_of_Landmark - radiusOfEffect && y_of_Residential <= y_of_Landmark + radiusOfEffect) {
        complex->newLandmarkWasAdded(); // func name doesnt make sense but its just a setter
    }
}

std::string Landmark::getStructureType() {
    return "Landmark";
}



