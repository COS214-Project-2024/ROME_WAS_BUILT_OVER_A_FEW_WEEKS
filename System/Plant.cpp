#include "Plant.h"

Plant::Plant() : IndustrialBuilding() {
    radiusOfEffect = 10;
    numEmployees = 0;
    employmentCapacity = 100;
    taxRatePerPerson = 200.0;
}

Plant::~Plant() {}

int Plant::getRadiusOfEffect() {
    return radiusOfEffect;
}
