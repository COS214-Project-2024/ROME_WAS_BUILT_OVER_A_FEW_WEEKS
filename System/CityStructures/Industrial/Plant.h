#ifndef PLANT_H
#define PLANT_H

#include <string>
using namespace std;

#include "IndustrialBuilding.h"

/**
 * @class Plant
 * @brief Represents a generic industrial plant.
 *
 * The `Plant` class inherits from `IndustrialBuilding` and serves as a 
 * base class for all plant types, managing common properties such as 
 * radius of effect and plant type.
 */
class Plant : public IndustrialBuilding {
protected:
    static const int DEFAULT_RADIUS_OF_EFFECT = 5; ///< Default radius of effect for plants.
    int radiusOfEffect; ///< Radius of effect of the plant.
    string plantType; ///< Type of the plant.

public:
    /**
     * @brief Constructs a Plant object with default properties.
     */
    Plant();

    /**
     * @brief Destroys the Plant object.
     */
    virtual ~Plant();

    /**
     * @brief Gets the radius of effect for the plant.
     * @return The radius of effect as an integer.
     */
    virtual int getRadiusOfEffect();

    /**
     * @brief Places the plant structure in the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    virtual bool placeStructure(int x, int y, CityMap* cityMap);

    /**
     * @brief Removes the plant structure from the city map.
     * @return True if the structure is successfully removed, false otherwise.
     */
    virtual bool removeStructure();

    /**
     * @brief Gets the type of the plant.
     * @return A string representing the plant type.
     */
    virtual string getPlantType();
};

#endif // PLANT_H
