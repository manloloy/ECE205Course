#include "TriangleShapeObj.hpp"

TriangleShapeObj::TriangleShapeObj(float radius, sf::Color color, sf::Vector2f pos)
    : triangle(radius, 3) {
    triangle.setFillColor(color);
    triangle.setPosition(pos);
}

void TriangleShapeObj::draw(sf::RenderWindow& window) const {
    window.draw(triangle);
}

void TriangleShapeObj::setPosition(sf::Vector2f pos) {
    triangle.setPosition(pos);
}

sf::Vector2f TriangleShapeObj::getPosition() const {
    return triangle.getPosition();
}

sf::FloatRect TriangleShapeObj::getBounds() const {
    return triangle.getGlobalBounds();
}
