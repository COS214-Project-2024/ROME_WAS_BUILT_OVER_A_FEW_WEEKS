#include "IndustrialFactory.h"

IndustrialBuilding* WarehouseFactory::createIndustrialBuilding() {
    return new Plant();
}

IndustrialBuilding* FactoryFactory::createIndustrialBuilding() {
    return new Plant();
}

IndustrialBuilding* PlantFactory::createIndustrialBuilding() {
    return new Plant();
}

