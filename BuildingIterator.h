#ifndef BUILDINGITERATOR_H
#define BUILDINGITERATOR_H

#include "ResidentialComplex.h"  // Enclosed in quotes for local inclusion

/**
 * @class BuildingIterator
 * @brief Abstract iterator interface for iterating over buildings.
 *
 * The `BuildingIterator` class provides an interface for iterating over a collection of
 * `ResidentialComplex` buildings. Derived classes implement specific iteration behaviors.
 */
class BuildingIterator {
public:
    /**
     * @brief Virtual destructor for `BuildingIterator`.
     *
     * Ensures proper cleanup of derived classes.
     */
    virtual ~BuildingIterator() = default;

    /**
     * @brief Checks if there are more buildings in the iteration.
     * @return `true` if there are more buildings to iterate over, otherwise `false`.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     */
    virtual bool hasNext() const = 0;

    /**
     * @brief Retrieves the next `ResidentialComplex` in the iteration.
     * @return A pointer to the next `ResidentialComplex` object.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     */
    virtual ResidentialComplex* next() = 0;
};

#endif  // BUILDINGITERATOR_H
