#ifndef WASTEPLANT_H
#define WASTEPLANT_H

#include "PlantDecorator.h"

/**
 * @class WastePlant
 * @brief Concrete decorator for managing waste disposal facilities.
 *
 * The `WastePlant` class enhances a `Plant` by adding functionality related 
 * to waste management for residential complexes.
 */
class WastePlant : public PlantDecorator {
public:
    /**
     * @brief Constructs a WastePlant with a specified plant.
     * @param plant Pointer to the `Plant` to be decorated.
     */
    WastePlant(Plant* plant);

    /**
     * @brief Destroys the WastePlant object.
     */
    virtual ~WastePlant();

    /**
     * @brief Places the waste plant structure at the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    bool placeStructure(int x, int y, CityMap* cityMap);

    /**
     * @brief Removes the waste plant structure from the city map.
     * @return True if the structure is successfully removed, false otherwise.
     */
    bool removeStructure();

    /**
     * @brief Notifies that a new residential complex has been added.
     * @param complex Pointer to the `ResidentialComplex` that was added.
     */
    void newResidentialComplexWasAdded(ResidentialComplex* complex);

    /**
     * @brief Gets the radius of effect for the waste plant.
     * @return An integer representing the radius of effect.
     */
    int getRadiusOfEffect();

    /**
     * @brief Gets the type of the plant.
     * @return A string representing the type of the waste plant.
     */
    string getPlantType();

    /**
     * @brief Sets the type of the waste plant.
     * @return A string indicating the waste plant type.
     */
    string setWastePlant();
};

#endif // WASTEPLANT_H
