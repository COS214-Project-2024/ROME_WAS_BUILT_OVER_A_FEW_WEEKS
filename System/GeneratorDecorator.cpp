#include "GeneratorDecorator.h"

GeneratorDecorator::GeneratorDecorator(Factory *factory){
    this->factory = factory;
}

GeneratorDecorator::~GeneratorDecorator(){
    delete factory;
}
