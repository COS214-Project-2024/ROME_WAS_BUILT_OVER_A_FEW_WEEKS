#ifndef FACTORY_H
#define FACTORY_H

#include "IndustrialBuilding.h"
#include "Material.h"
#include <queue>
#include <string>
using namespace std;


class Factory : public IndustrialBuilding {
    protected:
        int qunatity;
        string factoryType;
    public:
        Factory();
        virtual ~Factory();
        int getQuantity();
        virtual string getFactoryType();
        virtual bool placeStructure(int x, int y, CityMap* cityMap);
        virtual bool removeStructure();
        virtual int generate();
};


#endif