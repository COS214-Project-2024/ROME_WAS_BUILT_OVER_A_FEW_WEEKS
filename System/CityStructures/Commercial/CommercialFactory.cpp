#include "CommercialFactory.h"

CommercialBuilding* ShopFactory::createCommercialBuilding() {
    return new Shop();
}

CommercialBuilding* OfficeFactory::createCommercialBuilding() {
    return new Office();
}

CommercialBuilding* MallFactory::createCommercialBuilding() {
    return new Mall();
}

