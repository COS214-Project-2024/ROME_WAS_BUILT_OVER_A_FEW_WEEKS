#ifndef RESIDENTIAL_FACTORY_H
#define RESIDENTIAL_FACTORY_H

#include "BuildingFactory.h"    
#include "House.h"
#include "Apartment.h"
#include "Estate.h"
#include "Townhouse.h"

class ResidentialFactory : public BuildingFactory {
    public: 
        virtual ResidentialBuilding* createResidentialBuilding() = 0;
        virtual ~ResidentialFactory() {};
};

class HouseFactory : public ResidentialFactory {
    public:
        virtual ResidentialBuilding* createResidentialBuilding() override;
};

class ApartmentFactory : public ResidentialFactory {
    public:
        virtual ResidentialBuilding* createResidentialBuilding() override;
};

class EstateFactory : public ResidentialFactory {
    public:
        virtual ResidentialBuilding* createResidentialBuilding() override;
};

class TownhouseFactory : public ResidentialFactory {
    public:
        virtual ResidentialBuilding* createResidentialBuilding() override;
};

#endif