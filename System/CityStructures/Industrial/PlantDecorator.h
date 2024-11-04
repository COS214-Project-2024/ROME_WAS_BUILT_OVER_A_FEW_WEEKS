#ifndef PLANT_DECORATOR_H
#define PLANT_DECORATOR_H

#include <iostream>
#include "Plant.h"

/**
 * @class PlantDecorator
 * @brief Abstract base class for decorating plants.
 *
 * The `PlantDecorator` class inherits from `Plant` and serves as a 
 * base class for all plant decorators, providing common functionality 
 * for managing a base plant's properties and behaviors.
 */
class PlantDecorator : public Plant {
protected:
    Plant* plant; ///< Pointer to the base plant being decorated.

public:
    /**
     * @brief Default constructor for PlantDecorator.
     */
    PlantDecorator();

    /**
     * @brief Constructs a PlantDecorator with the specified base plant.
     * @param plant Pointer to the base plant being decorated.
     */
    PlantDecorator(Plant* plant);

    /**
     * @brief Destroys the PlantDecorator object.
     */
    virtual ~PlantDecorator();

    /**
     * @brief Gets the radius of effect for the decorated plant.
     * @return An integer representing the radius of effect.
     */
    int getRadiusOfEffect();

    /**
     * @brief Places the plant structure in the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    virtual bool placeStructure(int x, int y, CityMap* cityMap) = 0;

    /**
     * @brief Removes the plant structure from the city map.
     * @return True if the structure is successfully removed, false otherwise.
     */
    virtual bool removeStructure() = 0;

    /**
     * @brief Gets the type of the plant.
     * @return A string representing the plant type.
     */
    virtual string getPlantType();
};

#endif // PLANT_DECORATOR_H
