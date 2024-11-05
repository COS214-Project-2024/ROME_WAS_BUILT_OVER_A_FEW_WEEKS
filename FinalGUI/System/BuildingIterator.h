#ifndef BUILDINGITERATOR_H
#define BUILDINGITERATOR_H

#include "./CityStructures/Residential/ResidentialComplex.h"  // Enclosed in quotes for local inclusion

class BuildingIterator {
public:
    virtual ~BuildingIterator() = default;
    virtual bool hasNext() const = 0;  // Check if there are more buildings to iterate over
    virtual ResidentialComplex* next() = 0;      // Get the next building in the iteration
};

#endif  // BUILDINGITERATOR_H

