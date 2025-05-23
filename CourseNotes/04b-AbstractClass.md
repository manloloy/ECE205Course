# Abstract Classes and Interfaces in C++

In C++, abstract classes and interfaces allow developers to define **general behavior** without committing to a specific implementation.

---

## Abstract Classes

An **abstract class** is a class that cannot be instantiated and is intended to be used **only as a base class**. It **must contain at least one pure virtual function**.

```cpp
class AbstractBase {
public:
    virtual void f() = 0;  // pure virtual function
};
```

The `= 0` syntax makes `f()` a **pure virtual function**, meaning there is **no implementation in this class**.

---

### Key Rules

- You **cannot create objects** of an abstract class.
- You **can use references and pointers** to abstract classes.
- A derived class **must override** all pure virtual functions to be **concrete**.
- If any pure virtual function is left unimplemented, the derived class **remains abstract**.

---

### Example: Abstract Base Class

```cpp
class Shape {
public:
    virtual void draw() = 0;  // pure virtual
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

int main() {
    // Shape s;      // ❌ Error
    Shape* ptr;
    Circle c;

    ptr = &c;
    ptr->draw();      // ✅ Output: Drawing a circle
}
```

---

## Interfaces in C++

A **C++ interface** is simply an abstract class where:
- **All functions are pure virtual**
- **No data members** (except static constants, if needed)

```cpp
class IPrintable {
public:
    virtual void print() const = 0;  // pure virtual
};
```

### Why Use Interfaces?

An interface defines **how an object can be used**. It expresses a **contract** that derived classes must fulfill, but does **not define how**.

---

## Interface Example

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual int getArea() = 0;  // interface function

    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }

protected:
    int width;
    int height;
};

class Rectangle : public Shape {
public:
    int getArea() override { return width * height; }
};

class Triangle : public Shape {
public:
    int getArea() override { return (width * height) / 2; }
};

int main() {
    Rectangle rect;
    Triangle tri;

    rect.setWidth(5);
    rect.setHeight(7);
    cout << "Rectangle area: " << rect.getArea() << endl;

    tri.setWidth(5);
    tri.setHeight(7);
    cout << "Triangle area: " << tri.getArea() << endl;
}
```

### Output:
```
Rectangle area: 35
Triangle area: 17
```

---

## Concrete vs Abstract Classes

- A **concrete class** can be instantiated and provides full implementations.
- An **abstract class/interface** cannot be instantiated and may contain unimplemented behavior.

---

## Calling Pure Virtual Functions in Constructors

This is **undefined behavior**. Avoid calling pure virtual methods inside constructors or destructors:

```cpp
class A {
public:
    A() { direct(); }
    virtual void direct() = 0;  // ❌ this is dangerous
};
```

---

## Interface Design Strategy

- Use interfaces to **standardize behavior** across different implementations.
- Use inheritance to define a **shared interface**, while allowing **custom logic** in subclasses.
- This supports **polymorphism**, making systems easier to extend.

---

### Design Insight

Consider the abstract class as the **interface layer**:

```cpp
class AudioPlayer {
public:
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
};
```

Then implement different backends:

```cpp
class MP3Player : public AudioPlayer { ... }
class WAVPlayer : public AudioPlayer { ... }
```

You can call `play()` on any `AudioPlayer*` — regardless of which subclass it points to.

---

## Notes

| Term             | Description                                           |
|------------------|-------------------------------------------------------|
| Abstract Class   | A base class with at least one pure virtual function |
| Interface        | An abstract class with only pure virtual functions   |
| Concrete Class   | Implements all functions and can be instantiated     |
| Pure Virtual     | `= 0` marks a function with no implementation        |
| Cannot Do        | Instantiate abstract classes or call pure virtuals in constructors |

---
