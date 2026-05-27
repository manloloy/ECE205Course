# Lab09A: Capstone Project - Extra Credit

# Virtual Pet Simulator 

## Overview

In this capstone lab, you will design and implement a **Virtual Pet Simulator** that incorporates many of the major C++ concepts covered in this course: classes, inheritance, composition, operator overloading, file I/O with JSON, templates, and behavior scripting. The goal is to simulate customizable virtual pets defined using scriptable JSON data, and to allow dynamic updates and interactions such as breeding and behavioral extensions.

This project will be developed in stages. You are given a base structure to ensure consistency across submissions. However, most implementation will be left to you, following clearly defined design goals.

---

## Objectives

- Use **class inheritance** to model different species or types of pets.
- Implement **composition** to give pets customizable stats (e.g. health, mood, hunger).
- **Overload operators** to support breeding of two pets to form a new pet.
- Use **JSON files** to read/write pet definitions and simulate scriptable object behavior.
- Create an **editor mode** to update pet data interactively and persist to disk.
- Optionally support **template-based features** or **behavior scripting**.

---

## Base File Structure

```
VirtualPetSimulator/
├── main.cpp
├── pet.hpp
├── pet.cpp
├── stats.hpp
├── stats.cpp
├── data/
│   └── pets.json
├── include/
│   └── json.hpp
├── makefile
```

---

## Stage 1: Define the Pet and Stats Classes

Implement two core classes:

### `Stats` class (composition):
- Fields: `int health`, `int hunger`, `int happiness`
- Methods:
  - Getters/setters
  - `void update()` – applies simple changes over time (e.g., decrease happiness, increase hunger)

### `Pet` class:
- Fields: `std::string name`, `std::string species`, `Stats stats`
- Methods:
  - `void update()` – calls `stats.update()` and prints the pet's state
  - `void interact()` – user interaction that improves pet happiness
  - Overload `operator+` to simulate **breeding** two pets. The offspring gets:
    - Name: `"ChildOf_" + parent1.name + "_" + parent2.name`
    - Species: a hybrid (e.g., `"Mix"` or a randomized blend)
    - Stats: randomly inherited stats from parents

---

## Stage 2: Loading Pets from JSON

You must write a function that loads an array of pets from `data/pets.json`. Each entry should look like:

```json
{
  "name": "Milo",
  "species": "Cat",
  "stats": {
    "health": 100,
    "hunger": 20,
    "happiness": 80
  }
}
```

Store each pet in a `std::vector<Pet*>`. Support a save function to write these pets back to JSON (used in Editor mode).

---

## Stage 3: Editor Mode

Add a text-based **editor mode** to:

- View all pets loaded
- Modify a pet’s name, stats, or species
- Add new pets from scratch
- Save changes to `pets.json`

Use command-line prompts and loops. Each edit should be reflected in memory and saved when the user chooses to write back.

---

## Stage 4: Breeding System

Enable users to breed any two existing pets. The result is:

- A new `Pet` generated via `Pet operator+(Pet&)`
- Random inheritance of stats from each parent
- Appended to the list of current pets
- Saved to `pets.json` when requested

---

## Optional Extensions

- **Behavior Scripting:** Define simple scripts in a file like `behaviors.txt` with rules such as:
  ```
  if hunger > 70: happiness -= 10
  if happiness < 40: health -= 5
  ```
  Parse and apply these rules in the `update()` method.

- **Template Utility Functions:**
  - Write a template function `MostHungry<T>` that accepts a `vector<T*>` and returns the pet with the highest hunger.

---

## Expected Output Example

```
Welcome to Virtual Pet Simulator
Choose an option:
1. View pets
2. Interact with pet
3. Breed pets
4. Edit pets
5. Save and Exit

> 1

Name: Milo, Species: Cat
Health: 100, Hunger: 20, Happiness: 80

> 3
Enter name of parent 1: Milo
Enter name of parent 2: Luna
Child created: ChildOf_Milo_Luna

> 5
All pets saved to pets.json.
Goodbye!
```

---

## Sample Diagram

```
          +-----------+
          |   Stats   |
          +-----------+
          | health    |
          | hunger    |
          | happiness |
          +-----------+

                ^
                |
         +-------------+
         |    Pet      |
         +-------------+
         | name        |
         | species     |
         | stats       |
         +-------------+
         | update()    |
         | interact()  |
         | operator+() |
         +-------------+
```

---

## Makefile

```makefile
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp pet.cpp stats.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = petsim

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
```

---

## Notes

This lab is open-ended. Encourage creativity and sound class design. Require adherence to good coding practices and robust file I/O. The interface can remain text-based but must support all core functionality. Students must submit screenshots or short video demos.

---

## File Checklist before Submitting

- `main.cpp`, `pet.hpp/cpp`, `stats.hpp/cpp`
- Edited or new `data/pets.json`
- Any `*.txt` files if behavior scripting is implemented
- Makefile and build-ready folder
- README or usage notes if needed

## Submission
- Schedule a 30 min meeting with your Instructor to discuss your solution to this problem.
- Be prepared to explain the code you submit
