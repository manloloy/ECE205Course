# Function Templates in C++

## Overview

This module introduces **function templates** in C++, a powerful feature that allows functions to operate on multiple data types without rewriting code. Function templates enable **generic programming**, where the same function logic can be applied to different types — such as `int`, `double`, or `std::string` — making code **more reusable and maintainable**.

This lecture is suitable for students in an upper-division programming course at a research university. It assumes a solid foundation in functions, references, and type declarations in C++.

---

## Objectives

By the end of this module, students should be able to:

- Understand the syntax and semantics of function templates in C++
- Write and call basic function templates with one or more type parameters
- Recognize when to use function templates over function overloading
- Understand type inference and explicit template specification
- Extend template functions using multiple parameters or constraints (brief introduction)

---

## Motivation

Suppose you want to write a function to find the maximum of two values. You could write three different functions:

```cpp
int max(int a, int b) {
    return (a > b) ? a : b;
}

double max(double a, double b) {
    return (a > b) ? a : b;
}

char max(char a, char b) {
    return (a > b) ? a : b;
}
```

This violates the **DRY (Don't Repeat Yourself)** principle.

Instead, we can use a **function template** to write this once and use it for any comparable type:

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

---

## Syntax: Basic Function Template

```cpp
template <typename T>
ReturnType functionName(T param1, T param2) {
    // Function body
}
```

- `template <typename T>`: Introduces the template and type parameter `T`
- `T`: A placeholder type, replaced during compilation when the function is instantiated
- You may also use `template <class T>`, which is equivalent

### Example: Maximum of Two Values

```cpp
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int a = 3, b = 5;
    double x = 2.3, y = 7.8;

    std::cout << maxValue(a, b) << "\n";   // uses int
    std::cout << maxValue(x, y) << "\n";   // uses double
}
```

---

## Type Inference and Explicit Specification

C++ usually **infers** the template type automatically:

```cpp
std::string s1 = "apple", s2 = "banana";
std::cout << maxValue(s1, s2) << "\n";  // T is inferred as std::string
```

But you can also **explicitly specify** the type if needed:

```cpp
std::cout << maxValue<double>(3, 4.5) << "\n";  // T is double
```

This can be useful when mixing types or ensuring precision.

---

## Multiple Template Parameters

Function templates can have more than one type parameter.

```cpp
template <typename T1, typename T2>
void printPair(T1 a, T2 b) {
    std::cout << "(" << a << ", " << b << ")\n";
}

int main() {
    printPair(10, 3.14);       // T1 = int, T2 = double
    printPair("age", 25);      // T1 = const char*, T2 = int
}
```

---

## Template Limitations and Notes

- The compiler must generate a separate function for each unique set of parameter types.
- Template functions must be fully visible to the compiler, so they are typically defined in header files.
- Not all operations are valid for all types. For example, calling `maxValue("apple", "banana")` compares C-style pointers, not string values. Use `std::string` instead.

---

## Comparison: Function Templates vs Function Overloading

| Feature                  | Function Overloading         | Function Templates                  |
|--------------------------|------------------------------|--------------------------------------|
| Code reuse               | Limited, requires duplication | High, uses one function for all types |
| Flexibility              | Only works for predefined types | Works for any type that supports required operations |
| Type safety              | Strong                       | Strong                               |
| Resolution time          | Compile-time                 | Compile-time                         |

---

## Extension: Constraints (C++20 and above)

Templates can be constrained using concepts (if compiler supports C++20):

```cpp
#include <concepts>

template <typename T>
requires std::integral<T>
T square(T x) {
    return x * x;
}
```

This restricts `square()` to integral types only.

---


---

## Practice Exercises

1. Write a function template that returns the **minimum** of three values.
2. Write a function template that swaps two values using references.
3. Write a function template `isEqual<T>` that compares two values for equality.
4. Extend `printPair()` to return a `std::string` instead of printing to screen.
5. Use a function template to return the average of an array of numbers.

---

