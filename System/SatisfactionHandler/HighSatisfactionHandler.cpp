#include "HighSatisfactionHandler.h"
#include <random>

/**
 * @brief Constructor for HighSatisfactionHandler.
 * Initializes the object with a pointer to the next handler and sets the default
 * values for the chance of population change and income affection rate.
 * 
 * @param nextHandler Pointer to the next handler in the chain of responsibility.
 */
HighSatisfactionHandler::HighSatisfactionHandler(SatisfactionHandler *nextHandler) {
    // Assign the next handler in the chain of responsibility.
    this->nextHandler = nextHandler;
    // Set the initial probability of population change.
    chanceOfPopulationChange = 0.1;
    // Set the initial rate of how income affects tax calculation.
    incomeAffectionRate = 1;
}

/**
 * @brief Handles population adjustments based on high satisfaction levels.
 * 
 * This method only triggers if the satisfaction level is 80 or higher.
 * It potentially adds new citizens through birth or immigration.
 * 
 * @param curSatisfaction The current satisfaction level of the city. Determines if this handler acts.
 * @param cityHall Pointer to the CityHall object, which holds data about the city's population.
 */
void HighSatisfactionHandler::handlePopulation(int curSatisfaction, CityHall* cityHall) {
    // Check if the current satisfaction is below 80, and pass to the next handler if so.
    if (curSatisfaction < 80) {
        // If there is no next handler, call the base class method.
        if (nextHandler == NULL) {
            SatisfactionHandler::handlePopulation(curSatisfaction, cityHall);
            return;
        }
        // Delegate handling to the next handler in the chain.
        nextHandler->handlePopulation(curSatisfaction, cityHall);
    }

    // Create random number generators for decision-making processes.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random1(1, 100);
    std::uniform_int_distribution<> random2(1, 10);
    std::uniform_int_distribution<> random4(0, 1);

    // Generate a random number for determining if population should change.
    float changePopulation = random1(gen) / 100.0;

    // Check if the generated number is within the chance of triggering a population change.
    if (changePopulation <= chanceOfPopulationChange) {
        // Calculate the number of new citizens to potentially add.
        int numNewCitizenMultiplier = random2(gen) / 100;
        int numNewCitizens = cityHall->getNumCitizens() * numNewCitizenMultiplier;

        // Attempt to add new citizens via birth or immigration.
        for (int i = 0; i < numNewCitizens; ) {
            bool doBirth = random4(gen);
            if (doBirth) {
                // Increase population via birth.
                cityHall->birth();
            } else {
                // Increase population via immigration.
                cityHall->immigrate();
            }
        }
    }
}

/**
 * @brief Adjusts the tax rate based on high satisfaction levels.
 * 
 * This method only triggers if the satisfaction level is 80 or higher.
 * It calculates a new tax based on the income affection rate and modifies it randomly.
 * 
 * @param curSatisfaction The current satisfaction level of the city.
 * @param cityHall Pointer to the CityHall object for retrieving the current tax rate and population.
 * @return The adjusted tax amount, which is influenced by the current satisfaction.
 */
float HighSatisfactionHandler::handleTax(int curSatisfaction, CityHall* cityHall) {
    // Check if the current satisfaction is below 80, and pass to the next handler if so.
    if (curSatisfaction < 80) {
        if (nextHandler == NULL) {
            return SatisfactionHandler::handleTax(curSatisfaction, cityHall);
        }
        return nextHandler->handleTax(curSatisfaction, cityHall);
    }

    // Create a random generator for adjusting the income affection rate.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random1(-10, 10);

    // Adjust the income affection rate by a small random amount.
    incomeAffectionRate += random1(gen) / 100.0;
    
    // Calculate the final tax based on the adjusted income affection rate.
    return incomeAffectionRate * cityHall->getTaxRateResidential() * cityHall->getNumCitizens();
}
