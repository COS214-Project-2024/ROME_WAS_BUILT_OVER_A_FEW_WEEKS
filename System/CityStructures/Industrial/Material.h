#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

/**
 * @class Material
 * @brief Abstract base class for materials used in construction.
 *
 * The `Material` class defines the interface for all material types, 
 * specifying the production time and material name.
 */
class Material {
protected:
    int productionTimeInMinutes; ///< Production time for the material.

public:
    /**
     * @brief Gets the production time in minutes for the material.
     * @return An integer representing the production time in minutes.
     */
    virtual int getProductionTimeInMinutes() = 0;

    /**
     * @brief Gets the name of the material.
     * @return A string representing the material name.
     */
    virtual std::string getMaterialName() = 0;

    /**
     * @brief Destroys the Material object.
     */
    virtual ~Material() {};
};

#endif // MATERIAL_H
