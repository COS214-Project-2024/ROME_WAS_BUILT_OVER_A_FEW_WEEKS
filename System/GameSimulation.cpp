#include "GameSimulation.h"
#include "CityStructure.h"
#include "CityMap.h"
#include "CityHall.h"

#include <iostream>


GameSimulation::GameSimulation(CityHall *cityHall, CityMap *cityMap){
    // Set references to game objects
    this->cityHall = cityHall;
    this->cityMap = cityMap;

    // Create window
    window = new sf::RenderWindow(sf::VideoMode(1120, 630), "Rome Was Built In a Day", sf::Style::Close);
    timePerFrame = sf::seconds(1.f / 60.f);

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
}


void GameSimulation::gameRun(){
    sf::Clock clock;
    sf::Time elapsed = sf::Time::Zero;

    int j = 0;

    // Run game simulation while the window is open
    while (window->isOpen()){
        j += 1;
        std::cout << j << std::endl;

        // === PROCESS EVENTS ===
        processEvents();

        // Force the game to run at 60fps
        elapsed += clock.restart();

        while (elapsed >= timePerFrame){
            elapsed -= timePerFrame;
            update(timePerFrame);
        }


        // === DRAW THE FRAME ===
        drawFrame();
    }
}


void GameSimulation::processEvents(){
    sf::Event curEvent; // Create an event object

    while (window->pollEvent(curEvent)){ // We then poll this event (which means we "get" all events that happened in between the previous frame and now)

        // We then go through all the events and handle them (we specify what should happen based on the event that has occured)
        switch (curEvent.type){
            case sf::Event::Closed:
                window->close();
                break;
        }

    }

}


void GameSimulation::update(sf::Time deltaTime){
    return;
}


void GameSimulation::drawFrame(){
    // Clear the frame
    window->clear();

    // CITYMAP 2D VECTOR
    std::vector<std::vector<CityStructure*>> map = cityMap->getMap();

    // Iterate over each row in the 2D vector
    for (std::vector<CityStructure*>& row : map) {

        for (CityStructure* structure : row) {

            if (structure != NULL) {
                if (structure->getStructureType() == "Road"){
                    // Determine which road to use as a texture based on the other roads around it
                    std::string roadTexture = "Road1";
                    if (structure->getX() > 0 && map[structure->getY()][structure->getX() - 1] != NULL && map[structure->getY()][structure->getX() - 1]->getStructureType() == "Road"){
                        roadTexture = "Road2";
                    }else if (structure->getY() > 0 && map[structure->getY() - 1][structure->getX()] != NULL && map[structure->getY() - 1][structure->getX()]->getStructureType() == "Road"){
                        roadTexture = "Road3";
                    }else if (structure->getX() < map[0].size() - 1 && map[structure->getY()][structure->getX() + 1] != NULL && map[structure->getY()][structure->getX() + 1]->getStructureType() == "Road"){
                        roadTexture = "Road4";
                    }

                    structure->sprite->setTexture(textures[roadTexture]);
                    window->draw(*(structure->sprite));
                }else if (structure->getStructureType() == "ResidentialComplex"){

                }else{
                    structure->sprite->setTexture(textures[structure->getStructureType()]);
                    window->draw(*(structure->sprite));
                }
            }else{
                // Draw a landscape
                sf::Sprite landscape;
                landscape.setTexture(textures["Landscape1"]);
                //landscape.setPosition(x*128 + 128, y*128 + 128);
                landscape.setScale(2, 2);
                window->draw(landscape);
            }
        }
    }

    window->display();
}
