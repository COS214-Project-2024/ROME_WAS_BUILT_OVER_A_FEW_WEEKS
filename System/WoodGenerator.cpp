#include "WoodGenerator.h"

WoodGenerator::~WoodGenerator(){
    delete factory;
}

int WoodGenerator::generate(){
    return generateWood();
}

int WoodGenerator::generateWood(){
    return 100;
}


