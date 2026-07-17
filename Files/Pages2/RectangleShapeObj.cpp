#include "RectangleShapeObj.hpp"

RectangleShapeObj::RectangleShapeObj(sf::Vector2f size, sf::Color color, sf::Vector2f pos)
    : rectangle(size) {
    rectangle.setFillColor(color);
    rectangle.setPosition(pos);
}

void RectangleShapeObj::draw(sf::RenderWindow& window) const {
    window.draw(rectangle);
}

void RectangleShapeObj::setPosition(sf::Vector2f pos) {
    rectangle.setPosition(pos);
}

sf::Vector2f RectangleShapeObj::getPosition() const {
    return rectangle.getPosition();
}

sf::FloatRect RectangleShapeObj::getBounds() const {
    return rectangle.getGlobalBounds();
}
