#ifndef GENERATOR_DECORATOR_H
#define GENERATOR_DECORATOR_H

#include <iostream>
#include "Factory.h"
class Factory;

/**
 * @class GeneratorDecorator
 * @brief Abstract decorator class for enhancing factory functionalities.
 *
 * The `GeneratorDecorator` class is designed to extend the functionality 
 * of `Factory` objects by allowing additional behavior while maintaining 
 * the factory's interface.
 */
class GeneratorDecorator : public Factory {
protected:
    Factory* factory; ///< Pointer to the original factory being decorated.

public:
    /**
     * @brief Constructs a GeneratorDecorator object with no associated factory.
     */
    GeneratorDecorator();

    /**
     * @brief Constructs a GeneratorDecorator object with a specified factory.
     * @param factory Pointer to the `Factory` to be decorated.
     */
    GeneratorDecorator(Factory* factory);

    /**
     * @brief Destroys the GeneratorDecorator object.
     */
    virtual ~GeneratorDecorator();

    /**
     * @brief Generates a product or resource.
     * @return An integer representing the result of the generation process.
     */
    virtual int generate();

    /**
     * @brief Gets the type of the factory.
     * @return A string representing the factory type.
     */
    virtual string getFactoryType();

    /**
     * @brief Places the generator structure at the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    virtual bool placeStructure(int x, int y, CityMap* cityMap) = 0;

    /**
     * @brief Removes the generator structure from the city map.
     * @return True if the structure is successfully removed, false otherwise.
     */
    virtual bool removeStructure() = 0;
};

#endif // GENERATOR_DECORATOR_H
