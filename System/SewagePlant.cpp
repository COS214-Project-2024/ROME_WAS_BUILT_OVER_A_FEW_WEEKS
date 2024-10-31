#include "SewagePlant.h"

string SewagePlant::getPlantType(){
    return setSewagePlant();
}

string SewagePlant::setSewagePlant(){
    plantType = "|Sewage Plant|" + plant->getPlantType();
    return this->plantType;
}