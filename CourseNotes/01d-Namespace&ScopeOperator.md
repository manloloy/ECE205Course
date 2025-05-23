# C++ Namespaces

Namespaces are a **C++-specific** feature used to organize code and prevent name conflicts between variables or functions that might otherwise have the same name.

---

## Why Use Namespaces?

In large programs (or when using libraries), it's common for two parts of the program to define variables or functions with the **same name**. A **namespace** solves this by letting you group code together and **access it using a scope operator** (`::`).

---

## Syntax

```cpp
namespace my_namespace {
    int value = 5;
    int func() { return value + 10; }
}
```

You can access items within a namespace using the `::` operator:

```cpp
int x = my_namespace::value;
int y = my_namespace::func();
```

---

## Example: Multiple Namespaces

```cpp
#include <stdio.h>

namespace space1 {
    int x = 1;
    int fun() { return 10; }
}

namespace space2 {
    float x = 1;
    float fun() { return 2 * x; }
}

int main() {
    // Access things within namespace space1
    printf("In space1 x = %d\n", space1::x);
    printf("fun call in space1 returned = %d\n", space1::fun());

    // Access things within namespace space2
    printf("In space2 x = %f\n", space2::x);
    printf("fun call in space2 returned = %f\n", space2::fun());

    return 0;
}
```

---

## Key Points

- The `::` operator is called the **scope resolution operator**.
- You can use it to access **variables**, **functions**, and even **classes** inside a namespace.
- Namespaces help you **organize code** and avoid **name collisions**.
- We'll see this used more later when working with C++ **standard library features** like `std::cout`.

---

## Optional: Namespace Shortcuts

If you're using one namespace frequently, you can write:

```cpp
using namespace space1;
```

Then use `x` or `fun()` directly. But be cautious — this can reintroduce name collisions, especially in large projects.
