#ifndef GAME_SIMULATION_H
#define GAME_SIMULATION_H

class CityMap;
class CityHall;

#include <SFML/Graphics.hpp>

class GameSimulation{
    public:
        GameSimulation(CityHall* cityHall, CityMap* cityMap);
        // void gameRun();
    private:
        // Reference to main buildings
        CityHall* cityHall;
        CityMap* cityMap;

        // Graphics
        sf::RenderWindow* window;
        sf::Time timePerFrame;

        // // Game handling
        // void processEvents(); // User inputs
        // void update(sf::Time deltaTime);
        // void drawFrame();
};

#endif