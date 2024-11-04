#ifndef RESIDENTIAL_FACTORY_H
#define RESIDENTIAL_FACTORY_H

#include "../BuildingFactory.h"
#include "House.h"
#include "Apartment.h"
#include "Estate.h"
#include "Townhouse.h"

/**
 * @class ResidentialFactory
 * @brief Abstract factory for creating residential buildings.
 *
 * The `ResidentialFactory` class provides an interface for creating various types 
 * of residential buildings, such as houses, apartments, estates, and townhouses.
 */
class ResidentialFactory : public BuildingFactory {
public:
    /**
     * @brief Creates a residential building.
     * @return A pointer to the created `ResidentialBuilding` object.
     */
    virtual ResidentialBuilding* createResidentialBuilding() = 0;

    /**
     * @brief Destroys the ResidentialFactory object.
     */
    virtual ~ResidentialFactory() {};
};

/**
 * @class HouseFactory
 * @brief Factory for creating houses.
 */
class HouseFactory : public ResidentialFactory {
public:
    /**
     * @brief Creates a house.
     * @return A pointer to the created `ResidentialBuilding` object.
     */
    virtual ResidentialBuilding* createResidentialBuilding() override;
};

/**
 * @class ApartmentFactory
 * @brief Factory for creating apartments.
 */
class ApartmentFactory : public ResidentialFactory {
public:
    /**
     * @brief Creates an apartment.
     * @return A pointer to the created `ResidentialBuilding` object.
     */
    virtual ResidentialBuilding* createResidentialBuilding() override;
};

/**
 * @class EstateFactory
 * @brief Factory for creating estates.
 */
class EstateFactory : public ResidentialFactory {
public:
    /**
     * @brief Creates an estate.
     * @return A pointer to the created `ResidentialBuilding` object.
     */
    virtual ResidentialBuilding* createResidentialBuilding() override;
};

/**
 * @class TownhouseFactory
 * @brief Factory for creating townhouses.
 */
class TownhouseFactory : public ResidentialFactory {
public:
    /**
     * @brief Creates a townhouse.
     * @return A pointer to the created `ResidentialBuilding` object.
     */
    virtual ResidentialBuilding* createResidentialBuilding() override;
};

#endif // RESIDENTIAL_FACTORY_H
