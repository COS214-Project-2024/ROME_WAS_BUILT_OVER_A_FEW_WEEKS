#include "Mall.h"

Mall::Mall(int radiusOfEffect) : CommercialBuilding(radiusOfEffect) {
    numEmployed = 0;
    taxRatePerPerson = 100;
    employmentCapacity = 100;
}

Mall::~Mall() {}

// int Mall::calculateTotalTaxes() {
//     return numEmployed * taxRatePerPerson;
// }