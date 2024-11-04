#ifndef LOWSATISFACTIONHANDLER_H
#define LOWSATISFACTIONHANDLER_H

#include "SatisfactionHandler.h"

/**
 * @class LowSatisfactionHandler
 * @brief A class that manages population and tax adjustments for low satisfaction levels.
 * 
 * This handler is responsible for reducing the population by removing citizens through
 * death or emigration and adjusting the tax rate based on a lower income affection rate
 * when the satisfaction level is below 40.
 */
class LowSatisfactionHandler : public SatisfactionHandler {
    public:
        /**
         * @brief Constructor for LowSatisfactionHandler.
         * 
         * @param nextHandler Pointer to the next handler in the chain.
         */
        LowSatisfactionHandler(SatisfactionHandler* nextHandler);

        /**
         * @brief Adjusts the population of the city based on the current satisfaction level.
         * 
         * If the satisfaction is below 40, this method attempts to remove citizens
         * from the population through death or emigration methods.
         * 
         * @param curSatisfaction The current satisfaction level.
         * @param cityHall Pointer to the CityHall object for population operations.
         */
        void handlePopulation(int curSatisfaction, CityHall* cityHall);

        /**
         * @brief Adjusts the tax calculation for low satisfaction levels.
         * 
         * The method calculates a new tax rate based on a reduced income affection rate,
         * which is influenced by the current satisfaction level.
         * 
         * @param curSatisfaction The current satisfaction level.
         * @param cityHall Pointer to the CityHall object for tax rate retrieval.
         * @return Adjusted tax value.
         */
        float handleTax(int curSatisfaction, CityHall* cityHall);
};

#endif // LOWSATISFACTIONHANDLER_H
