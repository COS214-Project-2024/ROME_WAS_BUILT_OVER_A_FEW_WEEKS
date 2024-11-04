#ifndef MALL_H
#define MALL_H

#include "CommercialBuilding.h"
#include <string>

/**
 * @class Mall
 * @brief Represents a mall as a type of commercial building.
 *
 * The `Mall` class provides properties specific to a mall, such as cost and radius.
 * It inherits from `CommercialBuilding`.
 */
class Mall : public CommercialBuilding {
private:
    static const int DEFAULT_MALL_COST = 20000; /**< The default cost of constructing a mall. */
    static const int DEFAULT_MALL_RADIUS = 10;  /**< The default radius of influence of a mall. */

public:
    /**
     * @brief Constructs a new `Mall` instance with default parameters.
     */
    Mall();

    /**
     * @brief Destroys the `Mall` instance.
     */
    ~Mall();

    /**
     * @brief Gets the type of commercial building as a string.
     * @return A string indicating the commercial building type, "Mall".
     */
    std::string getCommercialBuildingType();
};

#endif // MALL_H
