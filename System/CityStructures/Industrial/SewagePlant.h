#ifndef SewagePlant_h
#define SewagePlant_h

#include "PlantDecorator.h"

/**
 * @class SewagePlant
 * @brief Represents a sewage treatment plant.
 *
 * The `SewagePlant` class inherits from `PlantDecorator` and provides 
 * functionality for managing a sewage plant's placement and its effects 
 * on the surrounding area.
 */
class SewagePlant : public PlantDecorator {
public:
    /**
     * @brief Constructs a SewagePlant with the specified base plant.
     * @param plant Pointer to the base plant being decorated.
     */
    SewagePlant(Plant* plant);

    /**
     * @brief Destroys the SewagePlant object.
     */
    virtual ~SewagePlant();

    /**
     * @brief Places the sewage plant structure in the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    bool placeStructure(int x, int y, CityMap* cityMap);

    /**
     * @brief Removes the sewage plant structure from the city map.
     * @return True if the structure is successfully removed, false otherwise.
     */
    bool removeStructure();

    /**
     * @brief Notifies that a new residential complex has been added.
     * @param complex Pointer to the `ResidentialComplex` that was added.
     */
    void newResidentialComplexWasAdded(ResidentialComplex* complex);

    /**
     * @brief Gets the radius of effect for the sewage plant.
     * @return An integer representing the radius of effect.
     */
    int getRadiusOfEffect();

    /**
     * @brief Gets the type of the sewage plant.
     * @return A string representing the plant type.
     */
    string getPlantType();

    /**
     * @brief Sets up the sewage plant.
     * @return A string indicating the setup process.
     */
    string setSewagePlant();
};

#endif // SewagePlant_h
