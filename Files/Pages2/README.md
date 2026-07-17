# Walkthrough: Pages2 — Clickable Shapes

This project extends the `Pages` singleton/page-navigation example from earlier
in the course. Same navigation skeleton (`AppManager`, `Page`), but now the
"objects on screen" are a proper class hierarchy instead of raw `sf::CircleShape`
values. This note walks through *why* each piece is built the way it is —
the goal is to see the OOP concepts from lecture (encapsulation, abstract
classes, inheritance, polymorphism, design patterns) doing real work, not just
existing as syntax.

---

## The problem this design solves

`Page1` needs several shapes bouncing around the screen. `Page2` needs several
shapes a user can click to remove. Both pages need to treat "a shape" the same
way — draw it, move it, check if it was clicked — **without caring whether it's
a circle, a rectangle, or a triangle**.

That's the textbook case for an **abstract base class**: define one interface
that every shape honors, so the pages only ever talk to `Shape`, never to
`CircleShapeObj` or `RectangleShapeObj` directly.

---

## `Shape`: the abstract base class

```cpp
// Shape.hpp
class Shape {
protected:
    sf::Vector2f velocity;

public:
    virtual ~Shape() = default;

    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual void setPosition(sf::Vector2f pos) = 0;
    virtual sf::Vector2f getPosition() const = 0;
    virtual sf::FloatRect getBounds() const = 0;

    void setVelocity(sf::Vector2f v);
    sf::Vector2f getVelocity() const;

    bool isClicked(sf::Vector2f mousePos) const;
    void bounce(unsigned windowWidth, unsigned windowHeight);
};
```

Notice this class has **two kinds of member functions**, and the split is the
whole point of the design:

- **Pure virtual** (`= 0`): `draw`, `setPosition`, `getPosition`, `getBounds`.
  These are the only things that are genuinely different between a circle and
  a rectangle — how you draw one, and how you ask SFML for its position/bounds.
  Because at least one pure virtual function exists, `Shape` is **abstract**:
  you cannot write `Shape s;` anywhere. It only ever exists as a base.

- **Concrete** (`isClicked`, `bounce`, the velocity accessors): these are
  **written once, in the base class, and shared by every subclass**. Look at
  how they're implemented in `Shape.cpp`:

  ```cpp
  bool Shape::isClicked(sf::Vector2f mousePos) const {
      return getBounds().contains(mousePos);
  }
  ```

  `isClicked` doesn't know or care what shape it's called on — it just asks
  the (virtual) `getBounds()` for the current on-screen rectangle and checks
  if the mouse is inside it. Every subclass gets click detection **for free**
  just by implementing `getBounds()` correctly. This is why the abstract class
  is doing real work here, not just enforcing a naming convention: it lets us
  write the click-detection logic and the bounce physics *exactly once*,
  instead of copy-pasting them into `CircleShapeObj`, `RectangleShapeObj`, and
  `TriangleShapeObj` separately.

  `bounce()` follows the same idea — it reads the shape's current bounds and
  position (virtual), decides whether to flip `velocity.x`/`velocity.y` based
  on the window edges, and calls `setPosition()` (virtual) to actually move
  it. The base class supplies the *algorithm*; the subclass supplies the
  *representation*.

---

## The concrete shapes: inheritance + polymorphism

```cpp
// CircleShapeObj.hpp
class CircleShapeObj : public Shape {
private:
    sf::CircleShape circle;

public:
    CircleShapeObj(float radius, sf::Color color, sf::Vector2f pos);

    void draw(sf::RenderWindow& window) const override;
    void setPosition(sf::Vector2f pos) override;
    sf::Vector2f getPosition() const override;
    sf::FloatRect getBounds() const override;
};
```

`CircleShapeObj`, `RectangleShapeObj`, and `TriangleShapeObj` each **wrap** an
SFML shape (`sf::CircleShape`, `sf::RectangleShape`, and — since SFML has no
dedicated triangle class — a 3-point `sf::CircleShape` for the triangle) and
translate the four pure virtual calls into calls on that wrapped object. That's
it. All the interesting behavior (click detection, bouncing) lives in `Shape`
and never gets touched again.

This is **composition inside inheritance**: `CircleShapeObj` *is-a* `Shape`
(inheritance, satisfies the interface), but *has-a* `sf::CircleShape`
(composition, does the actual SFML work). Compare this to `Shape` itself,
which deliberately does **not** hold any SFML shape member — it can't, since
it doesn't know which one it'll be.

Once `Page1`/`Page2` hold a `std::vector<std::unique_ptr<Shape>>`, this is
where **polymorphism** shows up concretely: the pages call `obj->draw(window)`
or `obj->isClicked(mousePos)` through a `Shape*`, and the actual circle,
rectangle, or triangle code runs — decided at runtime by which concrete object
that pointer happens to point at. The page code never has an `if (it's a
circle)` branch anywhere.

---

## `ShapeFactory`: Factory Method pattern

```cpp
// ShapeFactory.cpp
std::unique_ptr<Shape> createRandomShape(sf::Vector2f pos, sf::Vector2f velocity) {
    int type = rand() % 3;
    ...
    switch (type) {
        case 0: shape = std::make_unique<CircleShapeObj>(...); break;
        case 1: shape = std::make_unique<RectangleShapeObj>(...); break;
        default: shape = std::make_unique<TriangleShapeObj>(...); break;
    }
    shape->setVelocity(velocity);
    return shape;
}
```

This is the **Factory Method** pattern from lecture: the decision of *which
concrete class to construct* is centralized in one function, and every caller
(`Page1`'s constructor, `Page2`'s constructor) just gets back a `Shape*` and
never has to know or spell out `CircleShapeObj` themselves. Add a fourth shape
type later, and only `ShapeFactory.cpp` changes — `Page1.cpp`/`Page2.cpp` don't.

`randomVelocity()` lives in the same file for a similar reason: both pages
need "a random slow velocity," and centralizing it means changing the speed
range in one place changes it everywhere (see the "1/4 speed" change made
earlier — it was a one-line edit to `randomSpeedComponent()`).

---

## `AppManager` and `Page`: unchanged from `Pages`

`AppManager` is still a **Singleton** (private constructor, `getInstance()`,
one `sf::RenderWindow` for the whole program) and `Page` is still a small
**abstract interface** (`handleEvent` / `update` / `draw`, all pure virtual).
Neither needed to change for this project — the shape hierarchy is entirely
new code sitting *underneath* the existing page-navigation design. That's a
sign the original design had good separation of concerns: adding a new kind
of on-screen object didn't require touching how pages are switched.

---

## `Page1`: movement, no clicking

```cpp
void Page1::update() {
    sf::Vector2u size = AppManager::getInstance().getWindow().getSize();
    for (auto& obj : objects) {
        obj->bounce(size.x, size.y);
    }
}
```

`Page1` builds 5 shapes via the factory, and every frame calls `bounce()` on
each — that's the entire "movement" feature, because `bounce()` is defined
once on `Shape`. `Page1::handleEvent` only checks the `Next Page`/`Quit`
buttons; it never calls `isClicked()` on the shapes themselves, per the spec
("we don't care about click here").

## `Page2`: click-to-remove, then auto-return

```cpp
for (auto it = shapes.begin(); it != shapes.end(); ++it) {
    if ((*it)->isClicked(mousePos)) {
        shapes.erase(it);
        break;
    }
}

if (shapes.empty()) {
    AppManager::getInstance().changePage(std::make_unique<Page1>());
    return; // this Page2 has just been destroyed; touch nothing else
}
```

Same `Shape` interface, different usage: `Page2` also bounces its shapes
(`update()` is identical in shape to `Page1`'s), but on a left click it walks
the vector, finds the first shape whose `isClicked()` returns true, and erases
it — which is the whole "remove from the draw list" requirement, since `draw()`
just iterates whatever's left in `shapes`. When the vector empties, it hands
control back to `Page1` through `AppManager`.

**Careful bit:** `changePage()` replaces `AppManager`'s `unique_ptr<Page>`,
which destroys the current `Page2` object immediately — while `Page2::handleEvent`
is still executing on that very object (`this`). The `return` right after is
not just tidy control flow, it's load-bearing: nothing after that line may
touch `this` or any member, because the object may no longer exist. This same
pattern was already present in the original `Pages` project's `Next Page`/`Back`
buttons; `Page2` just reuses it for the "ran out of shapes" case too.

---

## The dependency picture

```
main.cpp
  └── AppManager (Singleton)
        └── Page (abstract)
              ├── Page1 ──┐
              └── Page2 ──┤
                           ├── Shape (abstract)
                           │     ├── CircleShapeObj
                           │     ├── RectangleShapeObj
                           │     └── TriangleShapeObj
                           └── ShapeFactory (creates Shape subclasses)
```

Everything above the dotted line (`Page1`, `Page2`) only ever depends on
`Shape`'s interface and `ShapeFactory`'s two functions — never on a concrete
shape class by name. That's the payoff of the abstract-class design: the pages
are written entirely in terms of "a `Shape`," and stay correct no matter how
many concrete shape types exist underneath.
