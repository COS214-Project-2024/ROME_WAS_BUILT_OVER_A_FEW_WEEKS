#ifndef CONCRETE_H
#define CONCRETE_H

#include "Material.h"

class Concrete : public Material {
    public:
        Concrete();
        ~Concrete();
        int getProductionTimeInMinutes();
        std::string getMaterialName();
};

#endif