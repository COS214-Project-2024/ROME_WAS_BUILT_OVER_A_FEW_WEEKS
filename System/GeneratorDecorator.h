#ifndef GENERATOR_DECORATOR_H
#define GENERATOR_DECORATOR_H

#include <iostream>
#include "Factory.h"
class Factory;

class GeneratorDecorator : public Factory {
    protected:
        Factory* factory;
        
    public:
        GeneratorDecorator(){};
        GeneratorDecorator(Factory* factory): factory(factory){};
        virtual ~GeneratorDecorator(){};
        virtual int generate(){return 0;};
};

#endif