/**
 * @file Democracy.cpp
 * @brief Implementation of the Democracy class.
 * 
 * This file contains the function definitions for the Democracy class, 
 * which simulates economic policies of a democratic system.
 */

#include "Democracy.h"
#include <random>
using namespace std;

/**
 * @brief Constructor for the Democracy class.
 */
Democracy::Democracy() {
}

/**
 * @brief Get the residential tax rate.
 * @return The tax rate for residential zones as an integer percentage.
 */
int Democracy::getTaxRateResidential() {
    return 50;
}

/**
 * @brief Get the commercial tax rate.
 * @return The tax rate for commercial zones as an integer percentage.
 */
int Democracy::getTaxRateCommercial() {
    return 75;
}

/**
 * @brief Get the industrial tax rate.
 * @return The tax rate for industrial zones as an integer percentage.
 */
int Democracy::getTaxRateIndustrial() {
    return 100;
}

/**
 * @brief Get the budget split for public services.
 * @return The budget allocation proportion as a double.
 */
double Democracy::getBudgetSplit() {
    return 0.5;
}

/**
 * @brief Get the impact on citizen satisfaction.
 * 
 * Generates a random number to add variability to the citizen satisfaction.
 * @return The citizen satisfaction impact as an integer.
 */
int Democracy::getCitizenSatisfactionImpact() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-2, 2);
    int random_number = dist(gen);
    return 5 + random_number;
}

/**
 * @brief Destructor for the Democracy class.
 */
Democracy::~Democracy() {
}
