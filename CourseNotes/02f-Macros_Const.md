# Macros in C and C++

This module introduces the use of **macros** in C and C++ for constants, expressions, and reusable logic.

---

## Simple Macros

Macros are symbolic names defined using the preprocessor directive `#define`.

```c
#define TRUE 1
#define FALSE 0
#define MAX_SCORE 100
#define PI 3.14159
```

When the preprocessor runs, it replaces every occurrence of these names with their values **before compilation**.

Example:

```c
if (denom == 0) return FALSE;  // becomes → return 0;
```

---

## Why Use Macros?

- Makes code easier to read and maintain
- Eliminates “magic numbers”
- Allows centralized changes
- Avoids memory use (macros are not variables)

---

## Macros with Arguments

Macros can be defined with **parameters** (similar to functions) to make them more general and reusable.

### Example

```c
#define MULTIPLE_OF_3(x) (((x) % 3) == 0)
```

Usage:

```c
if (MULTIPLE_OF_3(nickels)) {
    printf("nickels is a multiple of 3\n");
}

if (MULTIPLE_OF_3(dimes)) {
    printf("dimes is a multiple of 3\n");
}
```

The preprocessor expands the macro before compilation:

```c
if ((((nickels) % 3) == 0))
```

---

## Example: Macro with Two Arguments

```c
#define PICK(start, stop) (rand() % ((stop) - (start) + 1) + (start))
```

Usage:

```c
int hidden_number = PICK(1, 100);
```

This expands to:

```c
int hidden_number = (rand() % ((100) - (1) + 1) + (1));
```

Notice the **excessive parentheses** — this is intentional.

---

## Care in Defining Macros with Arguments

Macros are textual replacements. Without proper parentheses, operator precedence may lead to incorrect results.

### Example 1: Missing parentheses

```c
#define PRODUCT(x, y) x * y

int a = PRODUCT(2+3, 4+5);  // Expands to: a = 2+3 * 4+5;
```

Which actually computes:

```c
a = 2 + (3 * 4) + 5;  // → 19, not 45
```

### Correct Definition:

```c
#define PRODUCT(x, y) ((x) * (y))

int a = PRODUCT(2+3, 4+5);  // Expands to: ((2+3) * (4+5)) → 45
```

---

### Example 2: Combined with Division

```c
#define PRODUCT(x, y) ((x) * (y))

int a = PRODUCT(b, c) / PRODUCT(d, e);
```

Expands to:

```c
a = ((b) * (c)) / ((d) * (e));
```

Which is correct and preserves the intended evaluation order.

---

## What to consider

- Always wrap **macro arguments** and the **whole macro body** in parentheses.
- Avoid side effects in macro arguments (`x++`) — they may be evaluated multiple times.
- Prefer `const` or `constexpr` in C++ when possible, especially for type safety.


# `const` and `constexpr` in C++

In C++, we use `const` and `constexpr` to define values that do not change. This helps prevent bugs and makes programs easier to reason about.

---

## `const`: Read-Only Variables

A `const` variable is one whose value **cannot be modified** after it is initialized.

```cpp
const int max_score = 100;
```

- Must be initialized at the time of declaration
- Can be used to protect values that should not change
- Enforced at compile-time

### Example

```cpp
#include <iostream>
using namespace std;

int main() {
    const float pi = 3.14159;
    // pi = 3.14;  // Error: assignment of read-only variable
    cout << "Pi = " << pi << endl;
    return 0;
}
```

---
---

# constexpr: Compile-Time Constants

A `constexpr` is a constant whose value must be **computable at compile time**.

```cpp
constexpr int square(int x) {
    return x * x;
}

int arr[square(5)];  // Legal: size known at compile time
```

- Functions marked `constexpr` must contain a single return statement or valid constexpr logic
- Enables safer and more optimized code
- Introduced in C++11, expanded in later standards

---

## `const` vs `constexpr`

| Feature          | `const`                         | `constexpr`                     |
|------------------|----------------------------------|----------------------------------|
| Value known at   | Run time or compile time         | Compile time only               |
| Initialized with | Any valid expression             | Constant expressions only       |
| Used for         | Read-only values                 | Constant expressions, array sizes, etc. |
| Function use     | Cannot be used to define functions | Can define simple constexpr functions |

---

## Example: Using Both

```cpp
#include <iostream>
using namespace std;

constexpr int cube(int x) {
    return x * x * x;
}

int main() {
    const int width = 5;
    constexpr int height = 10;
    constexpr int volume = cube(3);  // 27

    cout << "Volume: " << volume << endl;
    return 0;
}
```

---

## When to Use

- Use `const` for read-only values that **might depend on runtime input**
- Use `constexpr` when you know a value **can and should be computed at compile time**

