//JARED TESTING

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

// Factory Methods
#include "./CityStructures/BuildingFactory.h"
#include "./CityStructures/Commercial/CommercialFactory.h"
#include "./CityStructures/Industrial/IndustrialFactory.h"
#include "./CityStructures/Landmark/LandmarkFactory.h"
#include "./CityStructures/Residential/ResidentialFactory.h"

// Core City Classes
#include "CityHall.h"
#include "CityMap.h"
#include "./CityStructures/CityStructure.h"

using namespace std;
// SET-UP REQUIREMENTS SO FAR:
// Create CityMap and CityHall.
// CityHall needs reference to political system



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
    if(residentialComplex2->placeStructure(3, 1, cityMap)){
        residentialComplex2->addResidentialComponent(new Townhouse(), cityMap);
    }

    //print states
    cout << "\nPRINT STATES" << endl;
    cityHall->printCityHallState();
    cout << endl;
    residentialComplex1->printResidentialComplexState();
    cout << endl;
    residentialComplex2->printResidentialComplexState();


    // CREATE AND PLACE ROADS
    cout << "\nCREATE AND PLACE ROADS" << endl;
    Road* road4 = new Road();
    road4->placeStructure(3, 2, cityMap);

    //CREATE AND PLACE PLANTS 
    cout << "\nCREATE AND PLACE PLANTS" << endl;
    Plant* plant = new Plant();
    Plant* powerPlant = new PowerPlant(plant);
    Plant* sewagePlant = new SewagePlant(powerPlant);
    std::cout << sewagePlant->getPlantType() << std::endl;


    //CREATE AND PLACE GENERATORS
    cout << "\nCREATE AND PLACE GENERATORS" << endl;
    Factory* factory = new Factory();
    Factory* concreteGenerator = new ConcreteGenerator(factory);
    Factory* steelGenerator = new SteelGenerator(concreteGenerator);
    Factory* woodGenerator = new WoodGenerator(steelGenerator);
    woodGenerator->placeStructure(4, 2, cityMap);
    cout << woodGenerator->getFactoryType() << endl;
    cout <<"\nGENERATE RESOURCES" << endl;
    cityMap->generateResources(woodGenerator);
    
    //CREATE AND PLACE WAREWHOUSE
    cout << "\nCREATE AND PLACE WAREWHOUSE" << endl;
    IndustrialBuilding* warehouse = new Warehouse();
    warehouse->placeStructure(3, 3, cityMap);

    //print states
    cout << "\nPRINT STATES" << endl;
    cityHall->printCityHallState();

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

    return 0;
}

// SET-UP REQUIREMENTS SO FAR:
// Create CityMap and CityHall.
// CityHall needs reference to political system


// // Testing Factorys -JASON TESTING

// #include <iostream>
// #include "CityStructures/Commercial/CommercialFactory.h"
// #include "CityStructures/BuildingFactory.h"
// #include "CityStructures/Residential/ResidentialFactory.h"
// #include "CityStructures/Industrial/IndustrialFactory.h"
// #include "CityStructures/Landmark/LandmarkFactory.h"

// int main() {
//     //Test Residential Factories
//     HouseFactory houseFactory;
//     ResidentialBuilding* house = houseFactory.createResidentialBuilding();
//     std::cout << "Created house with capacity: " << house->getCapacity() << std::endl;
//     delete house;

//     ApartmentFactory apartmentFactory;
//     ResidentialBuilding* apartment = apartmentFactory.createResidentialBuilding();
//     std::cout << "Created apartment with capacity: " << apartment->getCapacity() << std::endl;
//     delete apartment;

//     EstateFactory estateFactory;
//     ResidentialBuilding* estate = estateFactory.createResidentialBuilding();
//     std::cout << "Created estate with capacity: " << estate->getCapacity() << std::endl;
//     delete estate;

//     TownhouseFactory townhouseFactory;
//     ResidentialBuilding* townhouse = townhouseFactory.createResidentialBuilding();
//     std::cout << "Created townhouse with capacity: " << townhouse->getCapacity() << std::endl;
//     delete townhouse;

//     // Test Commercial Factories
//     ShopFactory shopFactory;
//     CommercialBuilding* shop = shopFactory.createCommercialBuilding();
//     std::cout << "Created shop with radius of effect: " << static_cast<Shop*>(shop)->getRadiusOfEffect() << std::endl;
//     delete shop;

//     OfficeFactory officeFactory;
//     CommercialBuilding* office = officeFactory.createCommercialBuilding();
//     std::cout << "Created office with radius of effect: " << static_cast<Office*>(office)->getRadiusOfEffect() << std::endl;
//     delete office;

//     MallFactory mallFactory;
//     CommercialBuilding* mall = mallFactory.createCommercialBuilding();
//     std::cout << "Created mall with radius of effect: " << static_cast<Mall*>(mall)->getRadiusOfEffect() << std::endl;
//     delete mall;

//     // Test Industrial Factories
//     PlantFactory plantFactory;
//     IndustrialBuilding* plant = plantFactory.createIndustrialBuilding();
//     std::cout << "Created plant" << std::endl;
//     delete plant;

//     FactoryFactory factoryFactory;
//     IndustrialBuilding* factory = factoryFactory.createIndustrialBuilding();
//     std::cout << "Created factory" << std::endl;
//     delete factory;

//     // Test Landmark Factories
//     ParkFactory parkFactory;
//     Landmark* park = parkFactory.createLandmark();
//     std::cout << "Created park with radius of effect: " << static_cast<Park*>(park)->getRadiusOfEffect() << std::endl;
//     delete park;

//     ColosseumFactory colosseumFactory;
//     Landmark* colosseum = colosseumFactory.createLandmark();
//     std::cout << "Created colosseum with radius of effect: " << static_cast<Colosseum*>(colosseum)->getRadiusOfEffect() << std::endl;
//     delete colosseum;

//     PantheonFactory pantheonFactory;
//     Landmark* pantheon = pantheonFactory.createLandmark();
//     std::cout << "Created cultural center with radius of effect: " << static_cast<Pantheon*>(pantheon)->getRadiusOfEffect() << std::endl;
//     delete pantheon;

//     return 0;
// }


//VANSH TESTING

// #include <iostream>
// #include <vector>

// #include "Factory.h"
// #include "GeneratorDecorator.h"
// #include "ConcreteGenerator.h"
// #include "SteelGenerator.h"
// #include "WoodGenerator.h"
// #include "Material.h"
// #include "Concrete.h"
// #include "Steel.h"
// #include "Wood.h"
// #include "Plant.h"
// #include "PlantDecorator.h"
// #include "PowerPlant.h"
// #include "WaterPlant.h"
// #include "WastePlant.h"
// #include "SewagePlant.h"

// #include "CityMap.h"
// #include "CityHall.h"

// // BUILDING TYPES
// #include "CityStructure.h"  
// #include "Road.h"
// #include "ResidentialComplex.h"
// #include "ResidentialBuilding.h"
// #include "CommercialBuilding.h"
// #include "IndustrialBuilding.h"
// #include "Landmark.h"

// // RESIDENTIAL BUILDING TYPES
// #include "House.h"
// #include "Apartment.h"
// #include "Townhouse.h"
// #include "Estate.h"

// // COMMERCIAL BUILDING TYPES
// #include "Shop.h"
// #include "Mall.h"
// #include "Office.h"

// // INDUSTRIAL BUILDING TYPES
// #include "Plant.h"
// #include "Factory.h"
// #include "Warehouse.h"

// // LANDMARK TYPES
// #include "Colosseum.h"
// #include "Pantheon.h"
// #include "Park.h"

// // GRAPHICS
// #include <SFML/Graphics.hpp>




// using namespace std;
// // SET-UP REQUIREMENTS SO FAR:
// // Create CityMap and CityHall.
// // CityHall needs reference to political system

// int main(){

//     cout << "Hello, World!" << endl;

//     // CREATE CITY MAP
//     cout << "\nCREATE CITY MAP" << endl;
//     CityMap* cityMap = new CityMap();

//     // CREATE AND PLACE CITY HALL
//     cout << "\nCREATE AND PLACE CITY HALL" << endl;
//     CityHall* cityHall = CityHall::getInstance();
//     cityHall->placeStructure(0, 0, cityMap);

//     // CREATE AND PLACE ROADS
//     cout << "\nCREATE AND PLACE ROADS" << endl;
//     Road* road1 = new Road();
//     road1->placeStructure(0, 1, cityMap);
//     Road* road2 = new Road();
//     road2->placeStructure(1, 1, cityMap);
//     Road* road3 = new Road();
//     road3->placeStructure(2, 1, cityMap);


//     // CREATE AND PLACE RESIDENTIAL COMPLEXES 
//     cout << "\nCREATE AND PLACE RESIDENTIAL COMPLEXES" << endl;
//     ResidentialBuilding* house1 = new House();
//     ResidentialComplex* residentialComplex1 = new ResidentialComplex(house1);
//     residentialComplex1->placeStructure(1, 2, cityMap);

//     //print states
//     cout << "\nPRINT STATES" << endl;
//     cityHall->printCityHallState();
//     cout << endl;
//     residentialComplex1->printResidentialComplexState();

//     // CREATE AND PLACE COMMERCIAL BUILDINGS
//     cout << "\nCREATE AND PLACE COMMERCIAL BUILDINGS" << endl;
//     CommercialBuilding* shop1 = new Shop();
//     shop1->placeStructure(2, 2, cityMap);

//     //print states
//     cout << "\nPRINT STATES" << endl;
//     cityHall->printCityHallState();
//     cout << endl;
//     residentialComplex1->printResidentialComplexState();

//     // // CREATE AND PLACE INDUSTRIAL BUILDINGS
//     // cout << "\nCREATE AND PLACE INDUSTRIAL BUILDINGS" << endl;
//     // Plant* factory1 = new Factory();
//     // factory1->placeStructure(3, 2, cityMap);

//     // CREATE AND PLACE PLANTS
//     cout << "\nCREATE AND PLACE PLANTS" << endl;
//     Plant* basePlant = new Plant();
//     Plant* powerPlant = new PowerPlant(basePlant);
//     Plant* powerWaterPlant = new WaterPlant(powerPlant);
//     cout << "TYPE: " << powerWaterPlant->getPlantType() << endl;
//     powerWaterPlant->placeStructure(1, 0, cityMap);

//     // print states
//     cout << "\nPRINT STATES" << endl;
//     cityHall->printCityHallState();
//     cout << endl;
//     residentialComplex1->printResidentialComplexState();

//     // CREATE AND PLACE LANDMARKS
//     cout << "\nCREATE AND PLACE LANDMARKS" << endl;
//     Landmark* colosseum = new Colosseum();
//     colosseum->placeStructure(0, 2, cityMap);

//     //print states
//     cout << "\nPRINT STATES" << endl;
//     cityHall->printCityHallState();
//     cout << endl;
//     residentialComplex1->printResidentialComplexState();

//     // PLACE RESIDENTIAL COMPLEX AFTER HAVING COMMERCIAL BUILDING AND LANDMARK
//     cout << "\nPLACE RESIDENTIAL COMPLEX AFTER HAVING COMMERCIAL BUILDING AND LANDMARK" << endl;
//     ResidentialBuilding* house2 = new House();
//     ResidentialComplex* residentialComplex2 = new ResidentialComplex(house2);
//     residentialComplex2->placeStructure(3, 1, cityMap);

//     // residentialComplex2->addResidentialComponent(new House());

//     //print states
//     cout << "\nPRINT STATES" << endl;
//     cityHall->printCityHallState();
//     cout << endl;
//     cout << "COMPLEX 1" << endl;
//     residentialComplex1->printResidentialComplexState();
//     cout << endl;
//     cout << "COMPLEX 2" << endl;
//     residentialComplex2->printResidentialComplexState();

//     // TEST REMOVING 
//     cout << "\n=======================================================================" << endl;
//     cout << "                         TEST REMOVING" << endl;
//     cout << "=======================================================================" << endl;

//     // REMOVE CITY HALL
//     cout << "\n============ REMOVE CITY HALL ============" << endl;
//     cityHall->removeStructure();

//     // REMOVE COMMERICAL BUILDING
//     cout << "\n======== REMOVE COMMERICAL BUILDING ========" << endl;
//     shop1->removeStructure();

//     cout << "\nResidential Complex 1" << endl;
//     residentialComplex1->printResidentialComplexState();
//     cout << "\nResidential Complex 2" << endl;
//     residentialComplex2->printResidentialComplexState();
//     cout << "==============================================" << endl;

//     // REMOVE LANDMARK
//     cout << "============= REMOVE LANDMARK =============" << endl;
//     colosseum->removeStructure();

//     cout << "\nResidential Complex 1" << endl;
//     residentialComplex1->printResidentialComplexState();
//     cout << "\nResidential Complex 2" << endl;
//     residentialComplex2->printResidentialComplexState();
//     cout << "==============================================" << endl;

//     // REMOVE PLANT
//     cout << "============== REMOVE PLANT ==============" << endl;
//     powerWaterPlant->removeStructure();

//     cout << "\nResidential Complex 1" << endl;
//     residentialComplex1->printResidentialComplexState();
//     cout << "\nResidential Complex 2" << endl;
//     residentialComplex2->printResidentialComplexState();
//     cout << "==============================================" << endl;

//     // REMOVE RESIDENTIAL COMPLEX
//     cout << "========= REMOVE RESIDENTIAL COMPLEX =========" << endl;
//     residentialComplex2->removeStructure();

//     cout << "\nResidential Complex 1" << endl;
//     residentialComplex1->printResidentialComplexState();
//     cout << "\nResidential Complex 2" << endl;
//     residentialComplex2->printResidentialComplexState();
//     cout << "==============================================" << endl;

//     // REMOVE ROAD
//     cout << "\nREMOVE ROAD" << endl;
//     road1->removeStructure();
//     cout << "ROAD 1" << endl;




//     std::vector<std::vector<CityStructure*> > map = cityMap->getMap();
//     cout << "City Map: " << map.size() << endl;
//     for(int i = 0; i < map.size(); i++){
//         for(int j = 0; j < map[i].size(); j++){
//             if(map[i][j] != nullptr){
//                 cout << map[i][j]->getStructureType() << " ";
//             }else{
//                 cout << "NULL ";
//             }
//         }
//         cout << endl;
//     }



//     cout << "Bye!" << endl; 

//     // =====================
//     // === GRAPHICS PART ===
//     // =====================
//     sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//     sf::CircleShape shape(100.f);
//     shape.setFillColor(sf::Color::Green);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear();
//         window.draw(shape);
//         // window.display();
//         window.display();
//     }
//     // =====================

//     return 0;
// }