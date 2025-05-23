# Inheritance and Composition in C++

C++ allows you to **create new classes from existing ones** using **inheritance**, and to **build complex objects from simpler ones** using **composition**.

---

## Access Specifiers in Classes

| Specifier   | Accessible From | Derived Class | Outside Class |
|-------------|-----------------|---------------|----------------|
| `public`    | Yes             | Yes           | Yes            |
| `protected` | Yes             | Yes           | No             |
| `private`   | Yes             | No            | No             |

---

## Basic Class Structure

```cpp
class Base {
  public:
    // public members

  protected:
    // protected members

  private:
    // private members
};
```

---

## Public Members Example

```cpp
class Line {
  public:
    double length;
    void setLength(double len);
    double getLength();
};

void Line::setLength(double len) {
  length = len;
}

double Line::getLength() {
  return length;
}

int main() {
  Line line;
  line.setLength(6.0);
  line.length = 10.0;  // OK, because it's public
  cout << "Length: " << line.getLength() << endl;
  return 0;
}
```

---

## Private Members Example

```cpp
class Box {
  private:
    double width;

  public:
    double length;
    void setWidth(double w);
    double getWidth();
};

void Box::setWidth(double w) {
  width = w;
}

double Box::getWidth() {
  return width;
}
```

```cpp
int main() {
  Box box;
  box.length = 10.0;
  box.setWidth(5.0);
  cout << "Width: " << box.getWidth() << endl;
}
```

---

## Protected Members and Derived Class

```cpp
class Box {
  protected:
    double width;
};

class SmallBox : public Box {
  public:
    void setSmallWidth(double w) { width = w; }
    double getSmallWidth() { return width; }
};
```

---

## Modes of Inheritance

| Inheritance Mode | Base Public | Base Protected | Base Private |
|------------------|-------------|----------------|---------------|
| `public`         | public      | protected      | not inherited |
| `protected`      | protected   | protected      | not inherited |
| `private`        | private     | private        | not inherited |

---

## Example: Public Inheritance

```cpp
class Shape {
  public:
    void draw() { cout << "Drawing shape\n"; }
};

class Circle : public Shape {
  public:
    void drawCircle() { cout << "Drawing circle\n"; }
};
```

---

## Types of Inheritance

### 1. Single Inheritance

```cpp
class A { };
class B : public A { };
```

### 2. Multiple Inheritance

```cpp
class A { };
class B { };
class C : public A, public B { };
```

### 3. Multilevel Inheritance

```cpp
class A { };
class B : public A { };
class C : public B { };
```

### 4. Hierarchical Inheritance

```cpp
class A { };
class B : public A { };
class C : public A { };
```

### 5. Hybrid (Virtual) Inheritance

Combination of multiple + hierarchical inheritance.

---

# Composition in C++

Composition means a class contains **objects of other classes** as members.

### “Has-a” Relationship

- A `Car` **has a** `SteeringWheel`
- A `Creature` **has a** `Point` location

---

### Example: Composition

```cpp
class Point {
  public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

class Creature {
  private:
    string name;
    int hp;

  public:
    Point location;

    Creature(string n, int h) : name(n), hp(h) {}
};
```

---

## Composition vs Aggregation

- **Composition**: Complex object owns its parts (destroying parent destroys members)
- **Aggregation**: Complex object uses parts it doesn't own (members outlive the parent)

---

## Inheritance vs Composition

| Question                         | Use             |
|----------------------------------|------------------|
| Is it a variation/type of X?     | Inheritance (IS-A) |
| Does it contain X?               | Composition (HAS-A) |

---

### Examples

- A `Car` IS-A `Vehicle` → **Inheritance**
- A `Vehicle` HAS-A `Tire`, `Engine`, `SteeringWheel` → **Composition**
- A `Square` IS-A `Shape` → **Inheritance**
- A `Creature` HAS-A `Location` → **Composition**

---

## Mixing Composition and Inheritance

```cpp
class Vehicle {
  // shared properties
};

class Car : public Vehicle {
  private:
    Engine engine;
    SteeringWheel steering;
    Tire tires[4];
};
```

Inheritance defines type hierarchy. Composition defines internal structure.

---
