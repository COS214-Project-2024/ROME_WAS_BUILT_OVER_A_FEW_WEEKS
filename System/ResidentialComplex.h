/**
 * @file ResidentialComplex.h
 * @brief Header file for the ResidentialComplex class.
 */

#ifndef RESIDENTIAL_COMPLEX_H 
#define RESIDENTIAL_COMPLEX_H

#include <vector>
#include "ResidentialComponent.h"

/**
 * @class ResidentialComplex
 * @brief A class representing a complex composed of multiple residential components.
 * 
 * The ResidentialComplex class aggregates different residential components, 
 * calculates their total capacity, and evaluates various satisfaction levels 
 * based on different factors such as traffic and nearby buildings.
 */
class ResidentialComplex : public ResidentialComponent {
private:
    std::vector<ResidentialComponent*> residentialComponents; /**< A list of residential components in the complex. */

    int trafficSatisfaction; /**< Satisfaction due to traffic conditions. */
    int EmploymentSatisfaction; /**< Satisfaction based on employment opportunities. */
    int PowerSatisfaction; /**< Satisfaction due to power availability. */
    int WaterSatisfaction; /**< Satisfaction due to water availability. */
    int WasteSatisfaction; /**< Satisfaction related to waste management. */
    int SewageSatisfaction; /**< Satisfaction related to sewage systems. */
    int HealthSatisfaction; /**< Satisfaction due to healthcare facilities. */
    int EducationSatisfaction; /**< Satisfaction due to educational facilities. */
    int safetySatisfaction; /**< Satisfaction due to safety and security. */

    int satisfaction; /**< The total satisfaction of the complex. */
    int capacity; /**< The total capacity of the complex. */

public:
    /**
     * @brief Constructs a ResidentialComplex with an initial residential component.
     * @param residential A pointer to the initial ResidentialComponent to be added.
     */
    ResidentialComplex(ResidentialComponent* residential);

    /**
     * @brief Places the residential complex on the city map.
     * @param x The x-coordinate for the placement.
     * @param y The y-coordinate for the placement.
     * @param cityMap A pointer to the CityMap where the complex is placed.
     */
    void placeStructure(int x, int y, CityMap* cityMap) override;

    /**
     * @brief Removes the residential complex from the city map.
     */
    void removeStructure() override;

    /**
     * @brief Destructor for ResidentialComplex.
     * 
     * Cleans up all dynamically allocated residential components.
     */
    ~ResidentialComplex();

    /**
     * @brief Called when a new road is added near the complex.
     * 
     * Updates the traffic satisfaction and recalculates the overall satisfaction.
     */
    void newRoadWasAdded();

    /**
     * @brief Called when a new commercial building is added near the complex.
     * 
     * Increases employment satisfaction and recalculates overall satisfaction.
     */
    void newCommercialBuildingWasAdded();

    /**
     * @brief Called when a new industrial building is added near the complex.
     * 
     * Increases employment satisfaction and recalculates overall satisfaction.
     */
    void newIndustrialBuildingWasAdded();

    /**
     * @brief Called when a new landmark is added near the complex.
     * 
     * Increases the overall satisfaction of the complex.
     */
    void newLandmarkWasAdded();

    /**
     * @brief Retrieves the current capacity of the complex.
     * @return The capacity of the complex.
     */
    int getCapacity() override;

    /**
     * @brief Adds a new residential component to the complex
     * @param residential A pointer to the ResidentialComponent to be added.
     */
    void addResidentialComponent(ResidentialComponent* residential);

    /**
     * @brief Calculates and updates the total capacity of the complex.
     * @return The total calculated capacity of the complex.
     */
    int calculateCapacity() override;

    /**
     * @brief Calculates traffic satisfaction based on nearby roads.
     * @return The calculated traffic satisfaction value.
     */
    int calculateTrafficSatisfaction();

    /**
     * @brief Calculates and updates the total satisfaction of the complex.
     * @return The calculated satisfaction value.
     */
    int calculateSatisfaction();

    /**
     * @brief Creates a deep copy of the current ResidentialComplex.
     * 
     * This method implements the Prototype pattern to clone the complex and its components.
     * 
     * @return A pointer to the newly cloned ResidentialComplex.
     */
    ResidentialComponent* clone() const override;
};

#endif // RESIDENTIAL_COMPLEX_H
