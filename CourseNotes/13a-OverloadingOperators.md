# Lecture Module: Operator Overloading in C++

## Overview

In C++, **operator overloading** allows you to redefine the behavior of built-in operators (like `+`, `-`, `*`, etc.) for user-defined types. This feature improves code readability and enables natural syntax when working with custom objects.

This module explores:

- What operator overloading is
- How to define operator overloading in a class
- The use of member functions for overloading
- How overload resolution is based on parameter types
- Multiple overloads of the same operator

---

## Why Overload Operators?

Operator overloading provides intuitive usage of custom types. For example, instead of calling a function like `addTime(t1, t2)`, you can use `t1 + t2`.

```cpp
TimeHrMn time1(3, 22);
TimeHrMn time2(2, 50);
TimeHrMn totalTime = time1 + time2;
```

This is equivalent to:

```cpp
TimeHrMn totalTime = time1.operator+(time2);
```

But the overloaded version is more natural and readable.

---

## Example: Overloading the `+` Operator

Here is a basic example using a `TimeHrMn` class to represent time in hours and minutes.

```cpp
#include <iostream>
using namespace std;

class TimeHrMn {
public:
    TimeHrMn(int h = 0, int m = 0);
    void Print() const;

    // Overload the + operator
    TimeHrMn operator+(TimeHrMn rhs);

private:
    int hours;
    int minutes;
};

// Constructor
TimeHrMn::TimeHrMn(int h, int m) {
    hours = h;
    minutes = m;
}

// Overloaded + operator (adds two TimeHrMn objects)
TimeHrMn TimeHrMn::operator+(TimeHrMn rhs) {
    TimeHrMn result;
    result.hours = hours + rhs.hours;
    result.minutes = minutes + rhs.minutes;
    return result;
}

// Print method
void TimeHrMn::Print() const {
    cout << "H:" << hours << ", M:" << minutes << endl;
}

int main() {
    TimeHrMn t1(3, 22);
    TimeHrMn t2(2, 50);
    TimeHrMn total = t1 + t2;
    total.Print();
    return 0;
}
```

**Expected Output:**
```
H:5, M:72
```

Note: This version does not yet normalize minutes > 60, which would be a good extension.

---

## Operator Overloading with Different Types

You can overload the same operator multiple times for different parameter types. For instance, to allow adding an `int` to a `TimeHrMn` object:

```cpp
class TimeHrMn {
public:
    // ...

    TimeHrMn operator+(int rhs);  // Adds hours
};

// Implementation
TimeHrMn TimeHrMn::operator+(int rhs) {
    TimeHrMn result;
    result.hours = hours + rhs;
    result.minutes = minutes;
    return result;
}
```

Then you can write:

```cpp
TimeHrMn t1(3, 45);
TimeHrMn t2 = t1 + 2;  // Adds 2 hours
t2.Print();  // H:5, M:45
```

---

## Important Notes

- **Only non-static member functions** or friend functions can overload operators.
- The **left-hand operand** is the object on which the member function is invoked.
- The **return type** should usually be a new object (not a reference to `this`), unless you are modifying the current object.
- The **return type does not participate** in overload resolution. You cannot have two overloads that differ only by return type.

---

## Common Errors

```cpp
TimeHrMn operator+(TimeHrMn rhs);
int operator+(TimeHrMn rhs); //  Invalid: parameter types same as above
```

```cpp
TimeHrMn operator+(int rhs);
int operator+(int rhs); //  Valid: because rhs is an int in both, but context differs
```

```cpp
// Ambiguous due to default arguments
TimeHrMn operator+(int h, int m = 0);
TimeHrMn operator+(int h); //  Ambiguous with above
```

---

## Notes

- Operator overloading improves code expressiveness when working with custom types.
- You can overload most operators in C++ using member functions.
- The compiler selects the correct overload based on the operands' types.
- Overload resolution does not consider the return type.
- Good practice includes ensuring that your overloads behave intuitively and do not surprise the user.

---

## Practice Idea

Create a `Distance` class with meters and centimeters and overload:
- `+` for Distance + Distance
- `+` for Distance + int (adds meters)
- `==` to compare two Distance objects

---
