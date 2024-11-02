#include <iostream>
#include "BuildingFactory.h"
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "IndustrialFactory.h"
#include "LandmarkFactory.h"

int main() {
    // Test Residential Factories
    HouseFactory houseFactory;
    ResidentialBuilding* house = houseFactory.createResidentialBuilding();
    std::cout << "Created house with capacity: " << house->getCapacity() << std::endl;
    delete house;

    ApartmentFactory apartmentFactory;
    ResidentialBuilding* apartment = apartmentFactory.createResidentialBuilding();
    std::cout << "Created apartment with capacity: " << apartment->getCapacity() << std::endl;
    delete apartment;

    EstateFactory estateFactory;
    ResidentialBuilding* estate = estateFactory.createResidentialBuilding();
    std::cout << "Created estate with capacity: " << estate->getCapacity() << std::endl;
    delete estate;

    TownhouseFactory townhouseFactory;
    ResidentialBuilding* townhouse = townhouseFactory.createResidentialBuilding();
    std::cout << "Created townhouse with capacity: " << townhouse->getCapacity() << std::endl;
    delete townhouse;

    // Test Commercial Factories
    ShopFactory shopFactory;
    CommercialBuilding* shop = shopFactory.createCommercialBuilding();
    std::cout << "Created shop with radius of effect: " << static_cast<Shop*>(shop)->getRadiusOfEffect() << std::endl;
    delete shop;

    OfficeFactory officeFactory;
    CommercialBuilding* office = officeFactory.createCommercialBuilding();
    std::cout << "Created office with radius of effect: " << static_cast<Office*>(office)->getRadiusOfEffect() << std::endl;
    delete office;

    MallFactory mallFactory;
    CommercialBuilding* mall = mallFactory.createCommercialBuilding();
    std::cout << "Created mall with radius of effect: " << static_cast<Mall*>(mall)->getRadiusOfEffect() << std::endl;
    delete mall;

    // Test Industrial Factories
    WarehouseFactory warehouseFactory;
    IndustrialBuilding* warehouse = warehouseFactory.createIndustrialBuilding();
    std::cout << "Created warehouse" << std::endl;
    delete warehouse;

    PlantFactory plantFactory;
    IndustrialBuilding* plant = plantFactory.createIndustrialBuilding();
    std::cout << "Created plant" << std::endl;
    delete plant;

    FactoryFactory factoryFactory;
    IndustrialBuilding* factory = factoryFactory.createIndustrialBuilding();
    std::cout << "Created factory" << std::endl;
    delete factory;

    // Test Landmark Factories
    ParkFactory parkFactory;
    Landmark* park = parkFactory.createLandmark();
    std::cout << "Created park with radius of effect: " << static_cast<Park*>(park)->getRadiusOfEffect() << std::endl;
    delete park;

    MonumentFactory monumentFactory;
    Landmark* monument = monumentFactory.createLandmark();
    std::cout << "Created monument with radius of effect: " << static_cast<Monument*>(monument)->getRadiusOfEffect() << std::endl;
    delete monument;

    CulturalCenterFactory culturalCenterFactory;
    Landmark* culturalCenter = culturalCenterFactory.createLandmark();
    std::cout << "Created cultural center with radius of effect: " << static_cast<CulturalCenter*>(culturalCenter)->getRadiusOfEffect() << std::endl;
    delete culturalCenter;

    return 0;
}