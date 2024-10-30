#ifndef WOOD_GENERATOR_H
#define WOOD_GENERATOR_H

#include "GeneratorDecorator.h"

class WoodGenerator : public GeneratorDecorator {
    public:
        WoodGenerator(){};
        WoodGenerator(Factory* factory);
        ~WoodGenerator();
        int generate();
        int generateWood();
};

#endif
