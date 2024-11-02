#ifndef SHOP_H
#define SHOP_H

#include "CommercialBuilding.h"
#include <string>

class Shop : public CommercialBuilding {
    private:
        static const int DEFAULT_SHOP_COST = 5000;
        static const int DEFAULT_SHOP_RADIUS = 2;
    public:
        Shop();
        ~Shop();

        std::string getCommercialBuildingType();

        static sf::Texture* texture;
};


#endif