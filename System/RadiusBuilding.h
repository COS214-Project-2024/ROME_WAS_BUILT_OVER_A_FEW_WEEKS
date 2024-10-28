#ifndef RADIUS_BUILDING_H
#define RADIUS_BUILDING_H

#include "CityStructure.h"

class RadiusBuilding : public CityStructure {
    private:
        int radiusOfEffect;
    public:
        RadiusBuilding(int radiusOfEffect);
        virtual ~RadiusBuilding();
        int getRadiusOfEffect();

        void placeStructure(int x, int y, CityMap* cityMap) = 0;
        void removeStructure();
        

        
};

#endif