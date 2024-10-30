#include "WoodGenerator.h"

WoodGenerator::WoodGenerator(Factory *factory){
    this->factory = factory;
}

WoodGenerator::~WoodGenerator(){
    delete factory;
}

int WoodGenerator::generate(){
    return generateWood();
}

int WoodGenerator::generateWood(){
    return 100;
}


