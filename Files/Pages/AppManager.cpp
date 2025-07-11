#include "AppManager.hpp"
#include "Page1.hpp"

AppManager::AppManager() : window(sf::VideoMode(800, 600), "Singleton App") {
    currentPage = std::make_unique<Page1>();
}

AppManager& AppManager::getInstance() {
    static AppManager instance;
    return instance;
}

void AppManager::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            currentPage->handleEvent(event, window);
        }

        currentPage->update();

        window.clear(sf::Color::White);
        currentPage->draw(window);
        window.display();
    }
}

void AppManager::changePage(std::unique_ptr<Page> newPage) {
    currentPage = std::move(newPage);
}

sf::RenderWindow& AppManager::getWindow() {
    return window;
}
