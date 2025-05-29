## Lab 01B: Coin Conversion

### Objective

Convert user-entered coin counts into a dollar amount.

---

### Input

Four integers: number of quarters, dimes, nickels, and pennies.

---

### Output

A dollar amount, formatted to 2 decimal places.

---

### Sample Input

```
4 3 2 1
```

---

### Expected Output

```
Amount: $1.41
```

---

### Notes for Students

- Use `scanf()` and `printf()` for C programs.
- Use `cin` and `cout` for C++ programs.
- Use `fixed` and `setprecision(2)` in C++ to control decimal formatting.
- In C, use `%.2f` in `printf()` to format output to 2 decimal places.

---

### C Template

```c
#include <stdio.h>

int main() {
    int quarters, dimes, nickels, pennies;
    double dollars;

    // TODO: Read input and calculate dollar value

    return 0;
}
```

---

### C++ Template

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int quarters, dimes, nickels, pennies;
    double dollars;

    // TODO: Read input and calculate dollar value

    return 0;
}
```



