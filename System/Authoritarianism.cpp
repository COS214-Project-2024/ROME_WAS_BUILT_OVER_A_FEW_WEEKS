#include "Authoritarianism.h"
#include <random>
using namespace std;

Authoritarianism::Authoritarianism(){
}

int Authoritarianism::getTaxRateResidential(){
    return 80;
}

int Authoritarianism::getTaxRateCommercial(){
    return 100;
}

int Authoritarianism::getTaxRateIndustrial(){
    return 120;
}

double Authoritarianism::getBudgetSplit(){
    return 0.7;
}

int Authoritarianism::getCitizenSatisfactionImpact(){
    random_device rd;
    mt19937 gen(rd());
    // Define the distribution range between -2 and 2 (inclusive)
    uniform_int_distribution<int> dist(-2, 2);
    // Generate a random number
    int random_number = dist(gen);
    return 3 + random_number;
}

Authoritarianism::~Authoritarianism(){
}