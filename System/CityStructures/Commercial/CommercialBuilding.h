#ifndef COMMERICAL_BUILDING_H
#define COMMERICAL_BUILDING_H

#include "../CityStructure.h"
#include "../../CityMap.h"
#include "../Residential/ResidentialComplex.h"

class ResidentialComplex;
class CityMap;


class CommercialBuilding : public CityStructure {
    private:
        int radiusOfEffect;
    public:
        CommercialBuilding(int radiusOfEffect);
        virtual ~CommercialBuilding();
        std::string getStructureType();

        int getRadiusOfEffect();
        bool placeStructure(int x, int y, CityMap* cityMap);
        bool removeStructure();
        void newResidentialComplexWasAdded(ResidentialComplex* complex);
        

        
};

#endif