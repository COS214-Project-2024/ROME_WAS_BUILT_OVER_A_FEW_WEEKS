#ifndef FACTORY_H
#define FACTORY_H

#include "IndustrialBuilding.h"

#include <queue>

class Factory : public IndustrialBuilding {
    protected:
        int itemQueueSize;
        std::queue<int> itemQueue;
    public:
        Factory();
        virtual ~Factory();
        
        
    
};


#endif