#ifndef APARTMENT_H
#define APARTMENT_H

#include "ResidentialBuilding.h"

class Apartment : public ResidentialBuilding {
    private:
        static const int DEFAULT_APARTMENT_CAPACITY = 100;
        static const int DEFAULT_APARTMENT_COST = 10000;
    public:
        Apartment();
        ~Apartment();

        std::string getStructureType() override;
        
};

#endif