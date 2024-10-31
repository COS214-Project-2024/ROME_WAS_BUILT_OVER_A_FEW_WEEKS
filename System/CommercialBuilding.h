#ifndef COMMERICAL_BUILDING_H
#define COMMERICAL_BUILDING_H

#include "CityStructure.h"

class CommercialBuilding : public CityStructure {
    private:
        int radiusOfEffect;
    public:
        CommercialBuilding(int radiusOfEffect);
        virtual ~CommercialBuilding();
        std::string getStructureType();

        int getRadiusOfEffect();
        void placeStructure(int x, int y, CityMap* cityMap);
        void removeStructure();
        

        
};

#endif