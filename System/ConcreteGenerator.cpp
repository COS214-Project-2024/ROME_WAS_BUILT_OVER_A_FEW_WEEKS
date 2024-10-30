#include "ConcreteGenerator.h"

ConcreteGenerator::ConcreteGenerator(Factory *factory){
    this->factory = factory;
}

ConcreteGenerator::~ConcreteGenerator(){
    delete factory;
}

void ConcreteGenerator::addToQueue(Material *material){
    if(itemQueue.size() < itemQueueSize){
        if(material->getMaterialName() == "Concrete"){
            itemQueue.push(material);
            generate();
        }
        else{
            std::cout << "Concrete Generator only accepts Concrete" << std::endl;
        }
    }
    else{
        std::cout << "Concrete Generator is full" << std::endl;
    }
}

int ConcreteGenerator::generate(){
    if(itemQueue.size() > 0){
        Material* material = itemQueue.front();
        itemQueue.pop();
        std::cout << "Concrete Generator generated " << material->getMaterialName() << std::endl;
        return 100;
    }
    else{
        std::cout << "Concrete Generator is empty" << std::endl;
    }
}

