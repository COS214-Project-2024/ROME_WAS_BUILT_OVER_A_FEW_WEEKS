/**
 * @file ResidentialBuilding.cpp
 * @brief Implementation of the ResidentialBuilding class.
 */

#include <iostream>
#include "CityMap.h"
#include "ResidentialBuilding.h"

/**
 * @brief Constructor for creating a ResidentialBuilding with a specified capacity.
 * @param capacity The capacity of the residential building.
 */
ResidentialBuilding::ResidentialBuilding(int capacity) : capacity(capacity) {
    // EMPTY.
}

/**
 * @brief Destructor for the ResidentialBuilding class.
 */
ResidentialBuilding::~ResidentialBuilding() {
    // EMPTY
}

/**
 * @brief Attempts to place a residential building on the given city map.
 * This function does not allow placing a residential building on its own, as it should be part of a residential complex.
 * @param x The x-coordinate where the structure should be placed.
 * @param y The y-coordinate where the structure should be placed.
 * @param cityMap Pointer to the CityMap where the structure is to be placed.
 */
void ResidentialBuilding::placeStructure(int x, int y, CityMap* cityMap) {
    std::cout << "You cannot place a residential building on its own" << std::endl;
}

/**
 * @brief Attempts to remove the residential building.
 * This function does not allow removing a residential building on its own.
 */
void ResidentialBuilding::removeStructure() {
    std::cout << "You cannot remove a residential building on its own" << std::endl;
}

/**
 * @brief Gets the capacity of the residential building.
 * @return The capacity of the residential building.
 */
int ResidentialBuilding::getCapacity() {
    return capacity;
}

/**
 * @brief Calculates and returns the capacity of the residential building.
 * @return The calculated capacity of the residential building.
 */
int ResidentialBuilding::calculateCapacity() {
    return capacity;
}

/**
 * @brief Creates a copy of the current ResidentialBuilding instance.
 * @return A pointer to a new ResidentialBuilding object that is a copy of this instance.
 */
ResidentialBuilding* ResidentialBuilding::clone() const {
    return new ResidentialBuilding(*this);
}
