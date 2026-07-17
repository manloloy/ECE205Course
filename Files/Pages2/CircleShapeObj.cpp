#include "CircleShapeObj.hpp"

CircleShapeObj::CircleShapeObj(float radius, sf::Color color, sf::Vector2f pos)
    : circle(radius) {
    circle.setFillColor(color);
    circle.setPosition(pos);
}

void CircleShapeObj::draw(sf::RenderWindow& window) const {
    window.draw(circle);
}

void CircleShapeObj::setPosition(sf::Vector2f pos) {
    circle.setPosition(pos);
}

sf::Vector2f CircleShapeObj::getPosition() const {
    return circle.getPosition();
}

sf::FloatRect CircleShapeObj::getBounds() const {
    return circle.getGlobalBounds();
}
