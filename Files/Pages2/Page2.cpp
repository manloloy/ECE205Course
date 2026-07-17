#include "Page2.hpp"
#include "AppManager.hpp"
#include "Page1.hpp"
#include "ShapeFactory.hpp"
#include <cstdlib>

namespace {
    int randomShapeCount() {
        return 5 + (rand() % 11); // 5-15 inclusive
    }
}

Page2::Page2() {
    font.loadFromFile("arial.ttf");

    backBtn.setFont(font);
    backBtn.setString("Back");
    backBtn.setCharacterSize(24);
    backBtn.setFillColor(sf::Color::Black);
    backBtn.setPosition(100, 500);

    int count = randomShapeCount();
    for (int i = 0; i < count; ++i) {
        sf::Vector2f pos(50.f + (rand() % 650), 50.f + (rand() % 400));
        shapes.push_back(createRandomShape(pos, randomVelocity()));
    }
}

bool Page2::isClicked(const sf::Text& btn, sf::Vector2f pos) {
    return btn.getGlobalBounds().contains(pos);
}

void Page2::handleEvent(sf::Event& event, sf::RenderWindow& window) {
    if (event.type != sf::Event::MouseButtonPressed ||
        event.mouseButton.button != sf::Mouse::Left) {
        return;
    }

    auto mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

    if (isClicked(backBtn, mousePos)) {
        AppManager::getInstance().changePage(std::make_unique<Page1>());
        return; // this Page2 has just been destroyed; touch nothing else
    }

    for (auto it = shapes.begin(); it != shapes.end(); ++it) {
        if ((*it)->isClicked(mousePos)) {
            shapes.erase(it);
            break;
        }
    }

    if (shapes.empty()) {
        AppManager::getInstance().changePage(std::make_unique<Page1>());
        return; // this Page2 has just been destroyed; touch nothing else
    }
}

void Page2::update() {
    sf::Vector2u size = AppManager::getInstance().getWindow().getSize();
    for (auto& shape : shapes) {
        shape->bounce(size.x, size.y);
    }
}

void Page2::draw(sf::RenderWindow& window) {
    for (auto& s : shapes) {
        s->draw(window);
    }
    window.draw(backBtn);
}
