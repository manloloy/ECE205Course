#pragma once
#include "Page.hpp"
#include "Shape.hpp"
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class Page2 : public Page {
private:
    sf::Font font;
    sf::Text backBtn;
    std::vector<std::unique_ptr<Shape>> shapes;

    bool isClicked(const sf::Text& btn, sf::Vector2f mousePos);

public:
    Page2();
    void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;
};
