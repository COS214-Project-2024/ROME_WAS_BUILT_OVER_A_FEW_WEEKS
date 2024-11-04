/**
 * @file ResidentialComponent.h
 * @brief Header file for the ResidentialComponent class.
 */

#ifndef RESIDENTIAL_COMPONENT_H
#define RESIDENTIAL_COMPONENT_H

#include "CityStructure.h"

/**
 * @class ResidentialComponent
 * @brief An abstract class representing a component in a residential structure.
 * 
 * This class serves as a base class for different types of residential components.
 * It inherits from CityStructure and provides common functionality for residential 
 * structures, such as placing and removing components, as well as calculating and 
 * retrieving capacity.
 */
class ResidentialComponent : public CityStructure {
public:
    /**
     * @brief Places the residential component on a city map.
     * @param x The x-coordinate for the placement.
     * @param y The y-coordinate for the placement.
     * @param cityMap A pointer to the CityMap where the structure is placed.
     */
    virtual void placeStructure(int x, int y, CityMap* cityMap) = 0;

    /**
     * @brief Removes the residential component from the city map.
     */
    virtual void removeStructure() = 0;

    /**
     * @brief Virtual destructor for the ResidentialComponent class.
     */
    virtual ~ResidentialComponent();

    /**
     * @brief Retrieves the current capacity of the residential component.
     * 
     * This method returns the capacity stored as a member variable.
     * @return The current capacity of the residential component.
     */
    virtual int getCapacity() = 0;

    /**
     * @brief Calculates and returns the total capacity of the residential component.
     * 
     * This method recalculates the capacity whenever it is called, unlike `getCapacity()`, 
     * which simply retrieves the stored capacity value
     * 
     * @return The recalculated capacity of the residential component.
     */
    virtual int calculateCapacity() = 0;

    /**
     * @brief Clones the current ResidentialComponent.
     * 
     * This method implements the Prototype pattern, allowing for the creation of a copy 
     * of the current object.
     * 
     * @return A pointer to the newly cloned ResidentialComponent.
     */
    virtual ResidentialComponent* clone() const = 0;
};

#endif // RESIDENTIAL_COMPONENT_H
