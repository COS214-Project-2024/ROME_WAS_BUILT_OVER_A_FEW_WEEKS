#ifndef CONCRETE_H
#define CONCRETE_H

#include "Material.h"

/**
 * @class Concrete
 * @brief Represents concrete as a material.
 *
 * The `Concrete` class inherits from `Material` and provides methods 
 * to obtain production time and the material's name.
 */
class Concrete : public Material {
public:
    /**
     * @brief Constructs a Concrete object.
     */
    Concrete();

    /**
     * @brief Destroys the Concrete object.
     */
    ~Concrete();

    /**
     * @brief Gets the production time for concrete.
     * @return The production time in minutes.
     */
    int getProductionTimeInMinutes();

    /**
     * @brief Gets the name of the material.
     * @return A string representing the material's name.
     */
    std::string getMaterialName();
};

#endif // CONCRETE_H
