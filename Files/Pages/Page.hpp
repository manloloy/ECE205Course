#pragma once
#include <SFML/Graphics.hpp>

class AppManager; // Forward declaration

class Page {
public:
    virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual ~Page() = default;
};
