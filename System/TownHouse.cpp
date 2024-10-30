#include "TownHouse.h"

Townhouse::Townhouse(int numInhabitants) : ResidentialBuilding(numInhabitants) {
    numInhabitants = 0;
    taxRatePerPerson = 50.0;
}

Townhouse::~Townhouse() {}


// int Townhouse::calculateTotalTaxes() {
//     return numInhabitants * taxRatePerPerson;
// }

