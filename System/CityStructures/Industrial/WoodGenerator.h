#ifndef WOOD_GENERATOR_H
#define WOOD_GENERATOR_H

#include "GeneratorDecorator.h"

/**
 * @class WoodGenerator
 * @brief Concrete decorator for generating wood resources.
 *
 * The `WoodGenerator` class enhances a `Factory` by adding wood generation capabilities.
 */
class WoodGenerator : public GeneratorDecorator {
public:
    /**
     * @brief Constructs a WoodGenerator with a specified factory.
     * @param factory Pointer to the `Factory` to be decorated.
     */
    WoodGenerator(Factory* factory);

    /**
     * @brief Destroys the WoodGenerator object.
     */
    virtual ~WoodGenerator();

    /**
     * @brief Generates resources, specifically wood.
     * @return An integer representing the amount of wood generated.
     */
    int generate();

    /**
     * @brief Generates wood resources.
     * @return An integer representing the amount of wood generated.
     */
    int generateWood();

    /**
     * @brief Gets the type of the factory.
     * @return A string representing the factory type.
     */
    string getFactoryType();

    /**
     * @brief Sets the wood generator type.
     * @return A string indicating the wood generator type.
     */
    string setWoodGenerator();

    /**
     * @brief Places the wood generator structure at the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    bool placeStructure(int x, int y, CityMap* cityMap);

    /**
     * @brief Removes the wood generator structure from the city map.
     * @return True if the structure is successfully removed, false otherwise.
     */
    bool removeStructure();
};

#endif // WOOD_GENERATOR_H
