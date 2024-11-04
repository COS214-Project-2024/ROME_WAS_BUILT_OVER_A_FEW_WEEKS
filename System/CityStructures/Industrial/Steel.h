#ifndef STEEL_H
#define STEEL_H

#include "Material.h"

/**
 * @class Steel
 * @brief Represents steel as a material in the production system.
 *
 * The `Steel` class inherits from `Material` and provides specific implementations
 * for the production time and material name related to steel.
 */
class Steel : public Material {
public:
    /**
     * @brief Constructs a Steel object.
     */
    Steel();

    /**
     * @brief Destroys the Steel object.
     */
    ~Steel();

    /**
     * @brief Gets the production time for steel in minutes.
     * @return An integer representing the production time in minutes.
     */
    int getProductionTimeInMinutes();

    /**
     * @brief Gets the name of the material.
     * @return A string representing the name of the steel material.
     */
    std::string getMaterialName();
};

#endif // STEEL_H
