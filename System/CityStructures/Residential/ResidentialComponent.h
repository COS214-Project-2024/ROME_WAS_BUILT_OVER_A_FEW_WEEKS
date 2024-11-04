#ifndef RESIDENTIAL_COMPONENT_H
#define RESIDENTIAL_COMPONENT_H

#include <string>

#include "../CityStructure.h"
#include "../../CityMap.h"

class CityMap;

class ResidentialComponent : public CityStructure {
    public:
        virtual ~ResidentialComponent(){};
        virtual std::string getStructureType() = 0;

        virtual bool placeStructure(int x, int y, CityMap* cityMap) = 0;
        virtual bool removeStructure() = 0;
        
        virtual int getCapacity() = 0; // retrieves the memeber variable capacity whereas calculateCapacity() re calculates the capacity every time

        // virtual void calculateStatisfaction() : NO NEED since it will be same for all in complex
        virtual int calculateCapacity() = 0; //composite function
        virtual int getCost() = 0;


        

};

#endif