#include "IndustrialFactory.h"

IndustrialBuilding* WarehouseFactory::createIndustrialBuilding() {
    return new Warehouse();
}

IndustrialBuilding* FactoryFactory::createIndustrialBuilding() {
    return new Factory();
}

IndustrialBuilding* PlantFactory::createIndustrialBuilding() {
    return new Plant();
}

