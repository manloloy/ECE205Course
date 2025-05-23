# Module 2: Constructors and Destructors in C++

C++ allows classes to define **constructors** and **destructors** to control how objects are initialized and cleaned up.

---

## What is a Constructor?

A **constructor** is a special function that is called **automatically** when an object is created.

### Key properties:
- Same name as the class
- No return type (not even `void`)
- Can be **overloaded** (multiple constructors with different parameters)

---

### Example: Default Constructor

```cpp
#include <iostream>
using namespace std;

class Line {
  private:
    double length;

  public:
    Line();              // constructor
    void setLength(double len);
    double getLength();
};

Line::Line() {
  cout << "Object is being created" << endl;
  length = 0.0;
}

void Line::setLength(double len) {
  length = len;
}

double Line::getLength() {
  return length;
}

int main() {
  Line line;
  line.setLength(6.0);
  cout << "Length of line: " << line.getLength() << endl;
  return 0;
}
```

---

## Parameterized Constructors

You can pass arguments to constructors to initialize objects at creation.

```cpp
class Line {
  private:
    double length;

  public:
    Line(double len);   // parameterized constructor
    double getLength();
};

Line::Line(double len) {
  cout << "Object created, length = " << len << endl;
  length = len;
}

double Line::getLength() {
  return length;
}

int main() {
  Line line(10.0);
  cout << "Length of line: " << line.getLength() << endl;
  return 0;
}
```

---

## Constructor Overloading

You can define multiple constructors for flexibility.

```cpp
class Point {
  int x, y;

public:
  Point() {
    x = 0; y = 0;
  }

  Point(int a, int b) {
    x = a; y = b;
  }

  void print() {
    cout << "(" << x << ", " << y << ")" << endl;
  }
};
```

---

## Initialization Lists

Instead of assigning in the constructor body, you can use **initialization lists**.

```cpp
class Line {
  double length;

public:
  Line(double len) : length(len) {
    cout << "Initialized with length = " << len << endl;
  }

  double getLength() {
    return length;
  }
};
```

Useful for:
- Initializing `const` and `reference` members
- Calling base class constructors

---

## The Destructor

A **destructor** is called automatically when an object goes out of scope or is deleted.

### Key properties:
- Same name as the class, prefixed with `~`
- No parameters
- No return value
- Used to clean up resources

---

### Destructor Example

```cpp
class Line {
  double length;

public:
  Line(double len) : length(len) {
    cout << "Object created, length = " << len << endl;
  }

  ~Line() {
    cout << "Object destroyed" << endl;
  }

  double getLength() {
    return length;
  }
};
```

In `main()`:

```cpp
int main() {
  Line line(5.0);
  cout << "Length: " << line.getLength() << endl;
  return 0;  // destructor is called automatically
}
```

---

## Object Lifetime

- Constructor runs when the object is created
- Destructor runs when the object goes out of scope or is deleted
- Helps manage **resources**, such as memory and file handles

---

## When to Use Constructors and Destructors

- Constructors ensure your object is **always valid** when used
- Destructors ensure resources are **always cleaned up**
- Use together with **RAII** to avoid memory/resource leaks

---
