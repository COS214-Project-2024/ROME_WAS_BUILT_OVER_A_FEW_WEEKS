/**
 * @file Communsim.cpp
 * @brief Implementation of the Communsim class.
 * 
 * This file contains the function definitions for the Communsim class, 
 * modeling economic policies specific to a communist system.
 */

#include "Communsim.h"
#include <random>
using namespace std;

/**
 * @brief Constructor for the Communsim class.
 */
Communsim::Communsim() {
}

/**
 * @brief Get the residential tax rate.
 * @return The tax rate for residential zones as an integer percentage.
 */
int Communsim::getTaxRateResidential() {
    return 30;
}

/**
 * @brief Get the commercial tax rate.
 * @return The tax rate for commercial zones as an integer percentage.
 */
int Communsim::getTaxRateCommercial() {
    return 40;
}

/**
 * @brief Get the industrial tax rate.
 * @return The tax rate for industrial zones as an integer percentage.
 */
int Communsim::getTaxRateIndustrial() {
    return 60;
}

/**
 * @brief Get the budget split for public services.
 * @return The budget allocation proportion as a double.
 */
double Communsim::getBudgetSplit() {
    return 0.3;
}

/**
 * @brief Get the impact on citizen satisfaction.
 * 
 * Generates a random number to simulate variability in citizen satisfaction.
 * @return The citizen satisfaction impact as an integer.
 */
int Communsim::getCitizenSatisfactionImpact() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-2, 2);
    int random_number = dist(gen);
    return 7 + random_number;
}

/**
 * @brief Destructor for the Communsim class.
 */
Communsim::~Communsim() {
}
