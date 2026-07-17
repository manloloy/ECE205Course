#pragma once
#include "Shape.hpp"
#include <memory>

// Creates a random concrete Shape (circle/rectangle/triangle) with a
// random size and color, positioned at pos with the given velocity.
std::unique_ptr<Shape> createRandomShape(sf::Vector2f pos, sf::Vector2f velocity);

// A random per-axis velocity, shared so every page's shapes move at
// the same speed.
sf::Vector2f randomVelocity();
