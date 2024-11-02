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
        virtual ~Factory(){};
        int getQuantity(){return this->qunatity;};
        virtual string getFactoryType(){return factoryType;};
};


#endif