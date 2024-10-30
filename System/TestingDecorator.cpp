#include "Factory.h"
#include "GeneratorDecorator.h"
#include "ConcreteGenerator.h"
#include "SteelGenerator.h"
#include "WoodGenerator.h"
#include "Material.h"
#include "Concrete.h"
#include "Steel.h"
#include "Wood.h"

int main(){
    Factory* factory = new Factory();
    ConcreteGenerator* concreteGenerator = new ConcreteGenerator(factory);
    SteelGenerator* steelGenerator = new SteelGenerator(factory);
    WoodGenerator* woodGenerator = new WoodGenerator(factory);
    
    Material* concrete = new Concrete();
    Material* steel = new Steel();
    Material* wood = new Wood();
    
    concreteGenerator->addToQueue(concrete);
    steelGenerator->addToQueue(steel);
    woodGenerator->addToQueue(wood);
    
    concreteGenerator->generate();
    steelGenerator->generate();
    woodGenerator->generate();
    
    delete concrete;
    delete steel;
    delete wood;
    delete concreteGenerator;
    delete steelGenerator;
    delete woodGenerator;
    delete factory;
    
    return 0;
}