#ifndef INDUSTRIAL_FACTORY_H
#define INDUSTRIAL_FACTORY_H

#include "../BuildingFactory.h"
#include "Plant.h"
#include "Warehouse.h"
#include "Factory.h"

/**
 * @class IndustrialFactory
 * @brief Abstract factory class for creating industrial buildings.
 *
 * The `IndustrialFactory` class defines the interface for factories that create
 * different types of industrial buildings, such as plants, warehouses, and factories.
 */
class IndustrialFactory : public BuildingFactory {
public:
    /**
     * @brief Creates an industrial building.
     * @return A pointer to the newly created `IndustrialBuilding`.
     */
    virtual IndustrialBuilding* createIndustrialBuilding() = 0;

    /**
     * @brief Destroys the IndustrialFactory object.
     */
    virtual ~IndustrialFactory() {};
};

/**
 * @class WarehouseFactory
 * @brief Factory class for creating warehouse buildings.
 *
 * The `WarehouseFactory` class overrides the `createIndustrialBuilding` method 
 * to provide implementation specific to creating warehouse buildings.
 */
class WarehouseFactory : public IndustrialFactory {
public:
    /**
     * @brief Creates a warehouse building.
     * @return A pointer to the newly created `IndustrialBuilding` (Warehouse).
     */
    virtual IndustrialBuilding* createIndustrialBuilding() override;
};

/**
 * @class FactoryFactory
 * @brief Factory class for creating factory buildings.
 *
 * The `FactoryFactory` class overrides the `createIndustrialBuilding` method 
 * to provide implementation specific to creating factory buildings.
 */
class FactoryFactory : public IndustrialFactory {
public:
    /**
     * @brief Creates a factory building.
     * @return A pointer to the newly created `IndustrialBuilding` (Factory).
     */
    virtual IndustrialBuilding* createIndustrialBuilding() override;
};

/**
 * @class PlantFactory
 * @brief Factory class for creating plant buildings.
 *
 * The `PlantFactory` class overrides the `createIndustrialBuilding` method 
 * to provide implementation specific to creating plant buildings.
 */
class PlantFactory : public IndustrialFactory {
public:
    /**
     * @brief Creates a plant building.
     * @return A pointer to the newly created `IndustrialBuilding` (Plant).
     */
    virtual IndustrialBuilding* createIndustrialBuilding() override;
};

#endif // INDUSTRIAL_FACTORY_H
