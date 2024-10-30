#ifndef COLLOSSEUM_H
#define COLLOSSEUM_H

#include "Landmark.h"
#include <string>

class Colosseum : public Landmark {
    private:
        static const int DEFAULT_COLOSSEUM_COST = 100000;
        static const int DEFAULT_COLOSSEUM_RADIUS = 5;
    public:
        Colosseum();
        ~Colosseum();
        std::string getLandmarkType();
};

#endif