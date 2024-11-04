#ifndef CONCRETE_GENERATOR_H
#define CONCRETE_GENERATOR_H

#include "GeneratorDecorator.h"


class ConcreteGenerator : public GeneratorDecorator {
    public:
        ConcreteGenerator(Factory* factory);
        virtual ~ConcreteGenerator();
        int generate();
        int generateConcrete();
        string getFactoryType();
        string setConcreteGenerator();
        bool placeStructure(int x, int y, CityMap* cityMap);
        bool removeStructure();
};

#endif