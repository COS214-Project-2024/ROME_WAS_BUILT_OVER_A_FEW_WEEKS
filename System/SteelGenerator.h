#ifndef STEEL_GENERATOR_H
#define STEEL_GENERATOR_H

#include "GeneratorDecorator.h"

class SteelGenerator : public GeneratorDecorator {
    public:
        SteelGenerator(){};
        SteelGenerator(Factory* factory) : GeneratorDecorator(factory) {this->factory = factory;};
        ~SteelGenerator();
        int generate();
        int generateSteel();
        string getFactoryType();
        string setSteelGenerator();
};

#endif
