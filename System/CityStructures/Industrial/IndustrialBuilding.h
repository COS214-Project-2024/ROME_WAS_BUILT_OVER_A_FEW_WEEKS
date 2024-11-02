#ifndef INDUSTRIAL_BUILDING_H
#define INDUSTRIAL_BUILDING_H

#include "../CityStructure.h"
#include "../../CityMap.h"

class CityMap;

class IndustrialBuilding : public CityStructure {
    public:
        IndustrialBuilding();
        virtual ~IndustrialBuilding();
        std::string getStructureType();
        
        virtual void placeStructure(int x, int y, CityMap* cityMap);

};



#endif