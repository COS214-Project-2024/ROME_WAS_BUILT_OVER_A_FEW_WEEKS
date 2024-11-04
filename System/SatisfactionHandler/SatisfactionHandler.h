#ifndef SATISFACTIONHANDLER_H
#define SATISFACTIONHANDLER_H

class CityHall; // Forward declaration

/**
 * @class SatisfactionHandler
 * @brief Abstract base class for handling satisfaction-related operations.
 * 
 * This class defines the interface for handling population and tax adjustments
 * based on satisfaction levels. It includes methods to handle tax calculations
 * and population adjustments, allowing for chain-of-responsibility behavior.
 */
class SatisfactionHandler {
    protected:
        SatisfactionHandler *nextHandler; ///< Pointer to the next handler in the chain.

    public:
        /**
         * @brief Constructor for SatisfactionHandler.
         * Initializes the next handler pointer to nullptr.
         */
        SatisfactionHandler() : nextHandler(nullptr) {}

        /**
         * @brief Virtual destructor for proper cleanup of derived classes.
         */
        virtual ~SatisfactionHandler() {}

        /**
         * @brief Handles population adjustments based on current satisfaction levels.
         * 
         * This method can be overridden in derived classes to provide specific
         * population handling logic.
         * 
         * @param curSatisfaction The current satisfaction level of the population.
         * @param cityHall Pointer to the CityHall object for population management.
         */
        virtual void handlePopulation(int curSatisfaction, CityHall *cityHall);

        /**
         * @brief Calculates tax based on current satisfaction levels.
         * 
         * This method can be overridden in derived classes to provide specific
         * tax calculation logic.
         * 
         * @param curSatisfaction The current satisfaction level of the population.
         * @param cityHall Pointer to the CityHall object for tax rate retrieval.
         * @return The calculated tax amount.
         */
        virtual float handleTax(int curSatisfaction, CityHall *cityHall);

        /**
         * @brief Adds a next handler to the chain for processing satisfaction-related requests.
         * 
         * @param nextHandler Pointer to the next SatisfactionHandler in the chain.
         */
        void addHandler(SatisfactionHandler *nextHandler);
};

#endif // SATISFACTIONHANDLER_H
