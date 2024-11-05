#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

class Material {
    protected:
        int productionTimeInMinutes;
    public:
        virtual int getProductionTimeInMinutes() = 0;
        virtual std::string getMaterialName() = 0;
        virtual ~Material(){};
};

#endif