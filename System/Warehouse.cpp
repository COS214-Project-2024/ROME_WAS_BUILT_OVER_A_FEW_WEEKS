#include "Warehouse.h"

Warehouse::Warehouse() : IndustrialBuilding() {
    numEmployees = 0;
    employmentCapacity = 50;
    taxRatePerPerson = 250.0;
}

Warehouse::~Warehouse() {}

// int Warehouse::calculateTotalTaxes() {
//     return numEmployees * taxRatePerPerson;
// }