#ifndef GAME_SIMULATION_H
#define GAME_SIMULATION_H

class CityMap;
class CityHall;

#include <map>
#include <SFML/Graphics.hpp>

class GameSimulation{
    public:
        GameSimulation(CityHall* cityHall, CityMap* cityMap);
        void gameRun();

        // Textures
        std::map<std::string, sf::Texture> textures;

        // Game values
        float imageScale = 1;


    private:
        // Reference to main buildings
        CityHall* cityHall;
        CityMap* cityMap;

        // Graphics
        sf::RenderWindow* window;
        sf::Time timePerFrame;

        // Game handling
        void processEvents(); // User inputs
        void update(sf::Time deltaTime);
        void drawFrame();


};

#endif