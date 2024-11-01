#include "WastePlant.h"

string WastePlant::getPlantType(){
    return setWastePlant();
}

string WastePlant::setWastePlant(){
    plantType = "|Waste Plant|" + plant->getPlantType();
    return this->plantType;
}