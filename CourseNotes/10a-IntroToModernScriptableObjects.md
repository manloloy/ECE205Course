# C++ Module: Introduction to Scriptable Objects

This module introduces **Scriptable Objects**, a powerful concept widely used in modern game engines like Unity and Unreal Engine. Though originally not part of standard C++, we will explain their purpose, benefits, and how the same ideas can be **conceptually and practically mimicked in C++**.

---

## What Are Scriptable Objects?

A **Scriptable Object** is a reusable, **data container** that allows developers to store and share **data and behavior** across the game or application without duplicating logic.

It is *not* a visible object in the scene like a character or item, but instead is an asset that can hold configuration or state information that other game components can reference.

---

## Why Are Scriptable Objects Useful?

Scriptable Objects help with:
- **Separation of Data and Behavior**: Data can be maintained in centralized reusable files.
- **Memory Efficiency**: Instead of duplicating data across scenes or objects, a single shared instance is used.
- **Ease of Reuse and Testing**: You can plug in different data into systems without writing new logic.
- **Decoupling Systems**: Objects can reference the same Scriptable Object instead of referencing each other directly.

---

## Common Use Cases

Scriptable Objects are especially useful for:

| Use Case                | Example                                  |
|-------------------------|------------------------------------------|
| Game Settings           | Audio volume, screen resolution          |
| Character Stats         | Health, speed, attack power              |
| Weapon Definitions      | Type, cooldown, damage                   |
| Shared Behavior Modules | State machines, AI behavior trees        |
| Event/Message Systems   | Decoupled signal/data broadcast systems  |

---

## Scriptable Objects in Unity (For Comparison)

In Unity (C#), Scriptable Objects are created by inheriting from `ScriptableObject`:

```csharp
[CreateAssetMenu(fileName = "NewWeapon", menuName = "Items/Weapon")]
public class WeaponData : ScriptableObject {
    public string weaponName;
    public int damage;
    public float cooldown;
}
```

These assets are then created in the Unity Editor and shared between GameObjects.

---

## Scriptable Objects in Unreal Engine (C++)

Unreal uses a similar approach by creating **Data Assets** derived from `UDataAsset`.

```cpp
UCLASS(BlueprintType)
class UWeaponData : public UDataAsset {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FString WeaponName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 Damage;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float Cooldown;
};
```

These assets can also be defined and referenced across multiple actors or blueprints.

---

## Mimicking Scriptable Objects in C++

Although C++ doesn't have a built-in editor or asset system, we can emulate Scriptable Objects by:

1. Defining configuration **structs or classes**
2. Loading them from **JSON or XML files**
3. Storing them in **shared pointers** or **singletons** to reuse them across the application

This is one way to mimic scriptable objects. Another might be to build a system that will let us read/write to files or update singletons at runtime and then try to construct classes that use them.

---

### Step 1: Define a Data Class

```cpp
// weapon_data.hpp

#ifndef WEAPON_DATA_HPP
#define WEAPON_DATA_HPP

#include <string>

struct WeaponData {
    std::string name;
    int damage;
    float cooldown;
};

#endif
```

---

### Step 2: Load Data from File (Example: JSON)

```cpp
// weapon_loader.hpp

#ifndef WEAPON_LOADER_HPP
#define WEAPON_LOADER_HPP

#include "weapon_data.hpp"
#include <fstream>
#include <nlohmann/json.hpp>

class WeaponLoader {
public:
    static WeaponData loadFromFile(const std::string& path) {
        std::ifstream file(path);
        nlohmann::json j;
        file >> j;

        WeaponData data;
        data.name = j["name"];
        data.damage = j["damage"];
        data.cooldown = j["cooldown"];
        return data;
    }
};

#endif
```

Install [`nlohmann/json`](https://github.com/nlohmann/json) for the JSON support.

Example `weapon.json` file:

```json
{
    "name": "Blaster",
    "damage": 25,
    "cooldown": 0.5
}
```

---

### Step 3: Use It in Your Game Code

```cpp
#include "weapon_loader.hpp"
#include <iostream>

int main() {
    WeaponData weapon = WeaponLoader::loadFromFile("weapon.json");

    std::cout << "Weapon: " << weapon.name << "\n";
    std::cout << "Damage: " << weapon.damage << "\n";
    std::cout << "Cooldown: " << weapon.cooldown << "s\n";

    return 0;
}
```

---

## Advanced C++ Extensions

- You can use a **singleton pattern** or a **service locator** to cache and reuse these data objects.
- If you want "live editing," you could reload the file periodically or on keypress (like `R` to reload weapons).
- You can add **virtual methods** to data types if you want behavior tied with data.

---

## Should We Use SFML?

In this case, SFML isn't required for demonstrating Scriptable Objects, but if you’d like to make a UI button or visual display based on shared data, it could be helpful.

We recommend integrating Scriptable Objects with SFML in future modules when designing reusable character definitions, enemy types, or item systems.

---

## Notes

- **Scriptable Objects** are data containers used in game engines to store reusable data and behavior.
- While not native to C++, you can replicate the concept using plain structs, JSON, and shared instances.
- This approach promotes **data-driven design**, **modularity**, and **flexibility** in your application.

---
