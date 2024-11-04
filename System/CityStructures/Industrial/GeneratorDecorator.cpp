#include "GeneratorDecorator.h"

GeneratorDecorator::GeneratorDecorator(){
    factory = nullptr;
}

GeneratorDecorator::GeneratorDecorator(Factory* factory) : factory(factory){
    this->factory = factory;
}

GeneratorDecorator::~GeneratorDecorator(){
    delete factory;
    factory = nullptr;
    delete cityMap;
    cityMap = nullptr;
}

int GeneratorDecorator::generate(){
    return factory->generate();
}

std::string GeneratorDecorator::getFactoryType(){
    return factory->getFactoryType();
}