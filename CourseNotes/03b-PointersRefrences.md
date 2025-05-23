# Pointers and References in C and C++

This module introduces **pointers** (C and C++) and **references** (C++ only), which allow access to variables indirectly. These concepts are central to memory management, function argument passing, and efficient data manipulation.

---

## Pointers (C and C++)

A **pointer** is a variable that stores the memory address of another variable.

### Declaration

```c
int *ptr;  // pointer to int
```

### Core Operators

| Symbol | Description                        |
|--------|------------------------------------|
| `&x`   | Address of `x`                     |
| `*ptr` | Value at the address `ptr` points to |

---

### Example (C)

```c
#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;

    printf("x = %d\n", x);      // 10
    printf("*p = %d\n", *p);    // 10

    *p = 20;
    printf("x = %d\n", x);      // 20

    return 0;
}
```

---

### Example (C++)

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int *p = &x;

    cout << "x = " << x << endl;
    cout << "*p = " << *p << endl;

    *p = 20;
    cout << "x = " << x << endl;

    return 0;
}
```

---

## Pointer Arithmetic

Pointers can be incremented to move through an array:

```c
int arr[] = {10, 20, 30};
int *p = arr;

for (int i = 0; i < 3; i++) {
    printf("%d ", *p);
    p++;
}
```

This works because array elements are stored in contiguous memory.

---

## References (C++ Only)

A **reference** is an alias for another variable. Unlike a pointer, it **must be initialized** and **cannot be changed** to refer to something else.

### Declaration

```cpp
int x = 5;
int &ref = x;  // ref is a reference to x
```

- No need for `*` to access the value
- No need for `&` to get the address when passing to functions

---

### Reference Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int &r = x;

    cout << "x = " << x << endl;
    cout << "r = " << r << endl;

    r = 25;
    cout << "x = " << x << endl;  // 25

    return 0;
}
```

---

### References in Functions

```cpp
void increment(int &ref) {
    ref = ref + 1;
}

int main() {
    int value = 5;
    increment(value);  // modifies original variable
    cout << value << endl;  // 6
}
```

---

## Pointers vs. References

| Feature           | Pointer                | Reference            |
|------------------|------------------------|----------------------|
| Syntax            | `int *p`              | `int &r`             |
| Needs initialization? | No               | Yes                  |
| Can change target?     | Yes              | No                   |
| Can be null?      | Yes                    | No                   |
| Used in C?        | Yes                    | No                   |
| Requires dereferencing (`*`) | Yes         | No                   |

---

## Notes

- Use **pointers** in C and when working with arrays or dynamic memory.
- Use **references** in C++ when you want to pass variables **by reference** safely and simply.
- Do not confuse the `&` symbol:
  - In a declaration (`int &r`) → it means "reference"
  - In an expression (`&x`) → it means "address of"

