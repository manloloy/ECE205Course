#pragma once
#include "Shape.hpp"

class RectangleShapeObj : public Shape {
private:
    sf::RectangleShape rectangle;

public:
    RectangleShapeObj(sf::Vector2f size, sf::Color color, sf::Vector2f pos);

    void draw(sf::RenderWindow& window) const override;
    void setPosition(sf::Vector2f pos) override;
    sf::Vector2f getPosition() const override;
    sf::FloatRect getBounds() const override;
};
