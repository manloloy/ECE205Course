# Lab05B: Inheritance in C++

## Overview

In this lab, you will practice object-oriented programming using **inheritance** in C++. You will implement a class hierarchy where a base class `Plant` is extended by a derived class `Flower`. You will then store both `Plant` and `Flower` objects in a list and use a function to display their information.

This assignment builds on your understanding of C++ classes, constructors, access modifiers, and virtual functions.

---

## Objectives

- Define and use base and derived classes in C++
- Use inheritance to extend functionality
- Store base and derived objects using pointers to a base class
- Use virtual functions to enable polymorphic behavior
- Dynamically allocate objects based on user input
- Store and display a list of objects with class-specific details

---

## Background

In C++, **inheritance** allows you to define a new class based on an existing class. The derived class inherits members (fields and methods) from the base class, which allows for code reuse and polymorphism.

- The `Plant` class will store basic information like name and cost.
- The `Flower` class will inherit from `Plant` and add details such as annual type and flower color.

Using **virtual functions**, we can ensure that the correct `print_info()` function is called depending on the object type, even if accessed via a pointer to the base class.

---

## Task

You will:

1. Create a `Plant` base class.
2. Create a `Flower` class derived from `Plant`.
3. Define a `print_info()` function in both classes (make the base version virtual).
4. Store all objects in a `vector<Plant*>`.
5. Implement a `print_list()` function that calls `print_info()` for each item in the list.
6. Parse user input to create the correct object type and add it to the list.
7. Delete all dynamically allocated memory at the end.

---

## Input Format

Each line will be of one of two forms:
```
plant <name> <cost>
flower <name> <cost> <is_annual> <color_of_flowers>
```

Input ends when the user enters `-1`.

---

## Output Format

Your output should print the information for each plant or flower in the order they were entered:
```
Plant 1 Information:
   Plant name: Spirea
   Cost: 10

Plant 2 Information:
   Plant name: Hydrangea
   Cost: 30
   Annual: false
   Color of flowers: lilac

...
```

---

## Template

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/* Define Plant class here */

/* Define Flower class here (inherits from Plant) */

/* Define print_list() function here */

int main() {
    vector<Plant*> my_garden;
    string user_input;

    getline(cin, user_input);
    while (user_input != "-1") {
        // Parse the line and create either a Plant or Flower
        getline(cin, user_input);
    }

    // Print the entire list
    print_list(my_garden);

    // Free allocated memory

    return 0;
}
```

---

## Notes

In this lab, you explored how inheritance works in C++. You practiced defining a class hierarchy, using virtual functions, handling dynamic memory, and working with heterogeneous collections of objects.

This lab prepares you for larger object-oriented programming designs and introduces you to polymorphism—a core concept in software engineering.
