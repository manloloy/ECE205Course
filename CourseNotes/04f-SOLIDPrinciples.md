# SOLID: A Quick Reference

**SOLID** is an acronym for five foundational object-oriented design principles (coined by Robert C. Martin). You've already learned the *ideas* behind most of these earlier in this course, just not under these names. This page is meant as a reference to look back at — it connects each letter to material you've already seen rather than teaching five new topics from scratch.

---

## S — Single Responsibility Principle

> A class should have only **one reason to change** — one job.

You've already been practicing this since [Introduction to Classes](./03d-ClassesIntroduction.md): a class that groups data and behavior into a single, focused unit is easier to reason about and safer to modify than one that does several unrelated things at once.

```cpp
// Violates SRP: one class doing three unrelated jobs
class Player {
public:
    void move();
    void render();
    void saveToFile();
};
```

```cpp
// Follows SRP: each class has one job
class PlayerMovement { public: void move(); };
class PlayerRenderer  { public: void render(); };
class PlayerSaveData  { public: void saveToFile(); };
```

If you change how saving works, only `PlayerSaveData` should need to change — movement and rendering code shouldn't be at risk of breaking.

---

## O — Open/Closed Principle

Covered in full in [Open/Closed Principle](./04e-OpenClosedPrinciple.md).

> Software entities should be **open for extension**, but **closed for modification**.

Achieved with abstract classes/interfaces: new behavior is added as a new derived class, not by editing code that already works.

---

## L — Liskov Substitution Principle

> Anywhere the base class is expected, a derived class object should be usable **without breaking correctness**.

This is the formal reason behind something you've already brushed up against in [Abstract Classes & Interfaces](./04b-AbstractClass.md): a derived class isn't just required to *compile* against the base class's interface, it has to actually **behave** in a way that doesn't violate what callers reasonably assume about the base class.

### The Classic Violation: Square vs. Rectangle

```cpp
class Rectangle {
public:
    virtual void setWidth(int w)  { width = w; }
    virtual void setHeight(int h) { height = h; }
    int area() const { return width * height; }
protected:
    int width, height;
};

class Square : public Rectangle {
public:
    void setWidth(int w) override  { width = height = w; }
    void setHeight(int h) override { width = height = h; }
};
```

`Square` compiles fine as a `Rectangle` — but any code that assumes "calling `setWidth()` doesn't change the height" (a reasonable assumption for a `Rectangle`) will get silently wrong behavior if it's handed a `Square`. `Square` is technically a subtype, but it is **not substitutable** for `Rectangle` — that's an LSP violation.

**Takeaway:** inheritance should model behavior that's actually consistent with the base class's contract, not just data that happens to overlap.

---

## I — Interface Segregation Principle

> No class should be forced to implement methods it **doesn't use**. Prefer several small, focused interfaces over one large one.

Recall the `AudioPlayer` interface from [Abstract Classes & Interfaces](./04b-AbstractClass.md). Suppose it grew a `record()` method:

```cpp
class AudioPlayer {
public:
    virtual void play()   = 0;
    virtual void pause()  = 0;
    virtual void stop()   = 0;
    virtual void record() = 0;  // not every player can actually do this
};
```

Now `MP3Player` is forced to implement `record()` even though it makes no sense for it to record anything. The ISP fix is to split the interface:

```cpp
class Playable {
public:
    virtual void play()  = 0;
    virtual void pause() = 0;
    virtual void stop()  = 0;
};

class Recordable {
public:
    virtual void record() = 0;
};

class MP3Player : public Playable { /* ... */ };
class VoiceRecorder : public Playable, public Recordable { /* ... */ };
```

Each class now only implements what it actually supports.

---

## D — Dependency Inversion Principle

> High-level code should depend on **abstractions**, not on concrete low-level classes directly.

You've already used this without naming it, in both the [Factory Method](./08a-DesignPattern-Factory.md) and [Strategy](./08b-DesignPattern-Strategy.md) patterns:

- `DataContext` (Strategy) depends on the abstract `SortStrategy` interface — never on `AscendingSort` or `DescendingSort` directly.
- Code that calls `ShapeFactory::createShape(type)` (Factory Method) depends on the `Shape` interface it gets back — not on `Circle` or `Square` directly.

In both cases, the "high-level" code (the code coordinating behavior) is decoupled from the "low-level" concrete classes, because both sides depend on a shared abstraction instead of on each other.

---

## Summary Table

| Letter | Principle | One-Line Idea | Where You've Seen It |
|--------|-----------|----------------|------------------------|
| S | Single Responsibility | One class, one job | [Classes Introduction](./03d-ClassesIntroduction.md) |
| O | Open/Closed | Extend without modifying | [Open/Closed Principle](./04e-OpenClosedPrinciple.md) |
| L | Liskov Substitution | Subclasses must honor the base class's contract | [Inheritance](./04a-Inheritance.md), [Abstract Classes](./04b-AbstractClass.md) |
| I | Interface Segregation | Don't force unused methods on implementers | [Abstract Classes](./04b-AbstractClass.md) |
| D | Dependency Inversion | Depend on abstractions, not concrete classes | [Factory Method](./08a-DesignPattern-Factory.md), [Strategy](./08b-DesignPattern-Strategy.md) |

---

## Notes

- SOLID principles overlap in practice — a well-designed abstract class or interface tends to satisfy several of them at once without extra effort.
- None of these are C++ syntax features; they're judgment calls about how to structure classes and interfaces, which is exactly the kind of thing this course has emphasized all along over memorized syntax.
- If you can already explain *why* the `Square`/`Rectangle` example is a problem, or *why* `DataContext` doesn't construct a `SortStrategy` directly, you already understand LSP and DIP — this page just gives you the names.

---
