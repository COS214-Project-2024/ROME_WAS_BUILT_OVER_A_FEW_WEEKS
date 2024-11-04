/**
 * @file ResidentialBuilding.h
 * @brief Header file for the ResidentialBuilding class.
 */

#ifndef RESIDENTIAL_BUILDING_H
#define RESIDENTIAL_BUILDING_H

#include "ResidentialComponent.h"

/**
 * @class ResidentialBuilding
 * @brief A class repreenting a single residential building component.
 * 
 * This class inherits from the ResidentialComponent and provides functionality 
 * related to a standalone residential building, including capacity management 
 * and basic structure operations.
 */
class ResidentialBuilding : public ResidentialComponent {
private:
    int capacity; /**< The capacity of the residential building. */

public:
    /**
     * @brief Constructs a ResidentialBuilding with a given capacity.
     * @param capacity The initial capacity of the building.
     */
    ResidentialBuilding(int capacity);

    /**
     * @brief Attempts to place the structure on a city map.
     * 
     * This function will display a message indicating that a standalone 
     * residential building cannot be placed on its own.
     * 
     * @param x The x-coordinate for the placement.
     * @param y The y-coordinate for the placement.
     * @param cityMap A pointer to the CityMap where the structure is to be placed.
     */
    void placeStructure(int x, int y, CityMap* cityMap) override;

    /**
     * @brief Attempts to remove the residential building.
     * 
     * This function will display a message indicating that a standalone 
     * residential building cannot be removed on its own.
     */
    void removeStructure() override;

    /**
     * @brief Destructor for the ResidentialBuilding.
     */
    ~ResidentialBuilding();

    /**
     * @brief Gets the capacity of the residential building.
     * @return The capacity of the building.
     */
    int getCapacity() override;

    /**
     * @brief Calculates and returns the capacity of the residential building.
     * @return The calculated capacity of the building.
     */
    int calculateCapacity() override;

    /**
     * @brief Clones the current ResidentialBuilding object.
     * 
     * This method implements the Prototype pattern, allowing for the creation 
     * of a copy of the current object.
     * 
     * @return A pointer to the newly cloned ResidentialBuilding.
     */
    ResidentialComponent* clone() const override;
};

#endif // RESIDENTIAL_BUILDING_H
