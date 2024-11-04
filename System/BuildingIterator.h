#ifndef BUILDINGITERATOR_H
#define BUILDINGITERATOR_H

#include "./CityStructures/Residential/ResidentialComplex.h"  // Enclosed in quotes for local inclusion

/**
 * @class BuildingIterator
 * @brief Abstract class defining an interface for iterating over buildings in a city.
 */
class BuildingIterator {
public:
    /**
     * @brief Destructor for BuildingIterator.
     */
    virtual ~BuildingIterator() = default;

    /**
     * @brief Checks if there are more buildings to iterate over.
     * @return True if there are more buildings, false otherwise.
     */
    virtual bool hasNext() const = 0;

    /**
     * @brief Retrieves the next building in the iteration.
     * @return Pointer to the next ResidentialComplex.
     */
    virtual ResidentialComplex* next() = 0;
};

#endif  // BUILDINGITERATOR_H
