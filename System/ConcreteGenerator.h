#ifndef CONCRETE_GENERATOR_H
#define CONCRETE_GENERATOR_H

#include "GeneratorDecorator.h"


class ConcreteGenerator : public GeneratorDecorator {
    public:
        ConcreteGenerator(){};
        ConcreteGenerator(Factory* factory);
        ~ConcreteGenerator();
        void addToQueue(Material* material);
        int generate();
};

#endif
