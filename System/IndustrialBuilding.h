#ifndef INDUSTRIAL_BUILDING_H
#define INDUSTRIAL_BUILDING_H

#include "RadiusBuilding.h"

class IndustrialBuilding : public RadiusBuilding {
    public:
        IndustrialBuilding(int radiusOfEffect);
        void placeStructure(int x, int y, CityMap* cityMap);
        virtual ~IndustrialBuilding();
};



#endif