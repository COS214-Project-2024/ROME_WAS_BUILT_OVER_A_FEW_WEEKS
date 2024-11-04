#ifndef CONCRETE_GENERATOR_H
#define CONCRETE_GENERATOR_H

#include "GeneratorDecorator.h"

/**
 * @class ConcreteGenerator
 * @brief Represents a generator for producing concrete.
 *
 * The `ConcreteGenerator` class inherits from `GeneratorDecorator` 
 * and manages the generation of concrete materials in a factory.
 */
class ConcreteGenerator : public GeneratorDecorator {
public:
    /**
     * @brief Constructs a ConcreteGenerator with the specified factory.
     * @param factory Pointer to the factory that the generator will use.
     */
    ConcreteGenerator(Factory* factory);

    /**
     * @brief Destroys the ConcreteGenerator object.
     */
    virtual ~ConcreteGenerator();

    /**
     * @brief Generates a material.
     * @return An integer representing the result of the generation process.
     */
    int generate();

    /**
     * @brief Generates concrete materials specifically.
     * @return An integer representing the amount of concrete generated.
     */
    int generateConcrete();

    /**
     * @brief Gets the type of the factory using this generator.
     * @return A string representing the factory type.
     */
    string getFactoryType();

    /**
     * @brief Sets up the concrete generator.
     * @return A string indicating the setup process.
     */
    string setConcreteGenerator();

    /**
     * @brief Places the structure in the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    bool placeStructure(int x, int y, CityMap* cityMap);

    /**
     * @brief Removes the structure from the city map.
     * @return True if the structure is successfully removed, false otherwise.
     */
    bool removeStructure();
};

#endif // CONCRETE_GENERATOR_H
