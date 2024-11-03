#ifndef OFFICE_H
#define OFFICE_H

#include "CommercialBuilding.h"
#include <string>

class Office : public CommercialBuilding {
    private:
        static const int DEFAULT_OFFICE_COST = 10000;
        static const int DEFAULT_OFFICE_RADIUS = 4;
    public:
        Office();
        ~Office();

        std::string getCommercialBuildingType();
        std::string getStructureType();
        
};


#endif