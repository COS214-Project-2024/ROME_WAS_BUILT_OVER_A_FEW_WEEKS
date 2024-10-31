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

