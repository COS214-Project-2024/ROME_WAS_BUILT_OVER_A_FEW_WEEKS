#ifndef STEEL_GENERATOR_H
#define STEEL_GENERATOR_H

#include "GeneratorDecorator.h"

/**
 * @class SteelGenerator
 * @brief Concrete decorator for generating steel resources.
 *
 * The `SteelGenerator` class enhances a `Factory` by adding steel generation capabilities.
 */
class SteelGenerator : public GeneratorDecorator {
public:
    /**
     * @brief Constructs a SteelGenerator with a specified factory.
     * @param factory Pointer to the `Factory` to be decorated.
     */
    SteelGenerator(Factory* factory);

    /**
     * @brief Destroys the SteelGenerator object.
     */
    virtual ~SteelGenerator();

    /**
     * @brief Generates resources, specifically steel.
     * @return An integer representing the amount of steel generated.
     */
    int generate();

    /**
     * @brief Generates steel resources.
     * @return An integer representing the amount of steel generated.
     */
    int generateSteel();

    /**
     * @brief Gets the type of the factory.
     * @return A string representing the factory type.
     */
    string getFactoryType();

    /**
     * @brief Sets the steel generator type.
     * @return A string indicating the steel generator type.
     */
    string setSteelGenerator();

    /**
     * @brief Places the steel generator structure at the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    bool placeStructure(int x, int y, CityMap* cityMap);

    /**
     * @brief Removes the steel generator structure from the city map.
     * @return True if the structure is successfully removed, false otherwise.
     */
    bool removeStructure();
};

#endif // STEEL_GENERATOR_H
