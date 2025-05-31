# Lab 02D: Functions and Random Values — Coin Flip Simulation

## Objective

- Practice defining and calling user-defined functions.
- Learn how to generate random numbers using `rand()` and `srand()` in C and C++.
- Use a loop to simulate repeated coin flips.

## Description

You will write a function named `CoinFlip` that randomly returns either `"Heads"` or `"Tails"` using the value from a random number generator. A main program will ask the user how many coin flips to perform and call the function that many times, printing each result on a new line.

### Behavior

- The value `1` means `"Heads"`, and `0` means `"Tails"`.
- Use a fixed seed (`srand(2)`) for predictable results during testing.
- Use `rand() % 2` to generate a value of either 0 or 1.

## Sample Input

```
3
```

## Expected Output

```
Tails
Heads
Tails
```

*Note: Output depends on the fixed seed (`srand(2)`).*

---

## Tips

- In C and C++, use `rand()` from `<stdlib.h>` to get random numbers.
- Always use `srand(seed)` once before your first call to `rand()` to ensure reproducibility.
- Use `rand() % 2` to get either 0 or 1.
- In C, return a `const char*` string. In C++, use `string` from `<string>`.

---

## C Template

```c
#include <stdio.h>
#include <stdlib.h>

/* Define your function here */

int main() {
    // TODO: Declare variables
    srand(2);  // Set the random seed

    // TODO: Get input and call CoinFlip function

    return 0;
}
```

---

## C++ Template

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

/* Define your function here */

int main() {
    // TODO: Declare variables
    srand(2);  // Set the random seed

    // TODO: Get input and call CoinFlip function

    return 0;
}
```

---
