#include "GameSimulation.h"

GameSimulation::GameSimulation(CityHall *cityHall, CityMap *cityMap){
    // Set references
    this->cityHall = cityHall;
    this->cityMap = cityMap;

    // Create window and graphics-related
    window = new sf::RenderWindow(sf::VideoMode(1280, 960), "Rome Was Built In a Day", sf::Style::Close | sf::Style::Resize);
    timePerFrame = sf::seconds(1.f / 60.f);
}