# Lab 06C: Recursive Flood Fill

## Objective
Implement a recursive **Flood Fill** algorithm. This lab demonstrates how recursion is used in real-world applications like the "bucket fill" tool in paint programs, pathfinding, or identifying connected regions in image processing.

## Background
Flood fill starts at a specific node (pixel) and "spreads" to all connected nodes that share the same target color. 

A recursive flood fill follows this logic:
1. **Base Case 1:** If the current coordinates are out of bounds, return.
2. **Base Case 2:** If the current node is not the color we want to replace, return.
3. **Base Case 3:** If the current node is already the new color, return (to avoid infinite loops).
4. **Recursive Step:** 
   - Change the color of the current node.
   - Call the function recursively for the nodes immediately **North, South, East, and West**.

## Task
You are provided with a 10x10 grid representing a simple "map." Your task is to implement the `floodFill` function. The program will take a starting `(x, y)` coordinate and a "new color" character from the user, then fill the connected region.

## C++ Template

```cpp
#include <iostream>
#include <vector>

const int WIDTH = 10;
const int HEIGHT = 10;

// The Grid
char screen[HEIGHT][WIDTH] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '#', '#', '.', '#'},
    {'#', '#', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '.', '#', '#', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

void printScreen() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            std::cout << screen[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * Recursive Flood Fill
 * @param x current x-coordinate (column)
 * @param y current y-coordinate (row)
 * @param targetColor the color we are looking to replace
 * @param replacementColor the color we are changing to
 */
void floodFill(int x, int y, char targetColor, char replacementColor) {
    // TODO: Implement Base Cases
    // 1. Check if (x, y) is out of bounds
    // 2. Check if screen[y][x] is not the targetColor
    // 3. Check if screen[y][x] is already the replacementColor

    // TODO: Implement Recursive Step
    // 1. Change the color at current (x, y)
    // 2. Recursively call floodFill for Up, Down, Left, and Right
}

int main() {
    std::cout << "Original Map:" << std::endl;
    printScreen();

    int startX, startY;
    char newColor;

    std::cout << "\nEnter starting X (0-9): ";
    std::cin >> startX;
    std::cout << "Enter starting Y (0-9): ";
    std::cin >> startY;
    std::cout << "Enter replacement character: ";
    std::cin >> newColor;

    char target = screen[startY][startX];
    floodFill(startX, startY, target, newColor);

    std::cout << "\nMap After Flood Fill:" << std::endl;
    printScreen();

    return 0;
}
```
