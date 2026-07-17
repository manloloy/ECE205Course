#pragma once
#include "Shape.hpp"

class TriangleShapeObj : public Shape {
private:
    // A CircleShape with 3 points renders as a triangle (SFML doesn't
    // have a dedicated triangle class).
    sf::CircleShape triangle;

public:
    TriangleShapeObj(float radius, sf::Color color, sf::Vector2f pos);

    void draw(sf::RenderWindow& window) const override;
    void setPosition(sf::Vector2f pos) override;
    sf::Vector2f getPosition() const override;
    sf::FloatRect getBounds() const override;
};
