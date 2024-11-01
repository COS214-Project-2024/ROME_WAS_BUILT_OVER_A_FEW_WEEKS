#include "SteelGenerator.h"

SteelGenerator::~SteelGenerator(){
    delete factory;
}


int SteelGenerator::generate(){
    return generateSteel();
}

int SteelGenerator::generateSteel(){
    return 100;
}

string SteelGenerator::getFactoryType(){
    return setSteelGenerator();
}

string SteelGenerator::setSteelGenerator(){
    factoryType = "|Steel Factory|" + factory->getFactoryType();
    return this->factoryType;
}