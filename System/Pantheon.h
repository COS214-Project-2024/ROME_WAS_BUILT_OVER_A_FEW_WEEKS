#ifndef PANTEHON_H
#define PANTEHON_H

#include "Landmark.h"
#include <string>

class Pantheon : public Landmark {
    private:
        static const int DEFAULT_PANTHEON_COST = 1000000;
        static const int DEFAULT_PANTHEON_RADIUS = 10;
    public:
        Pantheon();
        ~Pantheon();
        std::string getLandmarkType();
};

#endif