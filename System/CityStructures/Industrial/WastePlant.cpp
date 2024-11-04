#include "WastePlant.h"
#include "../Residential/ResidentialComplex.h"

WastePlant::WastePlant(Plant* plant) : PlantDecorator(plant) {
    this->plant = plant;
}

WastePlant::~WastePlant(){
    delete plant;
    plant = nullptr;
    delete cityMap;
    cityMap = nullptr;
}

bool WastePlant::placeStructure(int x, int y, CityMap* cityMap) {
    bool placed = CityStructure::placeStructure(x, y, cityMap);
    if (placed) {
        cityMap->addPlant(this);
        return true;
    }
    else {
        return false;
    }
}

bool WastePlant::removeStructure() {
    bool removed = cityMap->removeStructure(x, y);
    if (removed) {
        cityMap->removePlant(this);
        return true;
    }
    else {
        return false;
    }
}

void WastePlant::newResidentialComplexWasAdded(ResidentialComplex* complex) {
    // INFO of the commercial building
    int radiusOfEffect = this->getRadiusOfEffect();
    int x_of_Commercial = this->getX();
    int y_of_Commercial = this->getY();

    // INFO of the residential complex
    int x_of_Residential = complex->getX();
    int y_of_Residential = complex->getY();

    // determine if the residential complex is within the radius of effect
    if (x_of_Residential >= x_of_Commercial - radiusOfEffect && x_of_Residential <= x_of_Commercial + radiusOfEffect && y_of_Residential >= y_of_Commercial - radiusOfEffect && y_of_Residential <= y_of_Commercial + radiusOfEffect) {
        complex->newWastePlantWasAdded(); // func name doesnt make sense but its just a setter
        // sends it along the chain (for cases where there are multiple decorators)
        if (this->plant != nullptr) {
            this->plant->newResidentialComplexWasAdded(complex);
        }
    }
}

int WastePlant::getRadiusOfEffect() {
    return plant->getRadiusOfEffect();
}

string WastePlant::getPlantType(){
    return setWastePlant();
}

string WastePlant::setWastePlant(){
    plantType = "|Waste Plant|" + plant->getPlantType();
    return this->plantType;
}