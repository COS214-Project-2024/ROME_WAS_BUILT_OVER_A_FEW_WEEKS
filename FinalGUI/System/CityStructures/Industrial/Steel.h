#ifndef STEEL_H
#define STEEL_H

#include "Material.h"

class Steel : public Material {
    public:
        Steel();
        ~Steel();
        int getProductionTimeInMinutes();
        std::string getMaterialName();
};

#endif