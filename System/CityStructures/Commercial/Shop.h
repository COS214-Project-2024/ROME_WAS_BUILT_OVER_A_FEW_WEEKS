#ifndef SHOP_H
#define SHOP_H

#include "CommercialBuilding.h"
#include <string>

/**
 * @class Shop
 * @brief Represents a shop as a type of commercial building.
 *
 * The `Shop` class provides properties specific to a shop, such as cost and radius.
 * It inherits from `CommercialBuilding`.
 */
class Shop : public CommercialBuilding {
private:
    static const int DEFAULT_SHOP_COST = 5000;   /**< The default cost of constructing a shop. */
    static const int DEFAULT_SHOP_RADIUS = 2;    /**< The default radius of influence of a shop. */

public:
    /**
     * @brief Constructs a new `Shop` instance with default parameters.
     */
    Shop();

    /**
     * @brief Destroys the `Shop` instance.
     */
    ~Shop();

    /**
     * @brief Gets the type of commercial building as a string.
     * @return A string indicating the commercial building type, "Shop".
     */
    std::string getCommercialBuildingType();
};

#endif // SHOP_H
