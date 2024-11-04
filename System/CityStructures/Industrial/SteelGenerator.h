#ifndef STEEL_GENERATOR_H
#define STEEL_GENERATOR_H

#include "GeneratorDecorator.h"

class SteelGenerator : public GeneratorDecorator {
    public:
        SteelGenerator(Factory* factory);;
        virtual ~SteelGenerator();
        int generate();
        int generateSteel();
        string getFactoryType();
        string setSteelGenerator();
        bool placeStructure(int x, int y, CityMap* cityMap);
        bool removeStructure();
};

#endif