#include "Apartment.h"

Apartment::Apartment(int capacity) : ResidentialBuilding(capacity) {
    numInhabitants = 0;
    taxRatePerUnit = 100;
}

// int Appartment::calculateTotalTaxes() {
//     return numUnits * taxRatePerUnit;
// }

