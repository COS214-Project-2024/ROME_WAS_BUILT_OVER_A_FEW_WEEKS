#ifndef CITYHALL_H
#define CITYHALL_H

#include "CityStructures/CityStructure.h"

class SatisfactionHandler;
class PoliticalSystem;
class CityMap;
class Railway;
class Airport;
class School;
class Hospital;
class PoliceStation;

/**
 * @class CityHall
 * @brief Singleton class representing the central management structure of the city.
 * 
 * The CityHall handles various city operations including resource management,
 * population tracking, satisfaction calculation, and tax collection.
 */
class CityHall: public CityStructure {
private:
    static CityHall* cityHall; ///< Singleton instance of CityHall.
    SatisfactionHandler* chainOfResponsibility; ///< Chain of responsibility for handling satisfaction-related processes.
    PoliticalSystem* politicalSystem; ///< Pointer to the current political system of the city.
    Railway* railway; ///< Pointer to the railway system in the city.
    Airport* airport; ///< Pointer to the airport in the city.
    School* school; ///< Pointer to the school in the city.
    Hospital* hospital; ///< Pointer to the hospital in the city.
    PoliceStation* policeStation; ///< Pointer to the police station in the city.

    int numCitizens; ///< Total number of citizens in the city.
    int cityCapacity; ///< Maximum population capacity of the city.
    int numResidentialComplexes; ///< Number of residential complexes in the city.
    int numCommercialBuildings; ///< Number of commercial buildings in the city.
    int numIndustrialBuildings; ///< Number of industrial buildings in the city.
    int numFactories; ///< Number of factories in the city.
    int popeCoins; ///< Amount of pope coins available.
    int wood; ///< Amount of wood resources available.
    int steel; ///< Amount of steel resources available.
    int concrete; ///< Amount of concrete resources available.
    int maxWood; ///< Maximum wood storage capacity.
    int maxSteel; ///< Maximum steel storage capacity.
    int maxConcrete; ///< Maximum concrete storage capacity.
    static const int MAX_POPE_COINS = 1000000; ///< Maximum limit for pope coins.

    float residentialSatisfaction; ///< Current satisfaction level of residential areas.
    float citySatisfaction; ///< Overall satisfaction level of the city.

    int taxRateResidential; ///< Tax rate for residential buildings.
    int taxRateCommercial; ///< Tax rate for commercial buildings.
    int taxRateIndustrial; ///< Tax rate for industrial buildings.
    double budgetSplit; ///< Budget allocation percentage for user management.
    int citizenSatisfactionImpact; ///< Impact of satisfaction on citizens.

protected:
    /**
     * @brief Protected constructor for the CityHall singleton.
     */
    CityHall();

public:
    /**
     * @brief Retrieves the singleton instance of CityHall.
     * @return Pointer to the singleton instance.
     */
    static CityHall* getInstance();

    // Member function documentation is provided below:
    void setPoliticalSystem(PoliticalSystem* politicalSystem);
    void birth();
    void death();
    void emigrate();
    void immigrate();
    int getNumCitizens();
    int getCityCapacity();
    int getNumResidentialBuildings();
    std::string getStructureType();
    int getCost();

    /**
     * @brief Gets the current satisfaction level of the city.
     * @return Current satisfaction level.
     */
    int getCurrSatisfaction();

    /**
     * @brief Calculates and updates the overall satisfaction of the city.
     * @return Updated satisfaction level as a float.
     */
    float calculateSatisfaction();

    void calculateResidentialSatisfaction(float oldSatisfaction, float newSatisfaction);
    float getRailwayBonus();
    float getAirportBonus();
    float getSchoolBonus();
    float getHospitalBonus();
    float getPoliceStationBonus();
    float calculateHomelessnessDeduction();
    void populationChange(int satisfactionLevel);
    float collectTaxes(int satisfactionLevel);

    int getTaxRateResidential();
    int getTaxRateCommercial();
    int getTaxRateIndustrial();
    double getBudgetSplit();
    int getCitizenSatisfactionImpact();
    ~CityHall();

    // Resource management methods:
    bool placeStructure(int x, int y, CityMap* cityMap);
    bool removeStructure();
    void increaseStorageCapacity();
    void decreaseStorageCapacity();
    void increaseNumResidentialComplexes();
    void decreaseNumResidentialComplexes();
    void increaseNumCommercialBuildings();
    void decreaseNumCommercialBuildings();
    void increaseNumIndustrialBuildings();
    void decreaseNumIndustrialBuildings();
    void increaseNumFactories();
    void decreaseNumFactories();
    int getNumFactories();
    void generateWood(int generatedAmount);
    void generateSteel(int generatedAmount);
    void generateConcrete(int generatedAmount);

    // Financial methods:
    bool addPopeCoins(int coins);
    bool deductPopeCoins(int coins);
    bool addWood(int wood);
    bool deductWood(int wood);
    bool addSteel(int steel);
    bool deductSteel(int steel);
    bool addConcrete(int concrete);
    bool deductConcrete(int concrete);

    // Capacity adjustment:
    int getStorageCapacity();
    void increaseCapacity(int capacity);
    void decreaseCapacity(int capacity);

    /**
     * @brief Prints the current state of the CityHall.
     */
    void printCityHallState();
};

#endif
