# Lab05A: Inheritance – Pet, Cat, and Dog (C++ Only)

## Objectives
- Practice defining and using base and derived classes in C++
- Use constructors to initialize object attributes
- Use function overriding and class polymorphism
- Practice handling structured input to differentiate between derived types

## Background
Inheritance is a core concept in object-oriented programming. A base class encapsulates general behavior and data, while derived classes extend or customize this functionality. In this lab, you'll work with a `Pet` base class and two derived classes: `Cat` and `Dog`.

You'll read input that includes the type of pet (either `cat` or `dog`), followed by the pet's name, age, and an additional property specific to that pet type. Based on the input, the program should construct the appropriate object and print its details using a shared `print_info()` function.

### Reminder: Inheritance in C++
- Use the `:` symbol to derive a class from another.
- Use `public` inheritance to make the base class's public members accessible in the derived class.
- Override member functions to extend or customize behavior.

## Instructions

1. Define a base class `Pet` with the following:
   - Private members: `name` (string), `age` (int)
   - A constructor that takes `name` and `age`
   - A `print_info()` method that prints name and age

2. Define a class `Cat` that:
   - Inherits from `Pet`
   - Has a private member `breed` (string)
   - Its constructor should take `name`, `age`, and `breed`
   - Overrides `print_info()` to call the base method and print the breed

3. Define a class `Dog` that:
   - Inherits from `Pet`
   - Has a private member `favorite_toy` (string)
   - Its constructor should take `name`, `age`, and `favorite_toy`
   - Overrides `print_info()` to call the base method and print the favorite toy

4. In `main()`:
   - Read input lines of the form:

     ```
     cat Luna 3 ScottishFold
     dog Max 5 Ball
     -1
     ```

     The input ends with `-1`.
   - Store each object in a vector of `Pet*`
   - Loop through the vector and call `print_info()` on each object

5. Output should be in this format:

    ```
    Pet Information:
       Name: Luna
       Age: 3
       Breed: ScottishFold

    Pet Information:
       Name: Max
       Age: 5
       Favorite Toy: Ball
    ```

## Hints
- Use `vector<Pet*>` to store both `Cat*` and `Dog*` objects.
- Use `cin >>` with string tokens to parse the input line by line.
- Don't forget to clean up dynamically allocated memory with `delete`.

---

## Template

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pet {
public:
    Pet(string petName, int petAge);
    virtual void print_info() const;

protected:
    string name;
    int age;
};

class Cat : public Pet {
public:
    Cat(string petName, int petAge, string petBreed);
    void print_info() const override;

private:
    string breed;
};

class Dog : public Pet {
public:
    Dog(string petName, int petAge, string favToy);
    void print_info() const override;

private:
    string favorite_toy;
};

int main() {
    vector<Pet*> petList;
    string type;

    // TODO: Read structured input and create the appropriate object

    // TODO: Loop through list and call print_info() on each object

    // TODO: Delete allocated memory

    return 0;
}
```


---

## Some useful Reminders
- When storing both `Cat` and `Dog` objects in one list, you must use pointers to the base class.
- Always use `virtual` destructors for base classes when using inheritance with `new`.
- Input parsing is critical for dynamically creating the right object. Use string tags to differentiate types.

