#ifndef RESIDENTIAL_COMPONENT_H
#define RESIDENTIAL_COMPONENT_H

#include "CityStructure.h"

class ResidentialComponent : public CityStructure {
    public:
        virtual void placeStructure(int x, int y, CityMap* cityMap) = 0;
        virtual void removeStructure() = 0;
        virtual ~ResidentialComponent();
        virtual int getCapacity() = 0; // retrieves the memeber variable capacity whereas calculateCapacity() re calculates the capacity every time

        // virtual void calculateStatisfaction() : NO NEED since it will be same for all in complex
        virtual int calculateCapacity() = 0; //composite function

        

};

#endif