/**
 * @file PoliticalSystem.h
 * @brief Definition of the PoliticalSystem base class.
 * 
 * This file declares the abstract base class for different political systems.
 */

#ifndef POLITICALSYSTEM_H
#define POLITICALSYSTEM_H
#include <string>

/**
 * @class PoliticalSystem
 * @brief An abstract class representing a political system.
 * 
 * This class serves as the base for other specific political system types,
 * providing a common interface for economic policies.
 */
class PoliticalSystem {
public:
    /**
     * @brief Constructor for PoliticalSystem.
     */
    PoliticalSystem();

    /**
     * @brief Get the residential tax rate.
     * @return The tax rate for residential zones as an integer percentage.
     */
    virtual int getTaxRateResidential() = 0;

    
    virtual std::string getSystemName() = 0;

    /**
     * @brief Get the commercial tax rate.
     * @return The tax rate for commercial zones as an integer percentage.
     */
    virtual int getTaxRateCommercial() = 0;

    /**
     * @brief Get the industrial tax rate.
     * @return The tax rate for industrial zones as an integer percentage.
     */
    virtual int getTaxRateIndustrial() = 0;

    /**
     * @brief Get the budget split for public services.
     * @return The budget allocation proportion as a double.
     */
    virtual double getBudgetSplit() = 0;

    /**
     * @brief Get the impact on citizen satisfaction.
     * @return The calculated impact on citizen satisfaction as an integer.
     */
    virtual int getCitizenSatisfactionImpact() = 0;

    /**
     * @brief Destructor for PoliticalSystem.
     */
    virtual ~PoliticalSystem();
};

#endif // POLITICALSYSTEM_H
