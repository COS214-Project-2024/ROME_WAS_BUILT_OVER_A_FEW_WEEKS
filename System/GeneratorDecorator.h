#ifndef GENERATOR_DECORATOR_H
#define GENERATOR_DECORATOR_H

#include "Factory.h"

class GeneratorDecorator : public Factory {
    protected:
        
    public:
        GeneratorDecorator(Generator* generator);
        virtual ~GeneratorDecorator();
        virtual void generate() = 0;
};

#endif