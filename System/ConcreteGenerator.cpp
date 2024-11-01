#include "ConcreteGenerator.h"

ConcreteGenerator::~ConcreteGenerator(){
    delete factory;
}

int ConcreteGenerator::generate(){
    return generateConcrete();
}

int ConcreteGenerator::generateConcrete(){
    return 100;
}

string ConcreteGenerator::getFactoryType(){
    return setConcreteGenerator();
}

string ConcreteGenerator::setConcreteGenerator(){
    factoryType = "|Concrete Factory|" + factory->getFactoryType();
    return this->factoryType;
}