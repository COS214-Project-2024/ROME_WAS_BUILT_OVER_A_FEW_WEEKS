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
        Factory(){cost = 1000; woodCost = 0; steelCost = 0; concreteCost = 0;};
        Factory(int qunatity) : qunatity(qunatity) {};
        virtual ~Factory(){};
        int getQuantity(){return this->qunatity;};
        virtual string getFactoryType();
        virtual bool placeStructure(int x, int y, CityMap* cityMap);
        virtual int generate() = 0;
};


#endif