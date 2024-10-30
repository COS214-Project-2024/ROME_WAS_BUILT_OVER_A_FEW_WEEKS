#include "SteelGenerator.h"

SteelGenerator::SteelGenerator(Factory *factory){
    this->factory = factory;
}

SteelGenerator::~SteelGenerator(){
    delete factory;
}

void SteelGenerator::addToQueue(Material *material){
    if(itemQueue.size() < itemQueueSize){
        if(material->getMaterialName() == "Steel"){
            itemQueue.push(material);
            generate();
        }
        else{
            std::cout << "Steel Generator only accepts Steel" << std::endl;
        }
    }
    else{
        std::cout << "Steel Generator is full" << std::endl;
    }
}

int SteelGenerator::generate(){
    if(itemQueue.size() > 0){
        Material* material = itemQueue.front();
        itemQueue.pop();
        std::cout << "Steel Generator generated " << material->getMaterialName() << std::endl;
        return 100;
    }
    else{
        std::cout << "Steel Generator is empty" << std::endl;
    }
}

