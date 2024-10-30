#include "Communsim.h"
#include <random>
using namespace std;

Communsim::Communsim(){
}

int Communsim::getTaxRateResidential(){
    return 30;
}

int Communsim::getTaxRateCommercial(){
    return 40;
}

int Communsim::getTaxRateIndustrial(){
    return 60;
}

double Communsim::budgetSplitTaxes(){
    return 0.3;
}

int Communsim::politicalAffectOnSatisfaction(){
    random_device rd;
    mt19937 gen(rd());
    // Define the distribution range between -2 and 2 (inclusive)
    uniform_int_distribution<int> dist(-2, 2);
    // Generate a random number
    int random_number = dist(gen);
    return 7 + random_number;
}

Communsim::~Communsim(){
}


