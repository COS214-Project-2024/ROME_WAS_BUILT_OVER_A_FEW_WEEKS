#include "House.h"

House::House(int capacity) : ResidentialBuilding(capacity) {
    numInhabitants = 0;
    taxRatePrePerson = 40.0;
}

House::~House() {}

// int House::calculateTotalTaxes() {
//     return numInhabitants * taxRatePerPerson;
// }