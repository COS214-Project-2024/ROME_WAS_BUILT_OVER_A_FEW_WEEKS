#ifndef PLANT_H
#define PLANT_H

#include "IndustrialBuilding.h"

class Plant : public IndustrialBuilding {
    private:
        int radiusOfEffect;
    public:
        Plant() {};
        virtual ~Plant(){};
        int getRadiusOfEffect() { return 0;};
        void placeStructure(int x, int y, CityMap* cityMap) {};
        
};

#endif