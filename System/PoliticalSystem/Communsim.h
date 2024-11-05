/**
 * @file Communsim.h
 * @brief Definition of the Communsim class.
 * 
 * This file declares the Communsim class, which represents a communist political system.
 */

#ifndef COMMUNSIM_H
#define COMMUNSIM_H
#include "PoliticalSystem.h"

/**
 * @class Communsim
 * @brief A political system model representing communism.
 */
class Communsim : public PoliticalSystem {
public:
    /**
     * @brief Constructor for Communsim.
     */
    Communsim();

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
     * @brief Destructor for Communsim.
     */
    ~Communsim();
};

#endif // COMMUNSIM_H