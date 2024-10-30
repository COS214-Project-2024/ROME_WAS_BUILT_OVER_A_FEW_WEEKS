#ifndef COMMERCIAL_FACTORY_H
#define COMMERCIAL_FACTORY_H

#include "BuildingFactory.h"
#include "Shop.h"
#include "Office.h"
#include "Mall.h"

class CommercialFactory : public BuildingFactory {
    public: 
        virtual CommercialBuilding* createCommercialBuilding() = 0;
        virtual ~CommercialFactory() {};
};

class ShopFactory : public CommercialFactory {
    public:
        virtual CommercialBuilding* createCommercialBuilding() override;
};

class OfficeFactory : public CommercialFactory {
    public:
        virtual CommercialBuilding* createCommercialBuilding() override;
};

class MallFactory : public CommercialFactory {
    public:
        virtual CommercialBuilding* createCommercialBuilding() override;
};


#endif

