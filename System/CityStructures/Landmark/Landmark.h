#ifndef LANDMARK_H
#define LANDMARK_H

#include "../CityStructure.h"
#include "../../CityMap.h"
#include "../Residential/ResidentialComplex.h"

class ResidentialComplex;
class CityMap;

/**
 * @class Landmark
 * @brief Represents a generic landmark structure within the city.
 *
 * The `Landmark` class provides base functionality for specific landmarks,
 * including placement, removal, and interaction with residential complexes.
 */
class Landmark : public CityStructure {
private:
    int radiusOfEffect; /**< Radius of effect for this landmark. */

public:
    /**
     * @brief Constructs a `Landmark` with a specified radius of effect.
     * @param radiusOfEffect Radius within which the landmark has an influence.
     */
    Landmark(int radiusOfEffect);

    /**
     * @brief Virtual destructor for the `Landmark` class.
     */
    virtual ~Landmark();

    /**
     * @brief Retrieves the radius of effect for the landmark.
     * @return The radius of effect as an integer.
     */
    int getRadiusOfEffect();

    /**
     * @brief Places the landmark structure at specified coordinates on the city map.
     * @param x The x-coordinate where the landmark is placed.
     * @param y The y-coordinate where the landmark is placed.
     * @param cityMap Pointer to the `CityMap` in which the structure is being placed.
     * @return `true` if the structure was successfully placed; otherwise `false`.
     */
    bool placeStructure(int x, int y, CityMap* cityMap);

    /**
     * @brief Removes the landmark structure from the city map.
     * @return `true` if the structure was successfully removed; otherwise `false`.
     */
    bool removeStructure();

    /**
     * @brief Notifies the landmark that a new residential complex was added.
     * @param complex Pointer to the added `ResidentialComplex`.
     */
    void newResidentialComplexWasAdded(ResidentialComplex* complex);

    /**
     * @brief Gets the type of the structure as a string.
     * @return A string representing the type of the structure.
     */
    std::string getStructureType();
};

#endif // LANDMARK_H
