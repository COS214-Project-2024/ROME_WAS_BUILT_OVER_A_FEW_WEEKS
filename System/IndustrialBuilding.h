#ifndef INDUSTRIAL_BUILDING_H
#define INDUSTRIAL_BUILDING_H

#include "CityStructure.h"

class IndustrialBuilding : public CityStructure {
    public:
        IndustrialBuilding();
        virtual ~IndustrialBuilding();
        std::string getStructureType();
        
        void placeStructure(int x, int y, CityMap* cityMap);

};



#endif