#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"

class House : public ResidentialBuilding {
    private:
        static const int DEFAULT_HOUSE_CAPACITY = 5;
        static const int DEFAULT_HOUSE_COST = 1000;
    public:
        House();
        ~House();

        std::string getStructureType() override;
        
};

#endif