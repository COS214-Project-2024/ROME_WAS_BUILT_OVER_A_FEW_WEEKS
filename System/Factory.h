#ifndef FACTORY_H
#define FACTORY_H

#include "IndustrialBuilding.h"
#include "Material.h"
#include <queue>

class Factory : public IndustrialBuilding {
    protected:
        int qunatity;
    public:
        Factory(){};
        virtual ~Factory(){};
        int getQuantity(){return this->qunatity;};
};


#endif