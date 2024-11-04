#ifndef WOOD_H
#define WOOD_H

#include "Material.h"

/**
 * @class Wood
 * @brief Represents wood as a material.
 *
 * The `Wood` class implements the `Material` interface, providing specific 
 * characteristics and behaviors associated with wood as a building material.
 */
class Wood : public Material {
public:
    /**
     * @brief Constructs a Wood object with default properties.
     */
    Wood();

    /**
     * @brief Destroys the Wood object.
     */
    ~Wood();

    /**
     * @brief Gets the production time required to create wood.
     * @return An integer representing the production time in minutes.
     */
    int getProductionTimeInMinutes();

    /**
     * @brief Gets the name of the material.
     * @return A string representing the name of the material (wood).
     */
    std::string getMaterialName();
};

#endif // WOOD_H
