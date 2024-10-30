#include "Shop.h"

Shop::Shop(int radiusOfEffect) : CommercialBuilding(radiusOfEffect) {
    numEmployed = 0;
    taxRatePerPerson = 50;
    employmentCapacity = 10;
}

Shop::~Shop() {}

// int Shop::calculateTotalTaxes() {
//     return numEmployed * taxRatePerPerson;
// }