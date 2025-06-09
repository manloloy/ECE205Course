# Exception Handling in C++

## Overview

In this lecture, we introduce **exception handling** in C++. Exception handling provides a structured way to detect and respond to runtime errors that disrupt the normal flow of execution, such as invalid input or file failures.

C++ uses three primary constructs for exception handling:

- `try`: Defines a block of code that may throw an exception.
- `throw`: Signals that an error has occurred.
- `catch`: Defines how to handle a specific exception type.

---

## Motivation: Error Checking Without Exceptions

Consider a simple Body Mass Index (BMI) calculator without error checking:

```cpp
#include <iostream>
using namespace std;

int main() {
   int weightVal, heightVal;
   float bmiCalc;
   char quitCmd = 'a';

   while (quitCmd != 'q') {
      cout << "Enter weight (in pounds): ";
      cin >> weightVal;

      cout << "Enter height (in inches): ";
      cin >> heightVal;

      bmiCalc = (static_cast<float>(weightVal) / (heightVal * heightVal)) * 703.0;
      cout << "BMI: " << bmiCalc << endl;
      cout << "(CDC: 18.6-24.9 normal)" << endl;

      cout << "\nEnter any key ('q' to quit): ";
      cin >> quitCmd;
   }
   return 0;
}
```

There is no handling for invalid input like negative height or zero.

---

## Traditional Error Checking with If-Else

Naively adding `if` checks leads to repetitive and cluttered code:

```cpp
if (weightVal < 0 || heightVal <= 0) {
    cout << "Invalid input. Cannot compute BMI." << endl;
} else {
    bmiCalc = ...;
}
```

This mixes normal logic with error handling, which can obscure code readability.

---

## Exception Handling Syntax

C++ provides a clearer separation of normal logic and error handling:

```cpp
try {
    // Code that might throw an exception
    throw runtime_error("Something went wrong!");
}
catch (runtime_error& e) {
    cout << "Caught exception: " << e.what() << endl;
}
```

---

## Example: BMI Calculator with Exception Handling

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
   int weightVal, heightVal;
   float bmiCalc;
   char quitCmd = 'a';

   while (quitCmd != 'q') {
      try {
         cout << "Enter weight (in pounds): ";
         cin >> weightVal;
         if (weightVal <= 0) throw runtime_error("Invalid weight.");

         cout << "Enter height (in inches): ";
         cin >> heightVal;
         if (heightVal <= 0) throw runtime_error("Invalid height.");

         bmiCalc = (static_cast<float>(weightVal) / (heightVal * heightVal)) * 703.0;
         cout << "BMI: " << bmiCalc << endl;
         cout << "(CDC: 18.6-24.9 normal)" << endl;
      }
      catch (runtime_error& err) {
         cout << err.what() << endl;
         cout << "Cannot compute BMI." << endl;
      }

      cout << "\nEnter any key ('q' to quit): ";
      cin >> quitCmd;
   }
   return 0;
}
```

---

## Exceptions in Functions

Exceptions can be thrown in one function and caught in another, improving code reuse and clarity:

```cpp
int GetWeight() {
    int w;
    cout << "Enter weight: ";
    cin >> w;
    if (w <= 0) throw runtime_error("Invalid weight.");
    return w;
}

int GetHeight() {
    int h;
    cout << "Enter height: ";
    cin >> h;
    if (h <= 0) throw runtime_error("Invalid height.");
    return h;
}

int main() {
    try {
        int weight = GetWeight();
        int height = GetHeight();
        float bmi = (static_cast<float>(weight) / (height * height)) * 703.0;
        cout << "BMI: " << bmi << endl;
    }
    catch (runtime_error& err) {
        cout << err.what() << endl;
    }
    return 0;
}
```

---

## Multiple Catch Blocks

You can define more than one `catch` block for different exception types:

```cpp
try {
    // Code that might throw multiple types
}
catch (out_of_range& e) {
    cout << "Range error: " << e.what() << endl;
}
catch (runtime_error& e) {
    cout << "Runtime error: " << e.what() << endl;
}
catch (...) {
    cout << "Unknown error occurred." << endl;
}
```

---

## Summary

- Exception handling separates error logic from normal logic.
- `throw` signals an error; `try` protects error-prone code; `catch` handles it.
- Use exceptions in functions to propagate errors up the call chain.
- Catch blocks can be overloaded to handle multiple error types.

---

## Additional Resources

- [std::exception documentation](https://en.cppreference.com/w/cpp/error/exception)
- [runtime_error class](https://en.cppreference.com/w/cpp/error/runtime_error)

```cpp
// Custom exception class example (optional topic)
class InvalidBMIInput : public exception {
public:
   const char* what() const noexcept override {
      return "BMI input was invalid.";
   }
};
```

---

## Suggested Practice

- Add exception handling to a file reader that throws if the file fails to open.
- Create a calculator that throws if the denominator is zero.
- Modify your previous labs to throw exceptions when invalid input is detected.
