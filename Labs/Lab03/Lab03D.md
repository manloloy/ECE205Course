# Lab 03D: SFML Visual Catalog and State Management

## Objective

Build a graphical user interface (GUI) for the Book Catalog using the SFML library. Students will implement a state management system to handle "Undo" and "Redo" operations by capturing snapshots of the catalog data.

- Integrate the SFML library into a C++ project.
- Implement a basic state machine for Undo/Redo logic.
- Use `std::vector<std::vector<T>>` to manage a history of object states.
- Manage GUI interaction via keyboard events.

## Task

Create an SFML application that displays a list of book titles. The program must support the following:

1.  **Rendering:** Display the titles of all books currently in the `std::vector<Book>`.
2.  **Add/Remove:**
    *   **Add:** Pressing 'A' adds a generic book title (e.g., "Book #" + count).
    *   **Remove:** Pressing 'R' removes the last book in the list.
3.  **State Management (Undo/Redo):**
    *   **History:** Before any Add or Remove operation, save the current `std::vector<Book>` into a `history` vector.
    *   **Undo:** Pressing 'U' reverts the catalog to the last state in `history`. Move the current state to a `redoStack` before reverting.
    *   **Redo:** Pressing 'D' restores the state from `redoStack`.
    *   **Branching:** If a new Add/Remove operation occurs, clear the `redoStack`.
4.  **Constraint:** Limit the history size to 5 snapshots. If a 6th snapshot is added, remove the oldest one from the front of the vector.

## Key Logic

To manage history, use a vector of vectors:
`std::vector<std::vector<Book>> history;`

Every time the user modifies the catalog:
1. Clear the `redoStack`.
2. Push the current state to the `history`.
3. If `history.size() > 5`, `history.erase(history.begin())`.

## C++ Template

```cpp
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

struct Book {
    std::string title;
};

void DrawCatalog(sf::RenderWindow& window, const std::vector<Book>& catalog, sf::Font& font) {
    for (size_t i = 0; i < catalog.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(catalog[i].title);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        text.setPosition(50.f, 50.f + (i * 30.f));
        window.draw(text);
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Visual Book Catalog");
    sf::Font font;
    
    // Ensure you have arial.ttf in your project directory
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return -1; 
    }

    std::vector<Book> catalog;
    std::vector<std::vector<Book>> history;
    std::vector<std::vector<Book>> redoStack;
    const size_t MAX_HISTORY = 5;
    int bookCount = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    // TODO: Save state to history, clear redoStack, add new book
                }
                if (event.key.code == sf::Keyboard::R && !catalog.empty()) {
                    // TODO: Save state to history, clear redoStack, remove last book
                }
                if (event.key.code == sf::Keyboard::U && !history.empty()) {
                    // TODO: Push current to redoStack, set current to history.back(), pop history
                }
                if (event.key.code == sf::Keyboard::D && !redoStack.empty()) {
                    // TODO: Push current to history, set current to redoStack.back(), pop redoStack
                }
            }
        }

        window.clear(sf::Color::Black);
        DrawCatalog(window, catalog, font);
        
        sf::Text instr;
        instr.setFont(font);
        instr.setCharacterSize(15);
        instr.setString("A: Add | R: Remove | U: Undo | D: Redo");
        instr.setPosition(10.f, 570.f);
        window.draw(instr);

        window.display();
    }

    return 0;
}
```

# Compiling & Running (Try both options)
The instructions below assume your code is in main.cpp. You can replace main.cpp with <yourfilename>.cpp in the commands and in the Makefile below.

## Option 1: Direct Command Line
To compile from the terminal, use the following command (ensure you are in the directory containing main.cpp and arial.ttf):
```bash
g++ main.cpp -o catalog -lsfml-graphics -lsfml-window -lsfml-system
./catalog
```

## option 2: Makefile
Create a file named Makefile in your project directory with the following content:
```bash
CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: catalog

catalog: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o catalog $(LDFLAGS)

clean:
	rm -f catalog
```
To build and run:
```bash
make
./catalog
```
