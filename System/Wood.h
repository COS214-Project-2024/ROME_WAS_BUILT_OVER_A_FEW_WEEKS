#ifndef WOOD_H
#define WOOD_H

#include "Material.h"

class Wood : public Material {
    public:
        Wood();
        ~Wood();
        int getProductionTimeInMinutes();
        std::string getMaterialName();
};

#endif