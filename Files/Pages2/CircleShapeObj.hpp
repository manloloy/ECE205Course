#pragma once
#include "Shape.hpp"

class CircleShapeObj : public Shape {
private:
    sf::CircleShape circle;

public:
    CircleShapeObj(float radius, sf::Color color, sf::Vector2f pos);

    void draw(sf::RenderWindow& window) const override;
    void setPosition(sf::Vector2f pos) override;
    sf::Vector2f getPosition() const override;
    sf::FloatRect getBounds() const override;
};
