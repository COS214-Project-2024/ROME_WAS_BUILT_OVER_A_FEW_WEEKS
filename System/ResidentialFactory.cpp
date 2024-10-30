#include "ResidentialFactory.h"

ResidentialBuilding* HouseFactory::createResidentialBuilding() {
    return new House(4);
}

ResidentialBuilding* ApartmentFactory::createResidentialBuilding() {
    return new Apartment(50);
}

ResidentialBuilding* EstateFactory::createResidentialBuilding() {
    return new Estate(25);
}

ResidentialBuilding* TownhouseFactory::createResidentialBuilding() {
    return new Townhouse(6);
}
