#include "SteelGenerator.h"

SteelGenerator::SteelGenerator(Factory *factory){
    this->factory = factory;
}

SteelGenerator::~SteelGenerator(){
    delete factory;
}


int SteelGenerator::generate(){
    return generateSteel();
}

int SteelGenerator::generateSteel(){
    return 100;
}