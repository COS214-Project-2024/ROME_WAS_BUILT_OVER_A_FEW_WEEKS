#ifndef LOWSATISFACTIONHANDLER_H
#define LOWSATISFACTIONHANDLER_H

#include "SatisfactionHandler.h"

/**
 * @class LowSatisfactionHandler
 * @brief Handles population and tax adjustments when satisfaction is low.
 */
class LowSatisfactionHandler : public SatisfactionHandler {
    public:
        /**
         * @brief Constructor for LowSatisfactionHandler.
         * @param nextHandler Pointer to the next handler in the chain.
         */
        LowSatisfactionHandler(SatisfactionHandler* nextHandler);

        /**
         * @brief Handles population changes based on current satisfaction.
         * @param curSatisfaction The current satisfaction level.
         * @param cityHall Pointer to the CityHall object.
         */
        void handlePopulation(int curSatisfaction, CityHall* cityHall);

        /**
         * @brief Handles tax calculations based on current satisfaction.
         * @param curSatisfaction The current satisfaction level.
         * @param cityHall Pointer to the CityHall object.
         * @return Adjusted tax amount.
         */
        float handleTax(int curSatisfaction, CityHall* cityHall);
};

#endif // LOWSATISFACTIONHANDLER_H
