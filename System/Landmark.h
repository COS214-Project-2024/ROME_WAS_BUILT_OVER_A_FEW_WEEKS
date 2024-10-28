#ifndef LANDMARK_H
#define LANDMARK_H

#include "RadiusBuilding.h"

class Landmark : public RadiusBuilding {
    public:
        Landmark(int radiusOfEffect);
        void placeStructure(int x, int y, CityMap* cityMap);
        virtual ~Landmark();
        
};

#endif