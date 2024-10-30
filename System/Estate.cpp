#include "Estate.h"


Estate::Estate(int capacity) : ResidentialBuilding(capacity) {
    numInhabitants = 0;
    taxRatePerPerson = 40; 
}

Estate::~Estate() {}

// int Estate::calculateTotalTax() {
//     return numInhabitants * taxRatePerPerson;
// }