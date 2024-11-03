#include "GameSimulation.h"
#include "CityStructure.h"
#include "CityMap.h"
#include "CityHall.h"

#include <iostream>
#include <random>

#include "Factory.h"
#include "GeneratorDecorator.h"
#include "ConcreteGenerator.h"
#include "SteelGenerator.h"
#include "WoodGenerator.h"
#include "Material.h"
#include "Concrete.h"
#include "Steel.h"
#include "Wood.h"
#include "Plant.h"
#include "PlantDecorator.h"
#include "PowerPlant.h"
#include "WaterPlant.h"
#include "WastePlant.h"
#include "SewagePlant.h"

#include "CityMap.h"
#include "CityHall.h"

// BUILDING TYPES
#include "CityStructure.h"  
#include "Road.h"
#include "ResidentialComplex.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "IndustrialBuilding.h"
#include "Landmark.h"

// RESIDENTIAL BUILDING TYPES
#include "House.h"
#include "Apartment.h"
#include "Townhouse.h"
#include "Estate.h"

// COMMERCIAL BUILDING TYPES
#include "Shop.h"
#include "Mall.h"
#include "Office.h"

// INDUSTRIAL BUILDING TYPES
#include "Plant.h"
#include "Factory.h"
#include "Warehouse.h"

// LANDMARK TYPES
#include "Colosseum.h"
#include "Pantheon.h"
#include "Park.h"

#include <iostream>
#include <random>

#include <thread>
#include <chrono>


GameSimulation::GameSimulation(CityHall *cityHall, CityMap *cityMap) {
    // Set references to game objects
    this->cityHall = cityHall;
    this->cityMap = cityMap;

    // Create window (no need to use new)
    window.create(sf::VideoMode(1120, 630), "Rome Was Built In a Day", sf::Style::Close);
    timePerFrame = sf::seconds(1.f / 60.f);

    // Sleep
    //std::this_thread::sleep_for(std::chrono::seconds(8));

    // Viewport (cameraView as a regular member)
    cameraView.setSize(1120, 630);
    cameraView.setCenter(1120 / 2, 630 / 2);
    window.setView(cameraView);

    // Load textures
    textures["Apartment"].loadFromFile("../images/spr_Apartment.png");
    textures["CityHall"].loadFromFile("../images/spr_CityHall.png");
    textures["Estate"].loadFromFile("../images/spr_Estate.png");
    textures["Factory"].loadFromFile("../images/spr_Factory.png");
    textures["House"].loadFromFile("../images/spr_House.png");
    textures["Landscape1"].loadFromFile("../images/spr_Landscape1.png");
    textures["Landscape2"].loadFromFile("../images/spr_Landscape2.png");
    textures["Landscape3"].loadFromFile("../images/spr_Landscape3.png");
    textures["Monument"].loadFromFile("../images/spr_Monument.png");
    textures["Office"].loadFromFile("../images/spr_Office.png");
    textures["Park"].loadFromFile("../images/spr_Park.png");
    textures["PlantStrip"].loadFromFile("../images/spr_Plant_strip.png");
    textures["Road1"].loadFromFile("../images/spr_Road1.png");
    textures["Road2"].loadFromFile("../images/spr_Road2.png");
    textures["Road3"].loadFromFile("../images/spr_Road3.png");
    textures["Road4"].loadFromFile("../images/spr_Road4.png");
    textures["Shop"].loadFromFile("../images/spr_Shop.png");
    textures["TownHouse"].loadFromFile("../images/spr_TownHouse.png");
    textures["Warehouse"].loadFromFile("../images/spr_Warehouse.png");
    textures["Border1"].loadFromFile("../images/spr_Border1.png");
    textures["Border2"].loadFromFile("../images/spr_Border2.png");

    //std::this_thread::sleep_for(std::chrono::seconds(2));

    // Create the map
    createMap();

    // Create world border
    float worldWidth = myMap[0].size() * 128.f + 256.f;
    float worldHeight = myMap.size() * 128.f + 256.f;

    // Top and bottom borders
    for (int i = 0; i < myMap[0].size(); i++) {
        sf::Sprite borderTop;
        sf::Sprite borderBottom;

        borderTop.setTexture(textures["Border1"]);
        borderBottom.setTexture(textures["Border1"]);
        borderBottom.setRotation(180);

        borderTop.setScale(2, 2);
        borderBottom.setScale(2, 2);

        borderTop.setPosition(128.f + i * 128, 0);
        borderBottom.setPosition(256.f + i * 128, worldHeight);

        borderMap.push_back(borderTop);
        borderMap.push_back(borderBottom);
    }

    // Left and right borders
    for (int i = 0; i < myMap.size(); i++) {
        sf::Sprite borderLeft;
        sf::Sprite borderRight;

        borderLeft.setTexture(textures["Border1"]);
        borderLeft.setRotation(-90);
        borderRight.setTexture(textures["Border1"]);
        borderRight.setRotation(90);

        borderLeft.setScale(2, 2);
        borderRight.setScale(2, 2);

        borderLeft.setPosition(0, 256.f + i * 128);
        borderRight.setPosition(worldWidth, i * 128 + 128);

        borderMap.push_back(borderLeft);
        borderMap.push_back(borderRight);
    }

    // Corners
    sf::Sprite topLeft;
    sf::Sprite topRight;
    sf::Sprite bottomLeft;
    sf::Sprite bottomRight;

    topLeft.setTexture(textures["Border2"]);
    topRight.setTexture(textures["Border2"]);
    bottomLeft.setTexture(textures["Border2"]);
    bottomRight.setTexture(textures["Border2"]);

    topLeft.setRotation(-90);
    topRight.setRotation(0);
    bottomLeft.setRotation(180);
    bottomRight.setRotation(90);

    topLeft.setScale(2, 2);
    topRight.setScale(2, 2);
    bottomLeft.setScale(2, 2);
    bottomRight.setScale(2, 2);

    topLeft.setPosition(0, 128.f);
    topRight.setPosition(worldWidth - 128, 0);
    bottomLeft.setPosition(128, worldHeight);
    bottomRight.setPosition(worldWidth, worldHeight - 128);

    borderMap.push_back(topLeft);
    borderMap.push_back(topRight);
    borderMap.push_back(bottomLeft);
    borderMap.push_back(bottomRight);

}


void GameSimulation::createMap() {
    std::vector<std::vector<CityStructure*>> map = cityMap->getMap();
    int numRows = map.size();
    int numCols = map[0].size();
    myMap = std::vector<std::vector<CityItem>>(numRows, std::vector<CityItem>(numCols));

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            CityStructure* structure = map[row][col];
            if (structure != nullptr) {
                myMap[row][col].type = structure->getStructureType();
                std::string textureKey = determineTexture(structure, map);
                myMap[row][col].sprite.setTexture(textures[textureKey]);
                myMap[row][col].sprite.setPosition(col * 128 + 128, row * 128 + 128);
                myMap[row][col].sprite.setScale(2.0f, 2.0f);
            } else {
                myMap[row][col].type = "Landscape";
                int landscapeTexture = randomLandscapeTexture();
                myMap[row][col].sprite.setTexture(textures["Landscape" + std::to_string(landscapeTexture)]);
                myMap[row][col].sprite.setPosition(col * 128 + 128, row * 128 + 128);
                myMap[row][col].sprite.setScale(2.0f, 2.0f);
            }
        }
    }
}


std::string GameSimulation::determineTexture(CityStructure* structure, const std::vector<std::vector<CityStructure*> >& map) {
    if (structure->getStructureType() == "Road") {
        std::string roadTexture = "Road1";
        int x = structure->getX();
        int y = structure->getY();

        // Check neighbors to determine road type
        if (x > 0 && map[y][x - 1] != nullptr && map[y][x - 1]->getStructureType() == "Road") {
            roadTexture = "Road2";
        } else if (y > 0 && map[y - 1][x] != nullptr && map[y - 1][x]->getStructureType() == "Road") {
            roadTexture = "Road3";
        } else if (x < map[0].size() - 1 && map[y][x + 1] != nullptr && map[y][x + 1]->getStructureType() == "Road") {
            roadTexture = "Road4";
        }
        return roadTexture;
    }

    // Otherwise, return texture based on structure type
    return structure->getStructureType();
}


int GameSimulation::randomLandscapeTexture() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 3);
    return dis(gen);
}




void GameSimulation::gameRun() {
    sf::Time frameLimit = sf::milliseconds(20);  // Roughly 60 FPS
    sf::Clock frameClock;

    while (window.isOpen()) {
        processEvents();
        update();
        drawFrame();

        sf::Time frameTime = frameClock.getElapsedTime();
        if (frameTime < frameLimit) {
            sf::Time timeToSleep = frameLimit - frameTime;
            std::this_thread::sleep_for(std::chrono::milliseconds(timeToSleep.asMilliseconds()));
        }
        frameClock.restart();
    }
}



void GameSimulation::processEvents(){
    sf::Event curEvent; // Create an event object

    while (window.pollEvent(curEvent)){ // We then poll this event (which means we "get" all events that happened in between the previous frame and now)

        // We then go through all the  events and handle them (we specify what should happen based on the event that has occured)
        switch (curEvent.type){
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (curEvent.key.code == sf::Keyboard::Num1){

                        std::vector<std::vector<CityStructure*> > map1 = cityMap->getMap();
                        cout << "CITY MAP: " << map1.size() << endl;
                        for(int i = 0; i < map1.size(); i++){
                            for(int j = 0; j < map1[i].size(); j++){
                                if(map1[i][j] != nullptr){
                                    cout << map1[i][j]->getStructureType() << " ";
                                }else{
                                    cout << "NULL ";
                                }
                            }
                            cout << endl;
                        }


                        cout << "MINE: " << myMap.size() << endl;
                        for(int i = 0; i < myMap.size(); i++){
                            for(int j = 0; j < myMap[i].size(); j++){
                                if(myMap[i][j].type != "Landscape"){
                                    cout << myMap[i][j].type << " ";
                                }else{
                                    cout << "Landscape ";
                                }
                            }
                            cout << endl;
                        }




                    // CREATE AND PLACE ROADS
                    Road* road1 = new Road();
                    road1->placeStructure(0, 1, cityMap);
                    Road* road2 = new Road();
                    road2->placeStructure(1, 1, cityMap);
                    Road* road3 = new Road();
                    road3->placeStructure(2, 1, cityMap);



                        std::vector<std::vector<CityStructure*> > map2 = cityMap->getMap();
                        cout << "CITY MAP: " << map2.size() << endl;
                        for(int i = 0; i < map2.size(); i++){
                            for(int j = 0; j < map2[i].size(); j++){
                                if(map2[i][j] != nullptr){
                                    cout << map2[i][j]->getStructureType() << " ";
                                }else{
                                    cout << "NULL ";
                                }
                            }
                            cout << endl;
                        }


                        cout << "MINE: " << myMap.size() << endl;
                        for(int i = 0; i < myMap.size(); i++){
                            for(int j = 0; j < myMap[i].size(); j++){
                                if(myMap[i][j].type != "Landscape"){
                                    cout << myMap[i][j].type << " ";
                                }else{
                                    cout << "Landscape ";
                                }
                            }
                            cout << endl;
                        }

                }

                break;
        }

    }

}


void GameSimulation::update() {
    const float cameraSpeed = 200.0f;
    sf::Vector2f cameraMove(0.f, 0.f);

    // World boundaries
    float worldWidth = myMap[0].size() * 128.f + 256.f;
    float worldHeight = myMap.size() * 128.f + 256.f;

    // Check keyboard input for camera movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        cameraMove.x -= cameraSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        cameraMove.x += cameraSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        cameraMove.y -= cameraSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        cameraMove.y += cameraSpeed;
    }

    // Move the camera view
    cameraView.move(cameraMove);

    // Get the camera's new center position after movement
    sf::Vector2f cameraCenter = cameraView.getCenter();

    // Calculate the camera boundaries
    float halfWidth = cameraView.getSize().x / 2.f;
    float halfHeight = cameraView.getSize().y / 2.f;

    // Clamp the camera's position within the game world bounds
    cameraCenter.x = std::clamp(cameraCenter.x, halfWidth, worldWidth - halfWidth);
    cameraCenter.y = std::clamp(cameraCenter.y, halfHeight, worldHeight - halfHeight);

    // Apply the clamped center to the camera view
    cameraView.setCenter(cameraCenter);

    // Apply the updated camera view to the window
    window.setView(cameraView);
}


void GameSimulation::drawFrame() {
    window.setActive(true);
    // Clear the window for the new frame
    window.clear();

    // Draw Border
    for (int i = 0; i < borderMap.size(); i++){
        window.draw(borderMap[i]);
    }

    // Get the current city map data
    std::vector<std::vector<CityStructure*> > map = cityMap->getMap();

    // Iterate through each cell in the map
    for (int row = 0; row < map.size(); ++row) {
        for (int col = 0; col < map[row].size(); ++col) {
            CityStructure* structure = map[row][col];
            CityItem& cityItem = myMap[row][col];

            // Check if there's a structure in the cell
            if (structure != nullptr) {
                // Check if the type has changed
                if (structure->getStructureType() != cityItem.type) {
                    // Update CityItem with the new structure type and texture
                    cityItem.type = structure->getStructureType();
                    cityItem.sprite.setTexture(textures[cityItem.type]);

                    // Optionally adjust the sprite position based on row/col
                    cityItem.sprite.setPosition(col * 128 + 128, row * 128 + 128);
                }

                // Additional logic for road texture changes based on neighbors
                if (cityItem.type == "Road") {
                    std::string roadTexture = determineTexture(structure, map);
                    cityItem.sprite.setTexture(textures[roadTexture]);
                }
            } else {
                // Handle landscape tiles if there’s no structure
                if (cityItem.type != "Landscape") {
                    // Assign a random landscape texture
                    cityItem.type = "Landscape";
                    int landscapeTexture = randomLandscapeTexture();
                    cityItem.sprite.setTexture(textures["Landscape" + std::to_string(landscapeTexture)]);
                    cityItem.sprite.setPosition(col * 128 + 128, row * 128 + 128);
                }
            }

            // Draw the sprite for each CityItem in myMap
            window.draw(cityItem.sprite);

        }
    }

    // Display the frame
    window.display();
}
