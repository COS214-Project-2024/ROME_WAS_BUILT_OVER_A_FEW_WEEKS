#ifndef ESTATE_H
#define ESTATE_H

#include "ResidentialBuilding.h"

class Estate : public ResidentialBuilding {
    private:
        static const int DEFAULT_ESTATE_CAPACITY = 120;
        static const int DEFAULT_ESTATE_COST = 10000;
    public:
        Estate();
        ~Estate();
        
        std::string getStructureType() override;
        
};

#endif