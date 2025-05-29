# Lab 01D: Reverse Binary (While Loop Practice)

## Objective

This lab provides practice using `while` loops in C and C++. You will write a program that takes a positive integer as input and outputs its **reverse binary representation**.

---

## Background

In binary, numbers are represented as sequences of 0s and 1s. For example:
- `6` in binary is `110`
- The **reverse** of this binary string is `011`

We can compute the reverse binary of a number using repeated division by 2 and recording the remainders:
1. While the number is greater than 0:
   - Output the remainder of `number % 2`
   - Update the number to `number / 2`

This process continues until the number becomes 0.

---

## Input

A single positive integer.

---

## Output

A string of 0s and 1s representing the reverse binary of the input number.

---

## Sample Input

```
6
```

## Sample Output

```
011
```

---

## C Template

```c
#include <stdio.h>

int main() {
    int userNum;

    // TODO: Read input and print reverse binary

    return 0;
}
```

---

## C++ Template

```cpp
#include <iostream>
using namespace std;

int main() {
    int userNum;

    // TODO: Read input and print reverse binary

    return 0;
}
```

---

## Hints

- Use a `while` loop to repeatedly divide the input by 2.
- Print the result of `userNum % 2` inside the loop.
- Continue until `userNum` is 0.

---




