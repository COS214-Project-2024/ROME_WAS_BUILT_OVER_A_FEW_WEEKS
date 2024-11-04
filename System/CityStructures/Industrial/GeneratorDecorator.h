#ifndef GENERATOR_DECORATOR_H
#define GENERATOR_DECORATOR_H

#include <iostream>
#include "Factory.h"
class Factory;

class GeneratorDecorator : public Factory {
    protected:
        Factory* factory;
        
    public:
        GeneratorDecorator();
        GeneratorDecorator(Factory* factory);
        virtual ~GeneratorDecorator();
        virtual int generate();
        virtual string getFactoryType();
        virtual bool placeStructure(int x, int y, CityMap* cityMap) = 0;
        virtual bool removeStructure() = 0;
};

#endif