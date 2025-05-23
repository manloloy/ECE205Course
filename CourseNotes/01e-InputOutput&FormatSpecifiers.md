# Input and Output in C and C++

In this module, we explore how to get data **at runtime** and how to control how it's **formatted for output**.

---

## Input in C Using `scanf()`

```c
scanf("%d", &variable);  // Reads an integer
```

Use `&` to pass the **address** of the variable.

---

## Input in C++ Using `cin`

```cpp
cin >> variable;  // Automatically handles types
```

No `&` required — C++ handles it for you behind the scenes.

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

For advanced formatting, C++ uses the `<iomanip>` header.

---

## 📏 Format Specifiers

### Common `printf()` Conversion Specifiers (C)

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

### Formatting Output in C++ with `iomanip`

To control C++ output formatting, include:

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

You can read multiple values in a single line or across multiple lines using both `scanf()` and `cin`.

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

- Works if input is: `100 5.25` (on the same line)
- Also works if input is:
  ```
  100
  5.25
  ```

`scanf()` automatically skips whitespace and reads each input value in order.

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

- Works with input on the same line: `100 5.25`
- Also works with input on different lines:
  ```
  100
  5.25
  ```

Like `scanf()`, `cin` **skips whitespace** and reads values in order.

---

## Notes

- Both `scanf()` and `cin` **read tokens** separated by whitespace (spaces, tabs, or newlines).
- Both will **block** until all requested values are provided.
- The order of input **must match** the order of variables in the code.
