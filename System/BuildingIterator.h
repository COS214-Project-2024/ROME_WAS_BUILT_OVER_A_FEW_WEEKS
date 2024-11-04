#ifndef BUILDINGITERATOR_H
#define BUILDINGITERATOR_H

#include "./CityStructures/Residential/ResidentialComponent.h"  // Enclosed in quotes for local inclusion

class BuildingIterator {
public:
    virtual ~BuildingIterator(){};
    virtual bool hasNext() = 0;  // Check if there are more buildings to iterate over
    virtual ResidentialComponent* next() = 0;      // Get the next building in the iteration
};

#endif  // BUILDINGITERATOR_H

