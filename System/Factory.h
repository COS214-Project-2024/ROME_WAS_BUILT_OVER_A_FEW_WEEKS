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
        Factory(){};
        virtual ~Factory(){};
        int getQuantity(){return this->qunatity;};
        virtual string getFactoryType(){return factoryType;};
};


#endif