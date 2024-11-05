#ifndef WOOD_GENERATOR_H
#define WOOD_GENERATOR_H

#include "GeneratorDecorator.h"

class WoodGenerator : public GeneratorDecorator {
    public:
        WoodGenerator(){};
        WoodGenerator(Factory* factory) : GeneratorDecorator(factory) {this->factory = factory;};
        ~WoodGenerator();
        int generate();
        int generateWood();
        string getFactoryType();
        string setWoodGenerator();
};

#endif