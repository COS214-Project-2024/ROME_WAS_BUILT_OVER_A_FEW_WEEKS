#ifndef BOOSTER_STRUCTURES_H
#define BOOSTER_STRUCTURES_H

/**
 * @class BoosterStructures
 * @brief Base class for structures that provide a boost effect in the simulation.
 *
 * BoosterStructures serves as a base class for structures like airports and railways
 * that enhance or affect the satisfaction levels of nearby areas or buildings.
 */
class BoosterStructures {
protected:
    int level;                    /**< The boost level of the structure */
    float satisfactionMultiplier; /**< Multiplier affecting satisfaction in nearby areas */

public:
    /**
     * @brief Gets the boost level of the structure.
     * @return The current boost level.
     */
    int getLevel();

    /**
     * @brief Gets the satisfaction multiplier provided by the structure.
     * @return The satisfaction multiplier as a floating-point value.
     */
    float getSatisfactionMultiplier();
};

#endif // BOOSTER_STRUCTURES_H
