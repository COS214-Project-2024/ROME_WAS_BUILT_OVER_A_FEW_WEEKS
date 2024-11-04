#ifndef FACTORY_H
#define FACTORY_H

#include "IndustrialBuilding.h"
#include "Material.h"
#include <queue>
#include <string>
using namespace std;

/**
 * @class Factory
 * @brief Represents a factory for producing industrial materials.
 *
 * The `Factory` class inherits from `IndustrialBuilding` and 
 * manages production quantities and the factory type.
 */
class Factory : public IndustrialBuilding {
protected:
    int quantity; ///< Quantity of materials produced.
    string factoryType; ///< Type of the factory.
public:
    /**
     * @brief Constructs a Factory object.
     */
    Factory();

    /**
     * @brief Destroys the Factory object.
     */
    virtual ~Factory();

    /**
     * @brief Gets the quantity of materials produced by the factory.
     * @return An integer representing the quantity.
     */
    int getQuantity();

    /**
     * @brief Gets the type of the factory.
     * @return A string representing the factory type.
     */
    virtual string getFactoryType();

    /**
     * @brief Places the factory structure in the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    virtual bool placeStructure(int x, int y, CityMap* cityMap);

    /**
     * @brief Removes the factory structure from the city map.
     * @return True if the structure is successfully removed, false otherwise.
     */
    virtual bool removeStructure();

    /**
     * @brief Generates materials in the factory.
     * @return An integer representing the result of the generation process.
     */
    virtual int generate();
};

#endif // FACTORY_H
