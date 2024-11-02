#ifndef PARK_H
#define PARK_H

#include  "Landmark.h"
#include <string>

class Park : public Landmark {
    private:
        static const int DEFAULT_PARK_COST = 10000;
        static const int DEFAULT_PARK_RADIUS = 3;
    public:
        Park();
        ~Park();
        std::string getLandmarkType();
};

#endif