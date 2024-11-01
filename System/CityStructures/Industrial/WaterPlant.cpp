#include "WaterPlant.h"

string WaterPlant::getPlantType(){
    return setWaterPlant();
}

string WaterPlant::setWaterPlant(){
    plantType = "|Water Plant|" + plant->getPlantType();
    return this->plantType;
}