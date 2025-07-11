#include "Page2.hpp"
#include "AppManager.hpp"
#include "Page1.hpp"

Page2::Page2() {
    font.loadFromFile("arial.ttf");

    backBtn.setFont(font);
    backBtn.setString("Back");
    backBtn.setCharacterSize(24);
    backBtn.setFillColor(sf::Color::Black);
    backBtn.setPosition(100, 500);

    sf::RectangleShape panel(sf::Vector2f(300, 200));
    panel.setFillColor(sf::Color::Green);
    panel.setPosition(250, 150);
    panels.push_back(panel);
}

bool Page2::isClicked(const sf::Text& btn, sf::Vector2f pos) {
    return btn.getGlobalBounds().contains(pos);
}

void Page2::handleEvent(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left) {
        auto mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
        if (isClicked(backBtn, mousePos)) {
            AppManager::getInstance().changePage(std::make_unique<Page1>());
        }
    }
}

void Page2::draw(sf::RenderWindow& window) {
    for (auto& panel : panels) {
        window.draw(panel);
    }
    window.draw(backBtn);
}
