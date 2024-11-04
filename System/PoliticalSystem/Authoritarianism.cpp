/**
 * @file Authoritarianism.cpp
 * @brief Implementation of the Authoritarianism class.
 * 
 * This file defines the methods for the Authoritarianism class, which models
 * an economic system with specific tax rates, budget distribution, and citizen satisfaction impact.
 */

#include "Authoritarianism.h"
#include "Authoritarianism.h"

#include <random>
using namespace std;

std::string Authoritarianism::getSystemName(){
    return "Authoritarianism";
}

/**
 * @brief Default constructor for the Authoritarianism class.
 * 
 * Initializes an instance of the Authoritarianism economic system.
 */
Authoritarianism::Authoritarianism() {
}

/**
 * @brief Get the tax rate for residential zones.
 * 
 * This method returns the tax rate applied to residential areas.
 * 
 * @return The tax rate for residential zones, represented as an integer percentage.
 */
int Authoritarianism::getTaxRateResidential() {
    return 80;
}

/**
 * @brief Get the tax rate for commercial zones.
 * 
 * This method returns the tax rate applied to commercial areas.
 * 
 * @return The tax rate for commercial zones, represented as an integer percentage.
 */
int Authoritarianism::getTaxRateCommercial() {
    return 100;
}

/**
 * @brief Get the tax rate for industrial zones.
 * 
 * This method returns the tax rate applied to industrial areas.
 * 
 * @return The tax rate for industrial zones, represented as an integer percentage.
 */
int Authoritarianism::getTaxRateIndustrial() {
    return 120;
}

/**
 * @brief Get the budget split for public services.
 * 
 * This method returns the proportion of the budget allocated to public services.
 * 
 * @return The budget split as a double, where 1.0 represents 100%.
 */
double Authoritarianism::getBudgetSplit() {
    return 0.7;
}

/**
 * @brief Get the impact on citizen satisfaction.
 * 
 * This method calculates a random impact on citizen satisfaction. The base value is 3, 
 * with a random adjustment between -2 and 2.
 * 
 * @return The citizen satisfaction impact as an integer, with variability to simulate uncertainty.
 */
int Authoritarianism::getCitizenSatisfactionImpact() {
    random_device rd;        ///< Random device used to seed the generator.
    mt19937 gen(rd());       ///< Mersenne Twister pseudo-random generator.
    uniform_int_distribution<int> dist(-2, 2); ///< Distribution for generating random numbers between -2 and 2.
    
    // Generate a random number and return the adjusted satisfaction impact.
    int random_number = dist(gen);
    return -3 + random_number;
}

/**
 * @brief Destructor for the Authoritarianism class.
 * 
 * Cleans up resources used by an instance of the Authoritarianism class.
 */
Authoritarianism::~Authoritarianism() {
}
