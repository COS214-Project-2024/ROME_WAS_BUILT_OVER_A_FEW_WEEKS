#ifndef LANDMARK_H
#define LANDMARK_H

#include "CityStructure.h"

class Landmark : public CityStructure {
    private:
        int radiusOfEffect;
    public:
        Landmark(int radiusOfEffect);
        virtual ~Landmark();
        int getRadiusOfEffect();
        void placeStructure(int x, int y, CityMap* cityMap);
        void removeStructure();
        void newResidentialComplexWasAdded(ResidentialComplex* complex);
        
        
};

#endif