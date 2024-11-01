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

string WoodGenerator::getFactoryType(){
    return setWoodGenerator();
}


string WoodGenerator::setWoodGenerator(){
    factoryType = "|Wood Factory|" + factory->getFactoryType();
    return this->factoryType;
}