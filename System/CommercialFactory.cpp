#include "CommercialFactory.h"

CommercialBuilding* ShopFactory::createCommercialBuilding() {
    return new Shop(10);
}

CommercialBuilding* OfficeFactory::createCommercialBuilding() {
    return new Office(100);
}

CommercialBuilding* MallFactory::createCommercialBuilding() {
    return new Mall(50);
}

