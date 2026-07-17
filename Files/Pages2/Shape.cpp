#include "Shape.hpp"

void Shape::setVelocity(sf::Vector2f v) {
    velocity = v;
}

sf::Vector2f Shape::getVelocity() const {
    return velocity;
}

bool Shape::isClicked(sf::Vector2f mousePos) const {
    return getBounds().contains(mousePos);
}

void Shape::bounce(unsigned windowWidth, unsigned windowHeight) {
    sf::FloatRect bounds = getBounds();
    sf::Vector2f nextTopLeft(bounds.left + velocity.x, bounds.top + velocity.y);

    if (nextTopLeft.x < 0 || nextTopLeft.x + bounds.width > windowWidth) {
        velocity.x = -velocity.x;
    }
    if (nextTopLeft.y < 0 || nextTopLeft.y + bounds.height > windowHeight) {
        velocity.y = -velocity.y;
    }

    setPosition(getPosition() + velocity);
}
