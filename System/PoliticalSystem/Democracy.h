/**
 * @file Democracy.h
 * @brief Definition of the Democracy class.
 * 
 * This file declares the Democracy class, representing a democratic political system.
 */

#ifndef DEMOCRACY_H
#define DEMOCRACY_H
#include "PoliticalSystem.h"

/**
 * @class Democracy
 * @brief A political system model representing democracy.
 */
class Democracy : public PoliticalSystem {
public:
    /**
     * @brief Constructor for Democracy.
     */
    Democracy();

    /**
     * @brief Get the residential tax rate.
     * @return The tax rate for residential zones as an integer percentage.
     */
    virtual int getTaxRateResidential();

    /**
     * @brief Get the commercial tax rate.
     * @return The tax rate for commercial zones as an integer percentage.
     */
    virtual int getTaxRateCommercial();

    /**
     * @brief Get the industrial tax rate.
     * @return The tax rate for industrial zones as an integer percentage.
     */
    virtual int getTaxRateIndustrial();

    /**
     * @brief Get the budget split for public services.
     * @return The budget allocation proportion as a double.
     */
    virtual double getBudgetSplit();

    /**
     * @brief Get the impact on citizen satisfaction.
     * @return The calculated impact on citizen satisfaction as an integer.
     */
    virtual int getCitizenSatisfactionImpact();

    /**
     * @brief Destructor for Democracy.
     */
    ~Democracy();
};

#endif // DEMOCRACY_H
