# The Cast Operator in C and C++

In C and C++, a **cast** temporarily changes the type of a value **within an expression**.

---

## Why Use the Cast Operator?

In C and C++, when both operands in a division are integers, the result is also an integer. That means:

```c
int result = 3 / 8;   // result will be 0, not 0.375
```

If you're calculating a value like a stock price using mixed units, integer division can lead to incorrect results.

---

## Fixing It with a Cast

Suppose we have this code:

```c
int sell_whole = 11;
int sell_numer = 3;
int sell_denom = 8;
float price;

price = sell_whole + sell_numer / sell_denom;   // WRONG: 3/8 = 0 → price = 11.0
```
# The Cast Operator in C and C++

In C and C++, a **cast** temporarily changes the type of a value **within an expression**.

---

## Why Use the Cast Operator?

In C and C++, when both operands in a division are integers, the result is also an integer. That means:

```c
int result = 3 / 8;   // result will be 0, not 0.375
```

If you're calculating a value like a stock price using mixed units, integer division can lead to incorrect results.

---

## Fixing It with a Cast

Suppose we have this code:

```c
int sell_whole = 11;
int sell_numer = 3;
int sell_denom = 8;
float price;

price = sell_whole + sell_numer / sell_denom;   // WRONG: 3/8 = 0 → price = 11.0
```

To fix it, we temporarily cast one or both operands to a float:

```c
price = sell_whole + (float)sell_numer / (float)sell_denom;  // CORRECT: 3/8 = 0.375 → price = 11.375
```

---

## Cast Syntax

```c
(type) expression
```

✅ Notes:

- The cast does **not** change the variable’s actual type in memory.
- The cast is **temporary** and applies only to the expression it's in.
- You can cast to `float`, `double`, `int`, `char`, etc.

---

## C Example

```c
#include <stdio.h>

int main() {
    int numer = 1;
    int denom = 2;
    float result;

    result = (float)numer / denom;
    printf("Result: %f\n", result);  // Output: 0.500000

    return 0;
}
```

---

## C++ Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int numer = 5;
    int denom = 2;

    float result = static_cast<float>(numer) / denom;
    cout << "Result: " << result << endl;  // Output: 2.5

    return 0;
}
```

In C++, you can also use **C-style casts** like `(float)numer`, but `static_cast<float>(...)` is preferred in modern C++ for clarity and safety.

---

## When to Use Casting

- When mixing `int` and `float` in a calculation and precision matters
- When a library function expects a specific type
- When you want to **temporarily change how a value is treated**, without changing the actual variable

---

## Common Mistake

```c
int x = 3, y = 8;
float result = (float)(x / y);  // Still 0.0, because x / y happens first (as int division)
```

✅ Correct:

```c
float result = (float)x / y;  // Converts before division → 0.375
```

---

## Summary

- Casting lets you control the type used in a calculation.
- It does **not** permanently change the variable's type.
- Use it when you need **precision**, especially in division.
- In C++, prefer `static_cast<type>(expression)` over C-style `(type)` casts.


To fix it, we temporarily cast one or both operands to a float:

```c
price = sell_whole + (float)sell_numer / (float)sell_denom;  // CORRECT: 3/8 = 0.375 → price = 11.375
```

---

## Cast Syntax

```c
(type) expression
```

Notes:

- The cast does **not** change the variable’s actual type in memory.
- The cast is **temporary** and applies only to the expression it's in.
- You can cast to `float`, `double`, `int`, `char`, etc.

---

## C Example

```c
#include <stdio.h>

int main() {
    int numer = 1;
    int denom = 2;
    float result;

    result = (float)numer / denom;
    printf("Result: %f\n", result);  // Output: 0.500000

    return 0;
}
```

---

## C++ Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int numer = 5;
    int denom = 2;

    float result = static_cast<float>(numer) / denom;
    cout << "Result: " << result << endl;  // Output: 2.5

    return 0;
}
```

In C++, you can also use **C-style casts** like `(float)numer`, but `static_cast<float>(...)` is preferred in modern C++ for clarity and safety.

---

## When to Use Casting

- When mixing `int` and `float` in a calculation and precision matters
- When a library function expects a specific type
- When you want to **temporarily change how a value is treated**, without changing the actual variable

---

## Common Mistake

```c
int x = 3, y = 8;
float result = (float)(x / y);  // Still 0.0, because x / y happens first (as int division)
```

Correct:

```c
float result = (float)x / y;  // Converts before division → 0.375
```

---
