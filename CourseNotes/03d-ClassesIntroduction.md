# Classes in C++

In C++, a `class` is a user-defined data type that allows you to **group both data and functions** under a single name. It is the foundation of object-oriented programming (OOP).

---

## Struct vs Class

Both `struct` and `class` can be used to define custom types, but:

- In `struct`, members are **public by default**
- In `class`, members are **private by default**

---

## Basic Class Example

```cpp
#include <iostream>
using namespace std;

class Rectangle {
  private:
    int width, height;

  public:
    void set_values(int w, int h);
    int area();
};

void Rectangle::set_values(int w, int h) {
  width = w;
  height = h;
}

int Rectangle::area() {
  return width * height;
}

int main() {
  Rectangle rect;
  rect.set_values(3, 4);
  cout << "Area: " << rect.area() << endl;
  return 0;
}
```

### Notes

- `width` and `height` are private: cannot be accessed directly from `main`
- `set_values()` and `area()` are public: can be called from outside

---

## Why Use `class`?

- Enforces **encapsulation** by hiding internal data
- Helps organize code into logical units
- Allows grouping of **functions and data together**

---

## Declaring Multiple Objects

You can declare more than one object of a class, just like structs:

```cpp
int main() {
  Rectangle rectA, rectB;
  rectA.set_values(3, 4);
  rectB.set_values(5, 6);

  cout << "rectA area: " << rectA.area() << endl;
  cout << "rectB area: " << rectB.area() << endl;
  return 0;
}
```

---

## Arrays of Class Objects

```cpp
Rectangle shapes[2];
shapes[0].set_values(2, 3);
shapes[1].set_values(4, 5);

cout << "Area 0: " << shapes[0].area() << endl;
cout << "Area 1: " << shapes[1].area() << endl;
```

---

## Pointers to Class Objects

```cpp
Rectangle r;
Rectangle *ptr = &r;

ptr->set_values(6, 7);
cout << "Area: " << ptr->area() << endl;
```

The arrow `->` operator is used to access members from a pointer to an object.

---

## Access Specifiers Summary

| Specifier | Meaning                   |
|-----------|---------------------------|
| `private` | Only accessible inside the class |
| `public`  | Accessible from outside   |
| `protected` | Accessible in derived classes (will be used in inheritance) |

---
