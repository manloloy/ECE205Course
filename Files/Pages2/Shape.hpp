#pragma once
#include <SFML/Graphics.hpp>

// Abstract base for every clickable, movable shape on screen.
// Subclasses only need to say how to draw/position themselves;
// click detection and bounce physics are shared here so every
// shape gets them for free.
class Shape {
protected:
    sf::Vector2f velocity;

public:
    virtual ~Shape() = default;

    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual void setPosition(sf::Vector2f pos) = 0;
    virtual sf::Vector2f getPosition() const = 0;
    virtual sf::FloatRect getBounds() const = 0;

    void setVelocity(sf::Vector2f v);
    sf::Vector2f getVelocity() const;

    // True if mousePos falls within this shape's on-screen bounds.
    bool isClicked(sf::Vector2f mousePos) const;

    // Advances the shape by its velocity, reversing velocity on
    // whichever axis would carry it past the window edge.
    void bounce(unsigned windowWidth, unsigned windowHeight);
};
