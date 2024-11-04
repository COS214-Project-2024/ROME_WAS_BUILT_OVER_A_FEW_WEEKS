#include "LowSatisfactionHandler.h"
#include <random>

/**
 * @brief Constructor for LowSatisfactionHandler.
 * Initializes the object with a pointer to the next handler and sets default values
 * for chance of population change and income affection rate.
 * 
 * @param nextHandler Pointer to the next handler in the chain of responsibility.
 */
LowSatisfactionHandler::LowSatisfactionHandler(SatisfactionHandler *nextHandler) {
    // Assign the next handler in the chain of responsibility.
    this->nextHandler = nextHandler;
    // Set the initial probability of population change.
    chanceOfPopulationChange = 0.05;
    // Set the initial income affection rate.
    incomeAffectionRate = 0.6;
}

/**
 * @brief Handles population adjustments when satisfaction is below 40.
 * 
 * If the satisfaction level is low, this method attempts to reduce the city's population
 * through death or emigration.
 * 
 * @param curSatisfaction The current satisfaction level of the city.
 * @param cityHall Pointer to the CityHall object for modifying population.
 */
void LowSatisfactionHandler::handlePopulation(int curSatisfaction, CityHall *cityHall) {
    // Check if satisfaction is below 40 and pass to the next handler if it is.
    if (curSatisfaction < 40) {
        if (nextHandler == NULL) {
            SatisfactionHandler::handlePopulation(curSatisfaction, cityHall);
            return;
        }
        nextHandler->handlePopulation(curSatisfaction, cityHall);
    }

    // Random number generators for population change logic.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random1(1, 100);
    std::uniform_int_distribution<> random2(1, 10);
    std::uniform_int_distribution<> random4(0, 1);

    // Generate a random number to decide if the population should change.
    float changePopulation = random1(gen) / 100.0;

    // Check if the generated number meets the threshold for changing the population.
    if (changePopulation <= chanceOfPopulationChange) {
        // Calculate the number of citizens to reduce.
        int numNewCitizenMultiplier = random2(gen) / 100;
        int numNewCitizens = cityHall->getNumCitizens() * numNewCitizenMultiplier;

        // Attempt to reduce the population via death or emigration.
        for (int i = 0; i < numNewCitizens; ) {
            bool doDeath = random4(gen);
            if (doDeath) {
                // Decrease population via death.
                cityHall->death();
            } else {
                // Decrease population via emigration.
                cityHall->emigrate();
            }
        }
    }
}

/**
 * @brief Adjusts the tax rate when satisfaction is below 40.
 * 
 * The method modifies the tax rate based on a lower income affection rate and
 * recalculates the tax amount accordingly.
 * 
 * @param curSatisfaction The current satisfaction level.
 * @param cityHall Pointer to the CityHall object to retrieve tax rate and population data.
 * @return The adjusted tax value.
 */
float LowSatisfactionHandler::handleTax(int curSatisfaction, CityHall *cityHall) {
