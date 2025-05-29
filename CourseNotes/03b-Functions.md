# Functions in C and C++

Functions allow you to **break your program into smaller reusable blocks**, making code more organized, readable, and easier to debug.

---

## Why Use Functions?

- Group related operations together
- Avoid repeating code
- Make programs easier to read
- Help with testing and debugging
- Enable modular design

---

## Function Basics

### Function Syntax in C/C++

```c
return_type function_name(parameter_list)
{
    // body of the function
}
```

To use a function:
1. **Declare it** (also called a function prototype)
2. **Define it**
3. **Call it** from `main()` or another function

---

## Clean Example: Function That Prints and Adds

### C Version

```c
#include <stdio.h>

// Function prototype (declaration)
float print_then_add(int x, float y);

int main() {
    // declare variables
    int i_am_an_integer = 11;
    char i_am_a_char = 'c';
    float i_am_a_float = 1.23;
    double i_am_a_double = 1.23;
    float sum;

    // print the values
    printf("This is an integer: %i\n", i_am_an_integer);
    printf("This is a char: %c\n", i_am_a_char);
    printf("This is a float: %2.3f\n", i_am_a_float);
    printf("This is a double: %f\n", i_am_a_double);

    // function call
    sum = print_then_add(i_am_an_integer, i_am_a_float);

    printf("The sum of the integer and float is: %3.5f\n", sum);

    return 0;
}

// Function definition
float print_then_add(int x, float y) {
    printf("The value of x in the function is: %d\n", x);
    printf("The value of y in the function is: %f\n", y);
    return x + y;
}
```

---

### C++ Version

The same logic applies with minor changes:

```cpp
#include <iostream>
using namespace std;

// Function prototype
float print_then_add(int x, float y);

int main() {
    int i_am_an_integer = 11;
    char i_am_a_char = 'c';
    float i_am_a_float = 1.23;
    double i_am_a_double = 1.23;
    float sum;

    cout << "This is an integer: " << i_am_an_integer << endl;
    cout << "This is a char: " << i_am_a_char << endl;
    cout << "This is a float: " << i_am_a_float << endl;
    cout << "This is a double: " << i_am_a_double << endl;

    sum = print_then_add(i_am_an_integer, i_am_a_float);

    cout << "The sum of the integer and float is: " << sum << endl;

    return 0;
}

float print_then_add(int x, float y) {
    cout << "The value of x in the function is: " << x << endl;
    cout << "The value of y in the function is: " << y << endl;
    return x + y;
}
```

---

## Function Structure Breakdown

| Part             | Purpose                                |
|------------------|----------------------------------------|
| **Prototype**    | Declares the function before main      |
| **Definition**   | Contains the actual code               |
| **Call**         | Executes the function with arguments   |

---

## Notes

- Functions must be **declared** before use (unless defined before `main()`).
- You must **match the types** in the function prototype and definition.
- The `main()` function must return `int` in standard C/C++.
- Use `return` to give a value back to the caller.

---
