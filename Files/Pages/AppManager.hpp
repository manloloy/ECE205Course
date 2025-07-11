#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Page;

class AppManager {
private:
    sf::RenderWindow window;
    std::unique_ptr<Page> currentPage;

    AppManager(); // Private constructor for Singleton

public:
    static AppManager& getInstance(); // Singleton access

    void run();
    void changePage(std::unique_ptr<Page> newPage);
    sf::RenderWindow& getWindow();
};
