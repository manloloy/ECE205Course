# Lab 02C: Array Normalization

## Objective

Practice working with arrays and loops in both C and C++. This lab will help reinforce your understanding of:

- Array declaration and initialization
- Reading input into arrays
- Finding the maximum value
- Normalizing values
- Output formatting with two decimal places

> **Learning Tip**: Avoid using advanced libraries like `vector` or `iomanip` for this lab. This is intentional to help you gain confidence with lower-level constructs before advancing.

---

## Task

Given a sequence of floating-point numbers, normalize the values by dividing each element by the largest value in the array. The first input value will specify how many numbers follow.

### Input Format

- An integer `n` indicating how many floating-point values follow
- `n` floating-point values

### Output Format

- Each input value divided by the largest value, printed on the same line, each rounded to **two decimal places** and followed by a space.

---

## Example Input

```
5 30.0 50.0 10.0 100.0 65.0
```

## Expected Output

```
0.30 0.50 0.10 1.00 0.65 
```

---

## C Template

```c
#include <stdio.h>

int main() {
    int numValues;
    double values[100];  // Assuming input won't exceed 100 values
    double maxValue;
    
    // TODO: Read input values and store in array

    // TODO: Find the maximum value

    // TODO: Print normalized values

    return 0;
}
```

---

## C++ Template

```cpp
#include <iostream>
using namespace std;

int main() {
    int numValues;
    double values[100];  // Fixed-size array
    double maxValue;

    // TODO: Read input values

    // TODO: Find max value

    // TODO: Output normalized values with two decimals

    return 0;
}
```

---


