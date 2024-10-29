#ifndef PLANT_H
#define PLANT_H

#include "IndustrialBuilding.h"

class Plant : public IndustrialBuilding {
    private:
        int radiusOfEffect;
    public:
        Plant();
        virtual ~Plant();
        int getRadiusOfEffect();
        void placeStructure(int x, int y, CityMap* cityMap);
        
};

#endif