#ifndef INDUSTRIAL_FACTORY_H
#define INDUSTRIAL_FACTORY_H

#include "../BuildingFactory.h"
//#include "Factory.h"
#include "Plant.h"


class IndustrialFactory : public BuildingFactory {
    public: 
        virtual IndustrialBuilding* createIndustrialBuilding() = 0;
        virtual ~IndustrialFactory() {};
};  

class WarehouseFactory : public IndustrialFactory {
    public:
        virtual IndustrialBuilding* createIndustrialBuilding() override;
};

class FactoryFactory : public IndustrialFactory {
    public:
        virtual IndustrialBuilding* createIndustrialBuilding() override;
};

class PlantFactory : public IndustrialFactory {
    public:
        virtual IndustrialBuilding* createIndustrialBuilding() override;
};

#endif