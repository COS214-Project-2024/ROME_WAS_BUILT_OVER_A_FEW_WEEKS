#ifndef FACTORY_H
#define FACTORY_H

#include "IndustrialBuilding.h"
#include "Material.h"

#include <queue>

class Factory : public IndustrialBuilding {
    protected:
        int itemQueueSize;
        std::queue<Material*> itemQueue;
    public:
        Factory();
        virtual ~Factory();
        
        void addItemToQueue(Material* item);
        void removeItemFromQueue();

        
    
};


#endif