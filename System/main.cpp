#include <iostream>
#include "Factory.h"
#include "GeneratorDecorator.h"
#include "ConcreteGenerator.h"
#include "SteelGenerator.h"
#include "WoodGenerator.h"
#include "Material.h"
#include "Concrete.h"
#include "Steel.h"
#include "Wood.h"


using namespace std;

// SET-UP REQUIREMENTS SO FAR:
// Create CityMap and CityHall.
// CityHall needs reference to political system


void testDecorator(){
    cout << "Testing Decorator" << endl;
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
    
}

int main(){

    /*int x = 0;
    int y = 0;
    int z = 0;

    while (true) {
        if (x == 1000000000){
            cout << "Hello" << endl;
            x = 0;
        }
        
        x++;
    }

    while (true){
        x += 1;
        
        if (x % 100000000 == 0){
            y += 1;
        }

        if (y % 1000000 == 0){
            z += 1;
            x = 0;
        }

        if (z % 100000 == 0){
            cout << "x: " << x << " y: " << y << " z: " << z << endl;
            y = 0;
        }
    }*/
    testDecorator();

    return 0;
}