#include "Factory.h"

Factory::Factory(){
    itemQueueSize = 100;
}

Factory::~Factory(){
    itemQueueSize = 0;
    while(!itemQueue.empty()){
        itemQueue.pop();
    }
}