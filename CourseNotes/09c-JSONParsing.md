# JSON Parsing in C++ with nlohmann/json

## Overview

In this lecture, we introduce how to use the popular [nlohmann/json](https://github.com/nlohmann/json) header-only library to read and write JSON files in C++. This will allow students to structure and manipulate complex data such as configuration files, game assets, or object templates.

This module builds on **File I/O in C++**.

---

## 1. What is JSON?

JSON (JavaScript Object Notation) is a lightweight data-interchange format, easy for humans to read and write, and easy for machines to parse and generate.

### Example
```json
{
  "name": "Fluffy",
  "species": "cat",
  "hunger": 3,
  "position": [100, 200],
  "color": [255, 120, 120]
}
```

---

## 2. Installing nlohmann/json

This library is **header-only**, meaning you just include the `.hpp` file in your project.

1. Download the file `json.hpp` from:
   https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp

2. Place it in your project under `include/json.hpp`

---

## 3. Including the Library

```cpp
#include "include/json.hpp"
using json = nlohmann::json;
```

---

## 4. Parsing JSON from a File

### Example: Read pet data from a file

**pets.json**
```json
[
  {
    "name": "Fluffy",
    "species": "cat",
    "hunger": 3
  },
  {
    "name": "Rex",
    "species": "dog",
    "hunger": 5
  }
]
```

**main.cpp**
```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include "include/json.hpp"
using json = nlohmann::json;
using namespace std;

int main() {
    ifstream inFile("pets.json");
    if (!inFile) {
        cerr << "Failed to open file.\n";
        return 1;
    }

    json pets;
    inFile >> pets;

    for (const auto& pet : pets) {
        cout << pet["name"] << " is a " << pet["species"]
             << " with hunger level " << pet["hunger"] << endl;
    }

    return 0;
}
```

### Output
```
Fluffy is a cat with hunger level 3
Rex is a dog with hunger level 5
```

---

## 5. Writing JSON to a File

### Example: Save pet data

```cpp
#include <fstream>
#include "include/json.hpp"
using json = nlohmann::json;

int main() {
    json pet;
    pet["name"] = "Chirpy";
    pet["species"] = "bird";
    pet["hunger"] = 2;
    pet["position"] = {50, 75};

    ofstream outFile("new_pet.json");
    outFile << pet.dump(4); // pretty print with 4 spaces
    outFile.close();
    return 0;
}
```

**new_pet.json** (output)
```json
{
    "hunger": 2,
    "name": "Chirpy",
    "position": [
        50,
        75
    ],
    "species": "bird"
}
```

---

## 6. Accessing and Modifying Fields

```cpp
json pet;
pet["name"] = "Fluffy";
pet["hunger"] = 3;

cout << pet["name"] << endl;  // Fluffy

pet["hunger"] += 1;           // Increase hunger
```

### Type casting
```cpp
int h = pet["hunger"].get<int>();
string name = pet["name"].get<string>();
```

---

## 7. Arrays and Vectors

### Reading a JSON array of values
```json
"color": [255, 100, 120]
```

```cpp
vector<int> color = pet["color"].get<vector<int>>();
```

### Creating an array
```cpp
json pet;
pet["position"] = {100, 200};
```

---

## 8. Error Checking

Always check file opening:
```cpp
ifstream file("pets.json");
if (!file.is_open()) {
    cerr << "Error opening JSON file.\n";
}
```

Try/catch for malformed JSON:
```cpp
try {
    file >> j;
} catch (json::parse_error& e) {
    cerr << "Parse error: " << e.what() << endl;
}
```

---

## 9. Summary Table

| Task                  | Syntax                                      |
|-----------------------|---------------------------------------------|
| Include library       | `#include "json.hpp"`                        |
| Define alias          | `using json = nlohmann::json;`              |
| Parse file            | `infile >> j;`                              |
| Write file            | `outfile << j.dump(4);`                     |
| Access value          | `j["key"]`                                  |
| Read into vector      | `j["array"].get<vector<int>>()`             |
| Pretty print          | `j.dump(4)`                                 |

---

## 10. Practice Task

Create a file called `zoo.json` with several animal entries. Write a C++ program that:
- Reads the animals from the file
- Increases the hunger of all animals by 1
- Writes the updated list to `zoo_updated.json`

---

