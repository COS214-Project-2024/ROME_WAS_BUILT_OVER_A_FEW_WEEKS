#include "MediumSatisfactionHandler.h"
#include <random>

/**
 * @class MediumSatisfactionHandler
 * @brief Handles population and tax adjustments for medium satisfaction levels.
 * 
 * This class is responsible for managing changes in the population and tax rates
 * when the satisfaction level is between 60 and 80. It employs randomness to determine
 * the frequency and type of population changes, such as births, deaths, immigration, and emigration.
 */

/**
 * @brief Constructor for MediumSatisfactionHandler.
 * 
 * Initializes the handler with a pointer to the next handler in the chain and
 * sets default values for chanceOfPopulationChange and incomeAffectionRate.
 * 
 * @param nextHandler Pointer to the next SatisfactionHandler in the chain.
 */
MediumSatisfactionHandler::MediumSatisfactionHandler(SatisfactionHandler *nextHandler) {
    this->nextHandler = nextHandler; ///< Assign the next handler for processing.
    chanceOfPopulationChange = 0.05; ///< Default chance of population change (5%).
    incomeAffectionRate = 0.8; ///< Default income affection rate (80%).
}

/**
 * @brief Handles population adjustments based on current satisfaction levels.
 * 
 * If satisfaction is lower than 60, this method passes the request to the next handler
 * in the chain. Otherwise, it randomly determines if the population should change
 * and performs the corresponding actions (birth, immigration, death, emigration).
 * 
 * @param curSatisfaction The current satisfaction level of the population.
 * @param cityHall Pointer to the CityHall object for population management.
 */
void MediumSatisfactionHandler::handlePopulation(int curSatisfaction, CityHall *cityHall) {
    // Pass the request down the chain if satisfaction is lower than 60
    if (curSatisfaction < 60) {
        if (nextHandler == NULL) {
            SatisfactionHandler::handlePopulation(curSatisfaction, cityHall);
            return; // No further handler, exit the function.
        }
        nextHandler->handlePopulation(curSatisfaction, cityHall); // Delegate to the next handler.
    }

    // Random number generation for determining population changes
    std::random_device rd; // Random device for entropy
    std::mt19937 gen(rd()); // Mersenne Twister random number generator
    std::uniform_int_distribution<> random1(1, 100); // Distribution for random population change check
    std::uniform_int_distribution<> random2(1, 10); // Distribution for number of new citizens
    std::uniform_int_distribution<> random3(-10, 10); // Distribution for income affection adjustment
    std::uniform_int_distribution<> random4(0, 1); // Distribution for decision-making (leave or stay)

    float changePopulation = random1(gen) / 100; // Generate a random change value between 0 and 1

    // Check if the random number is below the chance of population change
    if (changePopulation <= chanceOfPopulationChange) {
        int numNewCitizenMultiplier = random2(gen) / 100; // Generate a multiplier for new citizens
        int numNewCitizens = cityHall->getNumCitizens() * numNewCitizenMultiplier; // Calculate new citizens

        // Adjust the population based on random events
        for (int i = 0; i < numNewCitizens;) {
            bool doLeave = random4(gen); // Decide if a citizen leaves

            if (doLeave) {
                bool doBirth = random4(gen); // Decide if there is a birth or immigration
                if (doBirth) {
                    cityHall->birth(); // Execute a birth event
                } else {
                    cityHall->immigrate(); // Execute an immigration event
                }
            } else {
                bool doDeath = random4(gen); // Decide if a citizen dies or emigrates
                if (doDeath) {
                    cityHall->death(); // Execute a death event
                } else {
                    cityHall->emigrate(); // Execute an emigration event
                }
            }
        }
    }
}

/**
 * @brief Handles tax calculations based on current satisfaction levels.
 * 
 * If the satisfaction level is lower than 60, the tax calculation request is passed to the next handler.
 * Otherwise, it randomly adjusts the income affection rate and calculates the tax based on the residential
 * tax rate and the number of citizens.
 * 
 * @param curSatisfaction The current satisfaction level of the population.
 * @param cityHall Pointer to the CityHall object for tax rate retrieval.
 * @return The calculated tax amount based on the adjusted income affection rate.
 */
float MediumSatisfactionHandler::handleTax(int curSatisfaction, CityHall *cityHall) {
    // If satisfaction is below 60, delegate the tax calculation to the next handler
    if (curSatisfaction < 60) {
        if (nextHandler == NULL) {
            return SatisfactionHandler::handleTax(curSatisfaction, cityHall);
        }
        return nextHandler->handleTax(curSatisfaction, cityHall); // Delegate to the next handler.
    }

    // Random number generation for adjusting income affection rate
    std::random_device rd; // Random device for entropy
    std::mt19937 gen(rd()); // Mersenne Twister random number generator
    std::uniform_int_distribution<> random1(-10, 10); // Distribution for random adjustment of income affection rate

    // Adjust the income affection rate randomly
    incomeAffectionRate += random1(gen) / 100; // Apply the random adjustment

    // Calculate and return the adjusted tax amount
    return incomeAffectionRate * cityHall->getTaxRateResidential() * cityHall->getNumCitizens();
}
