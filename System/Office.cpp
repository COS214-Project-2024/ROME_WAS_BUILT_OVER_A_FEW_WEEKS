#include "Office.h"

Office::Office(int radiusOfEffect) : CommercialBuilding(radiusOfEffect) {
    numEmployed = 0;
    employmentCapacity = 50;
    taxRatePerPerson = 300.0;
}

Office::~Office() {}

// int Office::calculateTotalTaxes() {
//     return numEmployed * taxRatePerPerson;
// }
