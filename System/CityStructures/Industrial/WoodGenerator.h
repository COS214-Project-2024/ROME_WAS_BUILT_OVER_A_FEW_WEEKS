#ifndef WOOD_GENERATOR_H
#define WOOD_GENERATOR_H

#include "GeneratorDecorator.h"

class WoodGenerator : public GeneratorDecorator {
    public:
        WoodGenerator(Factory* factory);
        virtual ~WoodGenerator();
        int generate();
        int generateWood();
        string getFactoryType();
        string setWoodGenerator();
        bool placeStructure(int x, int y, CityMap* cityMap);
        bool removeStructure();
};

#endif