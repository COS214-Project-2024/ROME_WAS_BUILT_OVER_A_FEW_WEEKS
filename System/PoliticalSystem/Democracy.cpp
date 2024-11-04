#include "Democracy.h"
#include <random>
using namespace std;
Democracy::Democracy(){
}

std::string Democracy::getSystemName(){
    return "Democracy";
}

int Democracy::getTaxRateResidential(){
    return 50;
}

int Democracy::getTaxRateCommercial(){
    return 75;
}

int Democracy::getTaxRateIndustrial(){
    return 100;
}

double Democracy::getBudgetSplit(){
    return 0.5;
}

int Democracy::getCitizenSatisfactionImpact(){
    random_device rd;
    mt19937 gen(rd());
    // Define the distribution range between -2 and 2 (inclusive)
    uniform_int_distribution<int> dist(-2, 2);
    // Generate a random number
    int random_number = dist(gen);
    return 5 + random_number;
}

Democracy::~Democracy(){
}

