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
        GeneratorDecorator(Factory* factory);
        virtual ~GeneratorDecorator();
        virtual void addToQueue(Material* material) =0;
        virtual int generate() = 0;
};

#endif