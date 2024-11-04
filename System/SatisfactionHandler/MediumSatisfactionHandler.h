#ifndef MEDIUMSATISFACTIONHANDLER_H
#define MEDIUMSATISFACTIONHANDLER_H

#include "SatisfactionHandler.h"

/**
 * @class MediumSatisfactionHandler
 * @brief Interface for handling medium satisfaction levels in the population.
 * 
 * This class extends the SatisfactionHandler to implement population and tax
 * handling specifically for medium satisfaction levels.
 */
class MediumSatisfactionHandler : public SatisfactionHandler {
    public:
        /**
         * @brief Constructor for MediumSatisfactionHandler.
         * 
         * Initializes the handler with the next handler in the chain and sets
         * default values for chanceOfPopulationChange and incomeAffectionRate.
         * 
         * @param nextHandler Pointer to the next SatisfactionHandler in the chain.
         */
        MediumSatisfactionHandler(SatisfactionHandler* nextHandler);

        /**
         * @brief Handles population changes based on current satisfaction levels.
         * 
         * The function modifies the population by executing births, immigration,
         * deaths, or emigration based on random chance and current satisfaction levels.
         * 
         * @param curSatisfaction The current satisfaction level of the population.
         * @param cityHall Pointer to the CityHall object for population management.
         */
        void handlePopulation(int curSatisfaction, CityHall* cityHall);

        /**
         * @brief Calculates the tax amount based on satisfaction and other parameters.
         * 
         * The method adjusts the income affection rate randomly and calculates the
         * tax based on the current tax rate and number of citizens.
         * 
         * @param curSatisfaction The current satisfaction level of the population.
         * @param cityHall Pointer to the CityHall object for tax rate retrieval.
         * @return The calculated tax amount.
         */
        float handleTax(int curSatisfaction, CityHall* cityHall);
};

#endif // MEDIUMSATISFACTIONHANDLER_H
