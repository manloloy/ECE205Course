# Lab 01C: Leap Year Checker

## Objective

This lab introduces conditional logic through the task of checking whether a given year is a leap year. You will practice using `if`/`else` statements in both C and C++.

---

## Problem Description

The Gregorian calendar has a special rule for accounting for the Earth's orbital period. A **leap year** is a year that has **366 days** instead of the usual **365 days**. The extra day is February 29.

A year is a **leap year** if:
1. It is divisible by 4,
2. **Except** for years that are divisible by 100,
3. **Unless** the year is also divisible by 400.

### Examples:
- 1600 → leap year  
- 1800 → not a leap year  
- 2000 → leap year  
- 2013 → not a leap year  
- 2020 → leap year  

---

## Input

A single integer representing a year.

---

## Output

A message stating whether the input year is a leap year or not, in the following format:

```
<year> - leap year
```

or

```
<year> - not a leap year
```

---

## Sample Input / Output

**Input:**
```
1712
```

**Output:**
```
1712 - leap year
```

**Input:**
```
1913
```

**Output:**
```
1913 - not a leap year
```

---

## Recommendation

Use `if`, `else`, and nested conditionals to determine leap year status. This is a good opportunity to practice decision-making structures in both C and C++.

---

## C Template

```c
#include <stdio.h>

int main() {
    int inputYear;
    int isLeapYear = 0; // Use 1 for true, 0 for false

    scanf("%d", &inputYear);

    // TODO: Add leap year logic

    return 0;
}
```

---

## C++ Template

```cpp
#include <iostream>
using namespace std;

int main() {
    int inputYear;
    bool isLeapYear = false;

    cin >> inputYear;

    // TODO: Add leap year logic

    return 0;
}
```




