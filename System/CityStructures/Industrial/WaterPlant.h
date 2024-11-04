#ifndef WATERPLANT_H
#define WATERPLANT_H

#include "PlantDecorator.h"
class PlantDecorator;
class ResidentialComplex;

/**
 * @class WaterPlant
 * @brief Concrete decorator for adding water supply capabilities.
 *
 * The `WaterPlant` class enhances a `Plant` by adding functionality related 
 * to water supply for a residential complex.
 */
class WaterPlant : public PlantDecorator {
public:
    /**
     * @brief Constructs a WaterPlant with a specified plant.
     * @param plant Pointer to the `Plant` to be decorated.
     */
    WaterPlant(Plant* plant);

    /**
     * @brief Destroys the WaterPlant object.
     */
    virtual ~WaterPlant();

    /**
     * @brief Gets the radius of effect for the water plant.
     * @return An integer representing the radius of effect.
     */
    int getRadiusOfEffect();

    /**
     * @brief Places the water plant structure at the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    bool placeStructure(int x, int y, CityMap* cityMap);

    /**
     * @brief Removes the water plant structure from the city map.
     * @return True if the structure is successfully removed, false otherwise.
     */
    bool removeStructure();

    /**
     * @brief Notifies that a new residential complex has been added.
     * @param complex Pointer to the `ResidentialComplex` that was added.
     */
    void newResidentialComplexWasAdded(ResidentialComplex* complex);

    /**
     * @brief Gets the type of the plant.
     * @return A string representing the type of the water plant.
     */
    string getPlantType();

    /**
     * @brief Sets the type of the water plant.
     * @return A string indicating the water plant type.
     */
    string setWaterPlant();
};

#endif // WATERPLANT_H
