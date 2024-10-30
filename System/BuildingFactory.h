#ifndef BUILDING_FACTORY_H
#define BUILDING_FACTORY_H

#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "IndustrialBuilding.h"
#include "Landmark.h"

class BuildingFactory {
public:
    virtual ~BuildingFactory() {}
};

#endif

