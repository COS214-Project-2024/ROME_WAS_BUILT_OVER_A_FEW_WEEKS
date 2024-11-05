#ifndef MALL_H
#define MALL_H

#include "CommercialBuilding.h"
#include <string>

class Mall : public CommercialBuilding {
    private:
        static const int DEFAULT_MALL_COST = 20000;
        static const int DEFAULT_MALL_RADIUS = 10;
    public:
        Mall();
        ~Mall();

        std::string getCommercialBuildingType();
        
};

#endif