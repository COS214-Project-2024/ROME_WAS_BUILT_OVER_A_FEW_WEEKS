#ifndef RESIDENTIAL_COMPLEX_H
#define RESIDENTIAL_COMPLEX_H

#include <vector>
#include "ResidentialComponent.h"

/**
 * @class ResidentialComplex
 * @brief Represents a complex of residential buildings.
 *
 * The `ResidentialComplex` class inherits from `ResidentialComponent` and manages 
 * multiple residential components, calculating overall satisfaction and capacity.
 */
class ResidentialComplex : public ResidentialComponent {
private:
    std::vector<ResidentialComponent*> residentialComponents; ///< Collection of residential components in the complex.

    // Satisfaction levels for various factors
    float trafficSatisfaction; ///< Traffic satisfaction level.
    float EmploymentSatisfaction; ///< Employment satisfaction level.
    float PowerSatisfaction; ///< Power satisfaction level.
    float WaterSatisfaction; ///< Water satisfaction level.
    float WasteSatisfaction; ///< Waste satisfaction level.
    float SewageSatisfaction; ///< Sewage satisfaction level.
    float HealthSatisfaction; ///< Health satisfaction level.
    float EducationSatisfaction; ///< Education satisfaction level.
    float safetySatisfaction; ///< Safety satisfaction level.
    float bonusSatisfaction; ///< Additional satisfaction bonuses.

    float satisfaction; ///< Total satisfaction of the complex.
    int capacity; ///< Capacity of the residential complex.
public:
    /**
     * @brief Constructs a ResidentialComplex object with an initial residential component.
     * @param residential Pointer to a `ResidentialComponent` to be included in the complex.
     */
    ResidentialComplex(ResidentialComponent* residential);

    /**
     * @brief Destroys the ResidentialComplex object.
     */
    ~ResidentialComplex();

    /**
     * @brief Gets the type of the structure.
     * @return A string representing the structure type.
     */
    std::string getStructureType() override;

    /**
     * @brief Places the structure in the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    bool placeStructure(int x, int y, CityMap* cityMap) override;

    /**
     * @brief Updates the complex when a new road is added.
     */
    void newRoadWasAdded();

    /**
     * @brief Updates the complex when a new commercial building is added.
     */
    void newCommercialBuildingWasAdded();

    /**
     * @brief Updates the complex when a new power plant is added.
     */
    void newPowerPlantWasAdded();

    /**
     * @brief Updates the complex when a new water plant is added.
     */
    void newWaterPlantWasAdded();

    /**
     * @brief Updates the complex when a new waste plant is added.
     */
    void newWastePlantWasAdded();

    /**
     * @brief Updates the complex when a new sewage plant is added.
     */
    void newSewagePlantWasAdded();

    /**
     * @brief Updates the complex when a new landmark is added.
     */
    void newLandmarkWasAdded();

    /**
     * @brief Removes the structure.
     * @return True if the structure is successfully removed, false otherwise.
     */
    bool removeStructure() override;

    /**
     * @brief Updates the complex when a road is removed.
     */
    void roadWasRemoved();

    /**
     * @brief Updates the complex when a commercial building is removed.
     */
    void commercialBuildingWasRemoved();

    /**
     * @brief Updates the complex when a power plant is removed.
     */
    void powerPlantWasRemoved();

    /**
     * @brief Updates the complex when a water plant is removed.
     */
    void waterPlantWasRemoved();

    /**
     * @brief Updates the complex when a waste plant is removed.
     */
    void wastePlantWasRemoved();

    /**
     * @brief Updates the complex when a sewage plant is removed.
     */
    void sewagePlantWasRemoved();

    /**
     * @brief Updates the complex when a landmark is removed.
     */
    void landmarkWasRemoved();

    /**
     * @brief Retrieves the capacity of the residential complex.
     * @return An integer representing the complex's capacity.
     */
    int getCapacity() override; // Retrieves the member variable capacity instead of recalculating it.

    /**
     * @brief Adds a residential component to the complex.
     * @param residential Pointer to the `ResidentialComponent` to add.
     * @param cityMap Pointer to the `CityMap` object where the component will be placed.
     */
    void addResidentialComponent(ResidentialComponent* residential, CityMap* cityMap);

    /**
     * @brief Removes a residential component from the complex.
     * @param residential Pointer to the `ResidentialComponent` to remove.
     */
    void removeResidentialComponent(ResidentialComponent* residential);

    /**
     * @brief Calculates the total capacity of the residential complex.
     * @return An integer representing the calculated capacity.
     */
    int calculateCapacity() override;

    /**
     * @brief Gets the cost of the residential complex.
     * @return An integer representing the cost.
     */
    int getCost() override;

    /**
     * @brief Calculates the traffic satisfaction level of the complex.
     * @return An integer representing the traffic satisfaction.
     */
    int calculateTrafficSatisfaction();

    /**
     * @brief Calculates the total satisfaction of the complex.
     * @return An integer representing the total satisfaction.
     */
    int calculateSatisfaction();

    /**
     * @brief Prints the current state of the residential complex.
     */
    void printResidentialComplexState();

    /**
     * @brief Clones the residential complex.
     * @return A pointer to a cloned `ResidentialComponent`.
     */
    ResidentialComponent* clone() const override;
};

#endif // RESIDENTIAL_COMPLEX_H
