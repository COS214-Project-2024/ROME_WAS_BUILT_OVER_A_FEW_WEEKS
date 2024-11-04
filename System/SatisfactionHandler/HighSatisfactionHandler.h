#ifndef HIGHSATISFACTIONHANDLER_H
#define HIGHSATISFACTIONHANDLER_H

#include "SatisfactionHandler.h"

/**
 * @class HighSatisfactionHandler
 * @brief A class that handles population and tax adjustments when satisfaction levels are high.
 * 
 * This handler is responsible for adjusting the population by adding new citizens through
 * birth or immigration and modifying the tax rate based on income affection rate if the
 * satisfaction level is 80 or higher.
 */
class HighSatisfactionHandler : public SatisfactionHandler {
    public:
        /**
         * @brief Constructor for HighSatisfactionHandler.
         * 
         * @param nextHandler Pointer to the next handler in the chain.
         */
        HighSatisfactionHandler(SatisfactionHandler* nextHandler);

        /**
         * @brief Adjusts the population of the city based on the current satisfaction level.
         * 
         * If the satisfaction is 80 or higher, the method attempts to add new citizens
         * by calling birth or immigration methods.
         * 
         * @param curSatisfaction The current satisfaction level.
         * @param cityHall Pointer to the CityHall object for population operations.
         */
        void handlePopulation(int curSatisfaction, CityHall* cityHall);

        /**
         * @brief Adjusts the tax calculation for high satisfaction levels.
         * 
         * Calculates the new tax rate by applying a modified income affection rate and
         * multiplying it with the base tax rate and population count.
         * 
         * @param curSatisfaction The current satisfaction level.
         * @param cityHall Pointer to the CityHall object for tax rate retrieval.
         * @return Adjusted tax value.
         */
        float handleTax(int curSatisfaction, CityHall* cityHall);
};

#endif // HIGHSATISFACTIONHANDLER_H
