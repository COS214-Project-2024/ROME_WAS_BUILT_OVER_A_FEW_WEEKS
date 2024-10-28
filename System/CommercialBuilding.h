#ifndef COMMERICAL_BUILDING_H
#define COMMERICAL_BUILDING_H

#include "RadiusBuilding.h"

class CommercialBuilding : public RadiusBuilding {
    public:
        CommercialBuilding(int radiusOfEffect);
        void placeStructure(int x, int y, CityMap* cityMap);
        virtual ~CommercialBuilding();

        
};

#endif