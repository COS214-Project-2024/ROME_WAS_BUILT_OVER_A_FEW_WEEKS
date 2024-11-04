#ifndef RESIDENTIAL_BUILDING_H
#define RESIDENTIAL_BUILDING_H

#include "ResidentialComponent.h"
#include "../../CityMap.h"
#include <string>

/**
 * @class ResidentialBuilding
 * @brief Represents a residential building as a type of residential component.
 *
 * The `ResidentialBuilding` class inherits from `ResidentialComponent` and provides 
 * properties and methods common to all residential buildings, including capacity management 
 * and placement functionality.
 */
class ResidentialBuilding : public ResidentialComponent {
protected:
    int capacity; ///< The maximum capacity of the residential building.
public:
    /**
     * @brief Constructs a ResidentialBuilding object with a specified capacity.
     * @param capacity The maximum capacity of the residential building.
     */
    ResidentialBuilding(int capacity);

    /**
     * @brief Destroys the ResidentialBuilding object.
     */
    ~ResidentialBuilding();

    /**
     * @brief Gets the type of the structure.
     * @return A string representing the structure type.
     */
    std::string getStructureType() override;

    /**
     * @brief Places the structure in the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    bool placeStructure(int x, int y, CityMap* cityMap) override;

    /**
     * @brief Removes the structure.
     * @return True if the structure is successfully removed, false otherwise.
     */
    bool removeStructure() override;

    /**
     * @brief Gets the capacity of the residential building.
     * @return An integer representing the building's capacity.
     */
    int getCapacity() override; // SAME AS calculateCapacity()

    /**
     * @brief Calculates the capacity of the residential building.
     * @return An integer representing the calculated capacity.
     */
    int calculateCapacity() override;

    /**
     * @brief Gets the cost of the residential building.
     * @return An integer representing the cost.
     */
    int getCost() override;

    /**
     * @brief Clones the residential building.
     * @return A pointer to a cloned `ResidentialComponent`.
     */
    ResidentialComponent* clone() const override;
};

#endif // RESIDENTIAL_BUILDING_H
