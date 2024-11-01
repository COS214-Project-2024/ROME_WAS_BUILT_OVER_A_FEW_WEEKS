#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

#include "ResidentialBuilding.h"

class Townhouse : public ResidentialBuilding {
    private:
        static const int DEFAULT_TOWNHOUSE_CAPACITY = 15;
        static const int DEFAULT_TOWNHOUSE_COST = 5000;
    public:
        Townhouse();
        ~Townhouse();

        std::string getResidentialBuildingType();
        
};

#endif