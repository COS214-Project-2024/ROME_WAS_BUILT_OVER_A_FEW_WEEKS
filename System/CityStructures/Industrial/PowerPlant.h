#ifndef PowerPlant_h
#define PowerPlant_h

#include "PlantDecorator.h"

/**
 * @class PowerPlant
 * @brief Represents a power generation plant.
 *
 * The `PowerPlant` class inherits from `PlantDecorator` and provides 
 * functionality for managing a power plant's placement and its effects 
 * on the surrounding area.
 */
class PowerPlant : public PlantDecorator {
public:
    /**
     * @brief Constructs a PowerPlant with the specified base plant.
     * @param plant Pointer to the base plant being decorated.
     */
    PowerPlant(Plant* plant);

    /**
     * @brief Destroys the PowerPlant object.
     */
    virtual ~PowerPlant();

    /**
     * @brief Places the power plant structure in the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    bool placeStructure(int x, int y, CityMap* cityMap);

    /**
     * @brief Removes the power plant structure from the city map.
     * @return True if the structure is successfully removed, false otherwise.
     */
    bool removeStructure();

    /**
     * @brief Notifies that a new residential complex has been added.
     * @param complex Pointer to the `ResidentialComplex` that was added.
     */
    void newResidentialComplexWasAdded(ResidentialComplex* complex);

    /**
     * @brief Gets the radius of effect for the power plant.
     * @return An integer representing the radius of effect.
     */
    int getRadiusOfEffect();

    /**
     * @brief Gets the type of the power plant.
     * @return A string representing the plant type.
     */
    string getPlantType();

    /**
     * @brief Sets up the power plant.
     * @return A string indicating the setup process.
     */
    string setPowerPlant();
};

#endif // PowerPlant_h
