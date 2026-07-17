#include "ShapeFactory.hpp"
#include "CircleShapeObj.hpp"
#include "RectangleShapeObj.hpp"
#include "TriangleShapeObj.hpp"
#include <cstdlib>

namespace {
    sf::Color randomColor() {
        return sf::Color(rand() % 256, rand() % 256, rand() % 256);
    }

    float randomSpeedComponent() {
        // 0.5-1.25, i.e. 1/4 of the original 2-5 speed range.
        float speed = (2.f + (rand() % 4)) / 4.f;
        return (rand() % 2 == 0) ? speed : -speed;
    }
}

sf::Vector2f randomVelocity() {
    return sf::Vector2f(randomSpeedComponent(), randomSpeedComponent());
}

std::unique_ptr<Shape> createRandomShape(sf::Vector2f pos, sf::Vector2f velocity) {
    int type = rand() % 3;
    float size = 20.f + (rand() % 20); // 20-39
    sf::Color color = randomColor();

    std::unique_ptr<Shape> shape;
    switch (type) {
        case 0:
            shape = std::make_unique<CircleShapeObj>(size, color, pos);
            break;
        case 1:
            shape = std::make_unique<RectangleShapeObj>(sf::Vector2f(size * 2.f, size * 2.f), color, pos);
            break;
        default:
            shape = std::make_unique<TriangleShapeObj>(size, color, pos);
            break;
    }

    shape->setVelocity(velocity);
    return shape;
}
