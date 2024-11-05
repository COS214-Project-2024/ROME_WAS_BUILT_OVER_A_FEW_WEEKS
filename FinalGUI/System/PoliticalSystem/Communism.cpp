#include "Communism.h"
#include <random>
using namespace std;

Communism::Communism(){
}

int Communism::getTaxRateResidential(){
    return 30;
}

int Communism::getTaxRateCommercial(){
    return 40;
}

int Communism::getTaxRateIndustrial(){
    return 60;
}

double Communism::getBudgetSplit(){
    return 0.3;
}

int Communism::getCitizenSatisfactionImpact(){
    random_device rd;
    mt19937 gen(rd());
    // Define the distribution range between -2 and 2 (inclusive)
    uniform_int_distribution<int> dist(-2, 2);
    // Generate a random number
    int random_number = dist(gen);
    return 7 + random_number;
}

Communism::~Communism(){
}


