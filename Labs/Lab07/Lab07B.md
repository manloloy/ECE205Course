# Lab 07B: STL Containers – Score Management System

## Objective
Practice using C++ Standard Template Library (STL) containers. You will implement a system that uses `std::vector`, `std::map`, and `std::set` to manage player scores, ensuring uniqueness and efficient lookup.

## Background
In game development and systems programming, choosing the right container is critical for performance:
- `std::vector`: Good for ordered lists and frequency-based access.
- `std::map`: Perfect for key-value pairs (e.g., looking up a score by a player's name).
- `std::set`: Useful for maintaining a sorted collection of unique values (e.g., a leaderboard of distinct high scores).

## Task
Create a "Score Manager" program that performs the following:
1. **Input:** Read a sequence of player names and their corresponding scores.
2. **Storage:**
   - Store name-score pairs in a `std::map<std::string, int>`. If a player is entered twice, update their score to the newest value.
   - Store all unique scores in a `std::set<int>` (descending order).
3. **Processing:**
   - Use a `std::vector<std::string>` to keep a log of the order in which players were added.
4. **Output:**
   - Print the list of players and their scores alphabetically.
   - Print the unique high scores in descending order.

## C++ Template

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

int main() {
    // Containers
    std::map<std::string, int> playerScores;
    std::set<int, std::greater<int>> uniqueScores; // Sorted descending
    std::vector<std::string> insertionOrder;

    std::string name;
    int score;

    std::cout << "Enter player name and score (type 'exit' 0 to stop):" << std::endl;

    while (true) {
        std::cin >> name >> score;
        if (name == "exit") break;

        // TODO: Add name to insertionOrder vector
        
        // TODO: Add/Update score in the playerScores map
        
        // TODO: Insert score into uniqueScores set
    }

    std::cout << "\n--- Alphabetical Score List ---" << std::endl;
    // TODO: Iterate through map and print "Name: Score"

    std::cout << "\n--- Unique Scores (High to Low) ---" << std::endl;
    // TODO: Iterate through set and print unique scores

    std::cout << "\n--- Insertion Log ---" << std::endl;
    // TODO: Iterate through vector and print names in the order they were entered

    return 0;
}
```
