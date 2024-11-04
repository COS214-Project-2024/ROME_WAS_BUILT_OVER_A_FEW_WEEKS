/**
 * @file Authoritarianism.h
 * @brief Definition of the Authoritarianism class.
 * 
 * This file declares the Authoritarianism class, which inherits from the 
 * PoliticalSystem base class and defines specific economic and social policies.
 */

#ifndef AUTHORITARIANISM_H
#define AUTHORITARIANISM_H

#include "PoliticalSystem.h"

/**
 * @class Authoritarianism
 * @brief A political system model representing an authoritarian regime.
 * 
 * This class provides implementations for tax rates, budget distribution, 
 * and citizen satisfaction specific to an authoritarian government system.
 */
class Authoritarianism : public PoliticalSystem {
public:
    /**
     * @brief Constructor for Authoritarianism.
     */
    Authoritarianism();

    /**
     * @brief Get the residential tax rate.
     * @return The tax rate for residential zones as an integer percentage.
     */
    virtual int getTaxRateResidential();

    /**
     * @brief Get the name of the political system.
     * @return The name of the political system as a string.
     */
    virtual std::string getSystemName();

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
     * @brief Destructor for Authoritarianism.
     */
    ~Authoritarianism();
};

#endif // AUTHORITARIANISM_H
