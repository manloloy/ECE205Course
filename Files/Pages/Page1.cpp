#include "Page1.hpp"
#include "AppManager.hpp"
#include "Page2.hpp"

Page1::Page1() {
    font.loadFromFile("arial.ttf");

    nextBtn.setFont(font);
    nextBtn.setString("Next Page");
    nextBtn.setCharacterSize(24);
    nextBtn.setFillColor(sf::Color::Black);
    nextBtn.setPosition(100, 500);

    quitBtn.setFont(font);
    quitBtn.setString("Quit");
    quitBtn.setCharacterSize(24);
    quitBtn.setFillColor(sf::Color::Black);
    quitBtn.setPosition(300, 500);

    for (int i = 0; i < 5; ++i) {
        sf::CircleShape circle(30);
        circle.setFillColor(sf::Color::Blue);
        circle.setPosition(100.f * i, 200);
        objects.push_back(circle);
    }
}

bool Page1::isClicked(const sf::Text& btn, sf::Vector2f pos) {
    return btn.getGlobalBounds().contains(pos);
}

void Page1::handleEvent(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left) {
        auto mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
        if (isClicked(nextBtn, mousePos)) {
            AppManager::getInstance().changePage(std::make_unique<Page2>());
        }
        else if (isClicked(quitBtn, mousePos)) {
            AppManager::getInstance().getWindow().close();
        }
    }
}

void Page1::draw(sf::RenderWindow& window) {
    for (auto& obj : objects) {
        window.draw(obj);
    }
    window.draw(nextBtn);
    window.draw(quitBtn);
}
