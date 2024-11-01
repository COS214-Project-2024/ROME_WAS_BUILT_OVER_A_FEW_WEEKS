#include "PowerPlant.h"

string PowerPlant::getPlantType(){
    return setPowerPlant();
}

string PowerPlant::setPowerPlant(){
    plantType = "|Power Plant|" + plant->getPlantType();
    return this->plantType;
}