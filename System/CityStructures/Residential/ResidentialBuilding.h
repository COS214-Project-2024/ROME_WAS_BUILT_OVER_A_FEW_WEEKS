#ifndef RESIDENTIAL_BUILDING_H
#define RESIDENTIAL_BUILDING_H

#include "ResidentialComponent.h"
#include "../../CityMap.h"
#include <string>

class CityMap;

class ResidentialBuilding : public ResidentialComponent {
    protected:
        int capacity;
    public:
        ResidentialBuilding(int capacity);
        ~ResidentialBuilding();
        std::string getStructureType();
        bool placeStructure(int x, int y, CityMap* cityMap);
        bool removeStructure();
        int getCapacity(); // SAME AS calculateCapacity()
        int calculateCapacity();
        int getCost();
        // virtual std::string getResidentialBuildingType() = 0;
        // clone method for prototype
        ResidentialComponent* clone() const override;
};

#endif