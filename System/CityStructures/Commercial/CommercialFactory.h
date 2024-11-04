#ifndef COMMERCIAL_FACTORY_H
#define COMMERCIAL_FACTORY_H

#include "../BuildingFactory.h"
#include "Shop.h"
#include "Office.h"
#include "Mall.h"

/**
 * @class CommercialFactory
 * @brief Abstract factory class for creating commercial buildings.
 *
 * The `CommercialFactory` class defines an interface for creating `CommercialBuilding` objects.
 * Derived classes implement the `createCommercialBuilding` method to create specific types
 * of commercial buildings.
 */
class CommercialFactory : public BuildingFactory {
public: 
    /**
     * @brief Creates a commercial building.
     * @return A pointer to a `CommercialBuilding` object.
     *
     * This is a pure virtual function that must be implemented by derived classes to
     * create specific types of commercial buildings.
     */
    virtual CommercialBuilding* createCommercialBuilding() = 0;

    /**
     * @brief Virtual destructor for `CommercialFactory`.
     */
    virtual ~CommercialFactory() {};
};

/**
 * @class ShopFactory
 * @brief Factory class for creating `Shop` buildings.
 *
 * The `ShopFactory` class implements the `CommercialFactory` interface to create `Shop` buildings.
 */
class ShopFactory : public CommercialFactory {
public:
    /**
     * @brief Creates a `Shop` building.
     * @return A pointer to a `Shop` building as a `CommercialBuilding` object.
     */
    virtual CommercialBuilding* createCommercialBuilding() override;
};

/**
 * @class OfficeFactory
 * @brief Factory class for creating `Office` buildings.
 *
 * The `OfficeFactory` class implements the `CommercialFactory` interface to create `Office` buildings.
 */
class OfficeFactory : public CommercialFactory {
public:
    /**
     * @brief Creates an `Office` building.
     * @return A pointer to an `Office` building as a `CommercialBuilding` object.
     */
    virtual CommercialBuilding* createCommercialBuilding() override;
};

/**
 * @class MallFactory
 * @brief Factory class for creating `Mall` buildings.
 *
 * The `MallFactory` class implements the `CommercialFactory` interface to create `Mall` buildings.
 */
class MallFactory : public CommercialFactory {
public:
    /**
     * @brief Creates a `Mall` building.
     * @return A pointer to a `Mall` building as a `CommercialBuilding` object.
     */
    virtual CommercialBuilding* createCommercialBuilding() override;
};

#endif // COMMERCIAL_FACTORY_H
