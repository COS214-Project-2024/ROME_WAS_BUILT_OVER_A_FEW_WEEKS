#include "WoodGenerator.h"

WoodGenerator::WoodGenerator(Factory *factory){
    this->factory = factory;
}

WoodGenerator::~WoodGenerator(){
    delete factory;
}

void WoodGenerator::addToQueue(Material *material){
    if(itemQueue.size() < itemQueueSize){
        if(material->getMaterialName() == "Wood"){
            itemQueue.push(material);
            generate();
        }
        else{
            std::cout << "Wood Generator only accepts Wood" << std::endl;
        }
    }
    else{
        std::cout << "Wood Generator is full" << std::endl;
    }
}

int WoodGenerator::generate(){
    if(itemQueue.size() > 0){
        Material* material = itemQueue.front();
        itemQueue.pop();
        std::cout << "Wood Generator generated " << material->getMaterialName() << std::endl;
        return 100;
    }
    else{
        std::cout << "Wood Generator is empty" << std::endl;
    }
    return 0;
}
   


