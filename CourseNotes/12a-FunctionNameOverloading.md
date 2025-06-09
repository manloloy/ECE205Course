# Function Overloading in C++

## Objective
This module introduces students to the concept of function overloading in C++. Function overloading allows multiple functions to share the same name as long as their parameter lists differ. Students will learn how to define and invoke overloaded functions and understand how the compiler resolves the correct function to call.

---

## Background

Function overloading is a powerful feature of C++ that enables defining multiple functions with the same name but different parameter lists. This makes programs more intuitive and organized, especially when the functions perform conceptually similar operations.

Function overloading is resolved at compile-time through a process known as **static polymorphism**.

---

## Key Rules of Function Overloading

1. **Different Number of Parameters**  
   Two functions can be overloaded if they differ in the number of parameters.
2. **Different Types of Parameters**  
   Functions can be overloaded if their parameter types differ.
3. **Return Type Does Not Influence Overloading**  
   Overloading is determined by the parameter list, not the return type.
4. **Ambiguity Errors**  
   The compiler must be able to uniquely determine which function to call. Ambiguity between overloaded functions causes compiler errors.
5. **Overloading and Default Parameters**  
   Overloaded functions that use default parameter values must be designed carefully to avoid ambiguous matches.

---

## Syntax Example

```cpp
#include <iostream>
#include <string>
using namespace std;

// Overloaded version 1: Uses int for month
void PrintDate(int day, int month, int year) {
    cout << month << "/" << day << "/" << year;
}

// Overloaded version 2: Uses string for month
void PrintDate(int day, string month, int year) {
    cout << month << " " << day << ", " << year;
}

int main() {
    PrintDate(30, 7, 2012);           // Calls version with int month
    cout << endl;
    PrintDate(30, "July", 2012);      // Calls version with string month
    cout << endl;
    return 0;
}
