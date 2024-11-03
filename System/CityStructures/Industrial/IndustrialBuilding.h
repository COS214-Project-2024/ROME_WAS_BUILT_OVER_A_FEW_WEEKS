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
        
        bool placeStructure(int x, int y, CityMap* cityMap);
        virtual bool removeStructure();

};



#endif