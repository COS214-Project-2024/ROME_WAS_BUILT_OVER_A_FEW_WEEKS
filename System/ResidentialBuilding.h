#ifndef RESIDENTIAL_BUILDING_H
#define RESIDENTIAL_BUILDING_H

#include "ResidentialComponent.h"

class ResidentialBuilding : public ResidentialComponent {
    private:
        int capacity;
    public:
        ResidentialBuilding(int capacity);
        void placeStructure(int x, int y, CityMap* cityMap);
        void removeStructure();
        ~ResidentialBuilding();

        int getCapacity(); // SAME AS calculateCapacity()

        int calculateCapacity();
};

#endif