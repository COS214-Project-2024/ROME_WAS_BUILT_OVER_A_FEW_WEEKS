#ifndef LANDMARK_H
#define LANDMARK_H

#include "../CityStructure.h"
#include "../../CityMap.h"
#include "../Residential/ResidentialComplex.h"

class ResidentialComplex;

class CityMap;

class Landmark : public CityStructure {
    private:
        int radiusOfEffect;
    public:
        Landmark(int radiusOfEffect);
        virtual ~Landmark() ;
        int getRadiusOfEffect();
        bool placeStructure(int x, int y, CityMap* cityMap);
        void removeStructure();
        void newResidentialComplexWasAdded(ResidentialComplex* complex);
        std::string getStructureType();
        
        
};

#endif