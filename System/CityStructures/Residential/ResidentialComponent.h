#ifndef RESIDENTIAL_COMPONENT_H
#define RESIDENTIAL_COMPONENT_H

#include <string>
#include "../CityStructure.h"
#include "../../CityMap.h"

class CityMap;

/**
 * @class ResidentialComponent
 * @brief Abstract class for components of residential structures.
 *
 * The `ResidentialComponent` class serves as a base class for all residential components,
 * providing an interface for common functionality like placing structures, removing them,
 * and calculating capacities.
 */
class ResidentialComponent : public CityStructure {
public:
    /**
     * @brief Destroys the ResidentialComponent object.
     */
    virtual ~ResidentialComponent() {};

    /**
     * @brief Gets the type of the structure.
     * @return A string representing the structure type.
     */
    virtual std::string getStructureType() = 0;

    /**
     * @brief Places the structure in the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    virtual bool placeStructure(int x, int y, CityMap* cityMap) = 0;

    /**
     * @brief Removes the structure.
     * @return True if the structure is successfully removed, false otherwise.
     */
    virtual bool removeStructure() = 0;

    /**
     * @brief Gets the capacity of the residential component.
     * @return An integer representing the component's capacity.
     */
    virtual int getCapacity() = 0; // retrieves the member variable capacity whereas calculateCapacity() recalculates the capacity every time

    /**
     * @brief Calculates the capacity of the residential component.
     * @return An integer representing the calculated capacity.
     */
    virtual int calculateCapacity() = 0; // composite function

    /**
     * @brief Gets the cost of the residential component.
     * @return An integer representing the cost.
     */
    virtual int getCost() = 0;

    /**
     * @brief Clones the residential component.
     * @return A pointer to a cloned `ResidentialComponent`.
     */
    virtual ResidentialComponent* clone() const = 0;
};

#endif // RESIDENTIAL_COMPONENT_H
