#pragma once
#include "Page.hpp"
#include "Shape.hpp"
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class Page1 : public Page {
private:
    sf::Font font;
    sf::Text nextBtn, quitBtn;
    std::vector<std::unique_ptr<Shape>> objects;

    bool isClicked(const sf::Text& btn, sf::Vector2f mousePos);

public:
    Page1();
    void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;
};
