#include "ConcreteGenerator.h"

ConcreteGenerator::ConcreteGenerator(Factory* factory) : GeneratorDecorator(factory){
    this->factory = factory;
}

ConcreteGenerator::~ConcreteGenerator(){
    delete factory;
    factory = nullptr;
    delete cityMap;
    cityMap = nullptr;
}

int ConcreteGenerator::generate(){
    return generateConcrete();
}

int ConcreteGenerator::generateConcrete(){
    return 100;
}

string ConcreteGenerator::getFactoryType(){
    return setConcreteGenerator();
}

string ConcreteGenerator::setConcreteGenerator(){
    factoryType = "|Concrete Factory|" + factory->getFactoryType();
    return this->factoryType;
}

bool ConcreteGenerator::placeStructure(int x, int y, CityMap *cityMap){
    bool placed = CityStructure::placeStructure(x, y, cityMap);
    if (placed) {
        cityMap->addFactory(this);
        return true;
    }
    else {
        return false;
    }
}

bool ConcreteGenerator::removeStructure(){
    bool removed = cityMap->removeStructure(x, y);
    if (removed) {
        cityMap->removeFactory(this);
        return true;
    }
    else {
        return false;
    }
}