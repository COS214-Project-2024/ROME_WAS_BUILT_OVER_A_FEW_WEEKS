#include "ResidentialFactory.h"

ResidentialBuilding* HouseFactory::createResidentialBuilding() {
    return new House();
}

ResidentialBuilding* ApartmentFactory::createResidentialBuilding() {
    return new Apartment();
}

ResidentialBuilding* EstateFactory::createResidentialBuilding() {
    return new Estate();
}

ResidentialBuilding* TownhouseFactory::createResidentialBuilding() {
    return new Townhouse();
}
