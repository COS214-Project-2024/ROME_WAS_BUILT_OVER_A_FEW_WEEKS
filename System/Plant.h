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
        virtual std::string getPlantType() = 0; // must return everything it is decorated with somehow
        
};

#endif