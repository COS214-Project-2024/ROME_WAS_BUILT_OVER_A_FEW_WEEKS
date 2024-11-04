#ifndef OFFICE_H
#define OFFICE_H

#include "CommercialBuilding.h"
#include <string>

/**
 * @class Office
 * @brief Represents an office as a type of commercial building.
 *
 * The `Office` class provides properties specific to an office, such as cost and radius.
 * It inherits from `CommercialBuilding`.
 */
class Office : public CommercialBuilding {
private:
    static const int DEFAULT_OFFICE_COST = 10000; /**< The default cost of constructing an office. */
    static const int DEFAULT_OFFICE_RADIUS = 4;   /**< The default radius of influence of an office. */

public:
    /**
     * @brief Constructs a new `Office` instance with default parameters.
     */
    Office();

    /**
     * @brief Destroys the `Office` instance.
     */
    ~Office();

    /**
     * @brief Gets the type of commercial building as a string.
     * @return A string indicating the commercial building type, "Office".
     */
    std::string getCommercialBuildingType();
};

#endif // OFFICE_H
