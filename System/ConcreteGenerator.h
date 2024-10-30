#ifndef CONCRETE_GENERATOR_H
#define CONCRETE_GENERATOR_H

#include "GeneratorDecorator.h"


class ConcreteGenerator : public GeneratorDecorator {
    public:
        ConcreteGenerator(){};
        ConcreteGenerator(Factory* factory);
        ~ConcreteGenerator();
        int generate();
        int generateConcrete();
};

#endif
