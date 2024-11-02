// Booster Structures
#include "./BoosterStructures/Airport.h"
#include "./BoosterStructures/BoosterStructures.h"
#include "./BoosterStructures/Railway.h"

// Check Adjacent Template
#include "./CheckAdjacentTemplate/CheckAdjacent.h"

// City Structures - Residential
#include "./CityStructures/Residential/Apartment.h"
#include "./CityStructures/Residential/Estate.h"
#include "./CityStructures/Residential/House.h"
#include "./CityStructures/Residential/ResidentialBuilding.h"
#include "./CityStructures/Residential/ResidentialComplex.h"
#include "./CityStructures/Residential/Townhouse.h"

// City Structures - Commercial
#include "./CityStructures/Commercial/CommercialBuilding.h"
#include "./CityStructures/Commercial/Mall.h"
#include "./CityStructures/Commercial/Office.h"
#include "./CityStructures/Commercial/Shop.h"

// City Structures - Industrial
#include "./CityStructures/Industrial/Concrete.h"
#include "./CityStructures/Industrial/ConcreteGenerator.h"
#include "./CityStructures/Industrial/Factory.h"
#include "./CityStructures/Industrial/IndustrialBuilding.h"
#include "./CityStructures/Industrial/Plant.h"
#include "./CityStructures/Industrial/PowerPlant.h"
#include "./CityStructures/Industrial/SewagePlant.h"
#include "./CityStructures/Industrial/Steel.h"
#include "./CityStructures/Industrial/SteelGenerator.h"
#include "./CityStructures/Industrial/Warehouse.h"
#include "./CityStructures/Industrial/WastePlant.h"
#include "./CityStructures/Industrial/WaterPlant.h"
#include "./CityStructures/Industrial/Wood.h"
#include "./CityStructures/Industrial/WoodGenerator.h"

// City Structures - Landmark
#include "./CityStructures/Landmark/Colosseum.h"
#include "./CityStructures/Landmark/Landmark.h"
#include "./CityStructures/Landmark/Pantheon.h"
#include "./CityStructures/Landmark/Park.h"

// City Structures - Road
#include "./CityStructures/Road/HighTraffic.h"
#include "./CityStructures/Road/LowTraffic.h"
#include "./CityStructures/Road/MediumTraffic.h"
#include "./CityStructures/Road/Road.h"

// Political System
#include "./PoliticalSystem/Authoritarianism.h"
#include "./PoliticalSystem/Communsim.h"
#include "./PoliticalSystem/Democracy.h"
#include "./PoliticalSystem/PoliticalSystem.h"

// Satisfaction Handlers
#include "./SatisfactionHandler/HighSatisfactionHandler.h"
#include "./SatisfactionHandler/LowSatisfactionHandler.h"
#include "./SatisfactionHandler/MediumSatisfactionHandler.h"
#include "./SatisfactionHandler/SatisfactionHandler.h"

// Core City Classes
#include "CityHall.h"
#include "CityMap.h"
#include "./CityStructures/CityStructure.h"







using namespace std;
// SET-UP REQUIREMENTS SO FAR:
// Create CityMap and CityHall.
// CityHall needs reference to political system

// void testDecorator(){
//     cout << "Testing Plants" << endl;
//     Plant* plant = new Plant();
//     Plant* powerPlant = new PowerPlant(plant);
//     Plant* waterPlant = new WaterPlant(powerPlant);
//     Plant* powerPlant2 = new PowerPlant(waterPlant);
//     Plant* wastePlant = new WastePlant(powerPlant2);
//     Plant* sewagePlant = new SewagePlant(wastePlant);

//     std::cout << sewagePlant->getPlantType() << std::endl;

//     cout << "\nTesting Generators" << endl;
//     Factory* factory = new Factory();
//     Factory* concreteFactory = new ConcreteGenerator(factory);
//     Factory* steelFactory = new SteelGenerator(concreteFactory);
//     Factory* woodFactory = new WoodGenerator(steelFactory);


//     std::cout << woodFactory->getFactoryType() << std::endl;
// }

int main(){

    cout << "Hello, World!" << endl;

    // CREATE CITY MAP
    cout << "\nCREATE CITY MAP" << endl;
    CityMap* cityMap = new CityMap();

    // CREATE AND PLACE CITY HALL
    cout << "\nCREATE AND PLACE CITY HALL" << endl;
    CityHall* cityHall = CityHall::getInstance();
    cityHall->placeStructure(0, 0, cityMap);

    // CREATE AND PLACE ROADS
    cout << "\nCREATE AND PLACE ROADS" << endl;
    Road* road1 = new Road();
    road1->placeStructure(0, 1, cityMap);
    Road* road2 = new Road();
    road2->placeStructure(1, 1, cityMap);
    Road* road3 = new Road();
    road3->placeStructure(2, 1, cityMap);


    // CREATE AND PLACE RESIDENTIAL COMPLEXES 
    cout << "\nCREATE AND PLACE RESIDENTIAL COMPLEXES" << endl;
    ResidentialBuilding* house1 = new House();
    ResidentialComplex* residentialComplex1 = new ResidentialComplex(house1);
    residentialComplex1->placeStructure(1, 2, cityMap);

    //print states
    cout << "\nPRINT STATES" << endl;
    cityHall->printCityHallState();
    cout << endl;
    residentialComplex1->printResidentialComplexState();

    // CREATE AND PLACE COMMERCIAL BUILDINGS
    cout << "\nCREATE AND PLACE COMMERCIAL BUILDINGS" << endl;
    CommercialBuilding* shop1 = new Shop();
    shop1->placeStructure(2, 2, cityMap);

    //print states
    cout << "\nPRINT STATES" << endl;
    cityHall->printCityHallState();
    cout << endl;
    residentialComplex1->printResidentialComplexState();

    // // CREATE AND PLACE INDUSTRIAL BUILDINGS
    // cout << "\nCREATE AND PLACE INDUSTRIAL BUILDINGS" << endl;
    // Plant* factory1 = new Factory();
    // factory1->placeStructure(3, 2, cityMap);

    // CREATE AND PLACE LANDMARKS
    cout << "\nCREATE AND PLACE LANDMARKS" << endl;
    Landmark* colosseum = new Colosseum();
    colosseum->placeStructure(0, 2, cityMap);

    // PLACE RESIDENTIAL COMPLEX AFTER HAVING COMMERCIAL BUILDING AND LANDMARK
    cout << "\nPLACE RESIDENTIAL COMPLEX AFTER HAVING COMMERCIAL BUILDING AND LANDMARK" << endl;
    ResidentialBuilding* house2 = new House();
    ResidentialComplex* residentialComplex2 = new ResidentialComplex(house2);
    residentialComplex2->placeStructure(3, 1, cityMap);

    residentialComplex2->addResidentialComponent(new House());

    //print states
    cout << "\nPRINT STATES" << endl;
    cityHall->printCityHallState();
    cout << endl;
    residentialComplex1->printResidentialComplexState();
    cout << endl;
    residentialComplex2->printResidentialComplexState();




    std::vector<std::vector<CityStructure*> > map = cityMap->getMap();
    cout << "City Map: " << map.size() << endl;
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if(map[i][j] != nullptr){
                cout << map[i][j]->getStructureType() << " ";
            }else{
                cout << "NULL ";
            }
        }
        cout << endl;
    }



    cout << "Bye!" << endl; 

    /*// =====================
    // === GRAPHICS PART ===
    // =====================
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }
    // // =====================

    */
  

    return 0;
}