# The Open/Closed Principle

The **Open/Closed Principle (OCP)** is one of the core principles of object-oriented design. It's a direct payoff of the inheritance, abstract classes, and interfaces you've just learned.

---

## What Is the Open/Closed Principle?

> Software entities (classes, functions, modules) should be **open for extension**, but **closed for modification**.

- **Open for extension** — you should be able to add new behavior to a system.
- **Closed for modification** — you should be able to do this *without changing existing, already-working code*.

At first these sound contradictory. The trick is that you don't add new behavior by editing old code — you add it by writing **new** code (usually a new derived class) that plugs into an interface the old code already depends on.

---

## A Violation: Type-Checking with `if`/`else`

Here's a common way beginners write shape-handling code:

```cpp
struct Shape {
    std::string type;
    double width, height, radius;
};

double calculateArea(Shape* shape) {
    if (shape->type == "circle") {
        return 3.14159 * shape->radius * shape->radius;
    } else if (shape->type == "rectangle") {
        return shape->width * shape->height;
    }
    // What about triangle? hexagon? ...
    return 0;
}
```

### Why This Violates OCP

Every time a new shape is added, `calculateArea()` must be **edited**. That means:

- You're touching code that already worked and was already tested.
- Every place in the program that has a similar `if`/`else` or `switch` on `type` needs the same edit — and it's easy to forget one.
- The risk of introducing a bug into *existing* shapes goes up every time you add a *new* one.

This kind of type-checking chain is one of the most common signs of an Open/Closed violation.

---

## Fixing It with an Abstract Class

Instead of asking "what type is this?", let each shape know how to compute its own area:

```cpp
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};
```

Code that uses shapes now depends only on the `Shape` interface:

```cpp
double totalArea(const std::vector<Shape*>& shapes) {
    double total = 0;
    for (Shape* s : shapes)
        total += s->area();
    return total;
}
```

### Adding a New Shape

```cpp
class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override {
        return 0.5 * base * height;
    }
};
```

Notice what did **not** change: `Shape`, `Circle`, `Rectangle`, and `totalArea()` are all untouched. `totalArea()` will correctly include `Triangle` objects the moment they're passed in — it never even needs to be recompiled with `Triangle` in mind. The system was **open** to the extension (`Triangle`) and **closed** to modification of existing code.

---

## OCP and the Patterns You've Already Learned

The Open/Closed Principle isn't a new technique — it's the *reason* several patterns from this course are designed the way they are.

| Pattern / Technique         | How It Supports OCP |
|------------------------------|----------------------|
| Abstract classes / interfaces | New behavior = a new derived class implementing the interface, not an edit to existing classes |
| **Strategy Pattern**          | New algorithms are added as new strategy classes; the `Context` class that uses them never changes |
| **Factory Method**            | New object types are added by extending the factory's creation logic, without changing the code that *calls* the factory |

---

## Signs You're Violating OCP

- A `switch` or `if`/`else` chain that checks an object's "type" (as a string, enum, or otherwise) to decide what to do.
- Adding a new feature requires you to go back and edit a function you already finished and tested.
- The same type-checking logic is duplicated in multiple places in the codebase.

---

## Notes

| Term                  | Description |
|------------------------|-------------|
| Open for extension     | New functionality can be added to the system |
| Closed for modification| Existing, working code does not need to change to support that new functionality |
| Primary tool           | Abstraction — abstract classes/interfaces + polymorphism |
| Related patterns       | Strategy, Factory Method |

- OCP is one of the five **SOLID** principles of object-oriented design (the "O").
- It is a *design goal*, not a language feature — C++ gives you the tools (virtual functions, abstract classes) to achieve it, but the discipline is yours.
- The payoff isn't visible in a small program — it shows up when a codebase has to keep growing without breaking what already works, which is exactly the situation your final project will put you in.

---
