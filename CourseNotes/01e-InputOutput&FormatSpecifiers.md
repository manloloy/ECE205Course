# C++ Module: Input, Output, and Type Deduction (`auto`)

In this module, we explore:

- How to perform **input and output** in both C and C++
- How to **format output** cleanly
- How C++ can **automatically infer types** using the `auto` keyword

---

## Input in C Using `scanf()`

```c
scanf("%d", &variable);  // Reads an integer
```

Use `&` to pass the **address** of the variable so `scanf()` can store the input.

---

## Input in C++ Using `cin`

```cpp
cin >> variable;  // Automatically handles types
```

In C++, there's no need for `&`. The input system uses references and operator overloading behind the scenes.

---

## Output in C Using `printf()`

```c
printf("Total = %d\n", total);
```

---

## Output in C++ Using `cout`

```cpp
cout << "Total = " << total << endl;
```

C++’s `cout` uses the `<<` operator to print values, and `endl` is used to move to a new line.

---

## Format Specifiers in C (`printf()`)

| Specifier | Meaning                        | Example Input | Example Output |
|-----------|--------------------------------|----------------|----------------|
| `%d`      | Integer (decimal)              | `42`           | `42`           |
| `%f`      | Float (decimal notation)       | `3.14`         | `3.140000`     |
| `%.2f`    | Float (2 decimal places)       | `3.14159`      | `3.14`         |
| `%c`      | Single character               | `'A'`          | `A`            |
| `%s`      | String                         | `"Hello"`      | `Hello`        |
| `%x`      | Integer (hex lowercase)        | `255`          | `ff`           |
| `%X`      | Integer (hex uppercase)        | `255`          | `FF`           |
| `%o`      | Integer (octal)                | `8`            | `10`           |
| `%%`      | Percent sign                   | (n/a)          | `%`            |

---

## Formatting Output in C++ with `iomanip`

Include:

```cpp
#include <iomanip>
```

| Manipulator         | Description                                | Example                             | Output           |
|---------------------|--------------------------------------------|-------------------------------------|------------------|
| `std::setw(n)`      | Set field width                            | `setw(5) << 42`                     | `   42`          |
| `std::setprecision(n)` | Set number of significant digits       | `setprecision(4) << 3.14159`       | `3.142`          |
| `std::fixed`        | Use fixed-point notation                   | `fixed << setprecision(2)`         | `3.14`           |
| `std::left`         | Left-align output                          | `left << setw(5) << "hi"`          | `hi   `          |
| `std::right`        | Right-align output (default)               | `right << setw(5) << "hi"`         | `  hi`           |
| `std::showpoint`    | Always show decimal point for floats       | `showpoint << 5.0`                 | `5.00000`        |
| `std::hex`          | Output numbers in hexadecimal              | `hex << 255`                       | `ff`             |
| `std::oct`          | Output numbers in octal                    | `oct << 8`                         | `10`             |

---

## Reading Multiple Inputs

### C Example with `scanf()`

```c
#include <stdio.h>

int main() {
    int shares;
    float price;

    printf("Enter number of shares and price: ");
    scanf("%d %f", &shares, &price);

    printf("Shares: %d\n", shares);
    printf("Price: %.2f\n", price);

    return 0;
}
```

- Input: `100 5.25` (or on separate lines)
- `scanf()` handles whitespace and reads the values in order.

---

### C++ Example with `cin`

```cpp
#include <iostream>
using namespace std;

int main() {
    int shares;
    float price;

    cout << "Enter number of shares and price: ";
    cin >> shares >> price;

    cout << "Shares: " << shares << endl;
    cout << "Price: " << price << endl;

    return 0;
}
```

C++’s `cin` also ignores whitespace and reads values in order.

---

## Type Deduction with `auto` (C++11 and later)

C++ lets you avoid repeating types by using the `auto` keyword. The compiler automatically infers the variable type from the initializer.

### Example 1: Auto with Primitives

```cpp
#include <iostream>
using namespace std;

int main() {
    auto i = 5;        // int
    auto j = 5.0;      // double
    auto ch = 'A';     // char

    cout << "i: " << i << ", j: " << j << ", ch: " << ch << endl;

    return 0;
}
```

**Why use `auto`?**

- Avoids repetition with complex types (e.g., iterators, lambda expressions)
- Makes code more maintainable
- Encourages generic programming

---

### Example 2: Auto with Containers

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4};

    // Without auto
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;

    // With auto
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }

    return 0;
}
```

The second loop is easier to read and maintain.

---

## Table Summary

| Feature        | C                      | C++                        |
|----------------|------------------------|-----------------------------|
| Input          | `scanf()`              | `cin`                      |
| Output         | `printf()`             | `cout`                     |
| Formatting     | Format specifiers      | `iomanip` manipulators     |
| Type Deduction | Not available          | `auto` (C++11+)            |

### Key Takeaways:

- Use `scanf()` and `printf()` in C; `cin` and `cout` in C++
- Use `iomanip` for clean formatting in C++
- Use `auto` to simplify code and let the compiler deduce types

```cpp
auto total = 3 + 4.5; // deduces as double
```

This gives you modern, flexible, and readable code.
