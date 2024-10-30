#ifndef STEEL_GENERATOR_H
#define STEEL_GENERATOR_H

#include "GeneratorDecorator.h"

class SteelGenerator : public GeneratorDecorator {
    public:
        SteelGenerator(){};
        SteelGenerator(Factory* factory);
        ~SteelGenerator();
        void addToQueue(Material* material);
        int generate();
};

#endif
