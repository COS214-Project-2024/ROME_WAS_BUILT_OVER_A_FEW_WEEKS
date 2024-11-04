/**
 * @file ResidentialComplex.cpp
 * @brief Implementation of the ResidentialComplex class.
 */

#include <iostream>
#include <vector>

#include "CityMap.h"
#include "ResidentialComponent.h"
#include "ResidentialComplex.h"

/**
 * @brief Constructs a ResidentialComplex with an initial residential component.
 * @param residential A pointer to the initial ResidentialComponent to add.
 */
ResidentialComplex::ResidentialComplex(ResidentialComponent* residential) {
    addResidentialComponent(residential);
    satisfaction = 100;
    capacity = residential->calculateCapacity();
}

/**
 * @brief Places the residential complex on the city map.
 * @param x The x-coordinate for the placement.
 * @param y The y-coordinate for the placement.
 * @param cityMap A pointer to the CityMap where the complex is to be placed.
 */
void ResidentialComplex::placeStructure(int x, int y, CityMap* cityMap) {
    CityStructure::placeStructure(x, y, cityMap);
    cityMap->addBuilding(this);
}

/**
 * @brief Removes the residential complex from the city map.
 */
void ResidentialComplex::removeStructure() {
    cityMap->removeStructure(x, y);
}

/**
 * @brief Destructor for the ResidentialComplex.
 * 
 * Cleans up the dynamically allocated residential components.
 */
ResidentialComplex::~ResidentialComplex() {
    std::vector<ResidentialComponent*>::iterator it;
    for (it = residentialComponents.begin(); it != residentialComponents.end(); it++) {
        delete *it;
    }
}

/**
 * @brief Called when a new road is added near the complex.
 * 
 * Updates the traffic satisfaction and overall satisfaction.
 */
void ResidentialComplex::newRoadWasAdded() {
    calculateTrafficSatisfaction();
    calculateSatisfaction();
}

/**
 * @brief Called when a new commercial building is added near the complex.
 * 
 * Updates employment satisfaction and recalculates overall satisfaction.
 */
void ResidentialComplex::newCommercialBuildingWasAdded() {
    EmploymentSatisfaction += 1;
    calculateSatisfaction();
}

/**
 * @brief Called when a new industrial building is added near the complex.
 * 
 * Updates employment satisfaction and recalculates overall satisfaction.
 */
void ResidentialComplex::newIndustrialBuildingWasAdded() {
    EmploymentSatisfaction += 1;
    calculateSatisfaction();
}

/**
 * @brief Called when a new landmark is added near the complex.
 * 
 * Increases overall satisfaction.
 */
void ResidentialComplex::newLandmarkWasAdded() {
    satisfaction += 1;
}

/**
 * @brief Gets the total capacity of the residential complex.
 * @return The total capacity.
 */
int ResidentialComplex::getCapacity() {
    return capacity;
}

/**
 * @brief Adds a residential component to the complex.
 * @param residential A pointer to the ResidentialComponent to add.
 */
void ResidentialComplex::addResidentialComponent(ResidentialComponent* residential) {
    residentialComponents.push_back(residential);
    calculateCapacity();
}

/**
 * @brief Calculates the total capacity of the residential complex.
 * @return The total calculated capacity
 */
int ResidentialComplex::calculateCapacity() {
    int totalCapacity = 0;
    for (ResidentialComponent* component : residentialComponents) {
        totalCapacity += component->calculateCapacity();
    }
    this->capacity = totalCapacity;
    return totalCapacity;
}

/**
 * @brief Calculates the traffic satisfaction for the complex based on nearby roads.
 * @return The calculated traffic satisfaction value.
 */
int ResidentialComplex::calculateTrafficSatisfaction() {
    // Implementation logic for calculating traffic satisfaction based on roads
    int newTrafficSatisfaction = 0;
    // Add logic to check nearby roads and update satisfaction
    trafficSatisfaction = newTrafficSatisfaction;
    return trafficSatisfaction;
}

/**
 * @brief Calculates the overall satisfaction of the residential complex.
 * @return The calculated overall satisfaction value.
 */
int ResidentialComplex::calculateSatisfaction() {
    satisfaction = trafficSatisfaction + EmploymentSatisfaction + PowerSatisfaction + WaterSatisfaction + WasteSatisfaction + SewageSatisfaction + HealthSatisfaction + EducationSatisfaction + safetySatisfaction;
    return satisfaction;
}

/**
 * @brief Clones the current ResidentialComplex object.
 * 
 * Creates a deep copy of the current object, including all components and satisfaction values.
 * 
 * @return A pointer to the cloned ResidentialComplex object.
 */
ResidentialComplex* ResidentialComplex::clone() const {
    ResidentialComplex* newComplex = new ResidentialComplex();
    newComplex->trafficSatisfaction = this->trafficSatisfaction;
    newComplex->employmentSatisfaction = this->employmentSatisfaction;
    newComplex->powerSatisfaction = this->powerSatisfaction;
    newComplex->waterSatisfaction = this->waterSatisfaction;
    newComplex->wasteSatisfaction = this->wasteSatisfaction;
    newComplex->sewageSatisfaction = this->sewageSatisfaction;
    newComplex->healthSatisfaction = this->healthSatisfaction;
    newComplex->educationSatisfaction = this->educationSatisfaction;
    newComplex->safetySatisfaction = this->safetySatisfaction;
    newComplex->satisfaction = this->satisfaction;
    newComplex->capacity = this->capacity;

    for (const ResidentialComponent* component : residentialComponents) {
        newComplex->addResidentialComponent(component->clone());
    }

    return newComplex;
}
