# Lab08A: Interfaces and Templates in C++

---

## Objectives

- Understand how to design and use class inheritance in C++.
- Implement and utilize abstract interfaces.
- Practice template functions with class pointers.
- Simulate and manipulate collections of vehicle types.

---

## Background

In this lab, you will simulate a fleet of delivery vehicles across different types: land, air, and sea. You’ll create a base class for all vehicles, extend it through inheritance, and apply templates and abstract interfaces to simulate fuel usage and ensure compatibility across your entire vehicle simulation system.

You will complete several tasks incrementally, using separate files as described. Each file focuses on a key learning outcome.

---

## Task Overview

You will complete four tasks:

- **Task 1a (Vehicle class)**: Create a base `Vehicle` class with protected data and public accessors.
- **Task 1b (Derived classes)**: Create `GroundV`, `AirV`, and `SeaV` classes that inherit from `Vehicle`.
- **Task 1c (Template Function)**: Design a template function `VehicleAdder` to combine multiple similar vehicles.
- **Task 1d (Interface Design)**: Ensure all vehicle classes conform to a common interface `Displayable`.

---

## Task 1a – Vehicle Class

Create a file named `1a.cpp`. In this file, write a class named `Vehicle` that contains:

- **Protected Members**:
  - `fuelUsage`: `float`, miles per gallon.
  - `load`: `float`, percentage of maximum load.
  - `fuelMeter`: `float`, fuel remaining percentage.
  - `odometer`: `float`, total miles traveled.

- **Public Interface**:
  - A constructor accepting `fuelUsage` as input.
  - Getters and setters for `load` and `fuelMeter`.
  - A setter for `odometer`.

You will use this base class as the foundation for later tasks.

### Example Diagram:

```
+---------------------+
|      Vehicle        |
+---------------------+
| - fuelUsage: float  |
| - load: float       |
| - fuelMeter: float  |
| - odometer: float   |
+---------------------+
| + Vehicle(float)    |
| + Set/Get Methods   |
+---------------------+
```

---

## Task 1b – Inherited Classes

Create a file named `1b.cpp`.

Implement three classes that inherit publicly from `Vehicle`:

- `GroundV`
- `AirV`
- `SeaV`

Each derived class should define a **public method** that simulates fuel usage and returns fuel consumed given a distance:

```cpp
float Drive(float mi); // GroundV
float Fly(float mi);   // AirV
float Sail(float mi);  // SeaV
```

Only provide function **prototypes** at this point; do not implement them yet.

---

## Task 1c – Template Function

Create a file named `1c.txt`.

Design a **template function** to merge a group of identical vehicles into one summary vehicle. Analyze how you would need to support the following:

```cpp
template <typename T>
T VehicleAdder(std::vector<T*> vect) {
    T* newV = vect[0];
    for (int i = 1 ; i < vect.size(); i++) {
        *newV = *newV + *vect[i]; // Assume + is overloaded
    }
    return *newV;
}
```

### 1c. Tasks:
In your Task 1c.txt file
- Describe what changes you would need to make to your `GroundV`, `AirV`, and `SeaV` classes to support `+` overloading.
- Explain what this function does, and what it returns.
- Clarify the type requirements and why overloading is needed.

---

## Task 1d – Interface for Display

Create a file named `1d.txt`.

Design an interface named `Displayable` that supports a method called `ShowVehicleDetails()`. This interface will be used to ensure compatibility when displaying vehicle information.

You are provided with the following function:

```cpp
void ShowUnitDetails(std::vector<Vehicle*> unitList) {
    for (int i = 0; i < unitList.size(); i++) {
        unitList[i]->ShowVehicleDetails();
    }
}
```

### 1d Tasks:
In your 1d.txt file
- Create the interface `Displayable` and ensure it includes a pure virtual function `ShowVehicleDetails()`.
- Modify each class (`GroundV`, `AirV`, `SeaV`) to implement `Displayable`.
- You may write only the class headers and indicate where changes are made.

---

## Expected Output

If implemented correctly, your vehicle classes should enable scenarios like:

```
Vehicle fleet details:
[GroundV] Odometer: 150.0 miles
[AirV]    Odometer: 1200.0 miles
[SeaV]    Odometer: 780.5 miles

Total combined fuel usage from unit: 194.3 gallons
```

---


## Submission

Submit the following files To your TA. 
- `1a.cpp`
- `1b.cpp`
- `1c.txt`
- `1d.txt`

Each file must compile individually (where applicable). Include comments and documentation for full credit.

---

