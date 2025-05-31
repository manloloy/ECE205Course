# Lab 02E: Sorting Arrays with Functions (No Vectors)

## Objective

Practice writing and calling functions in C and C++. This lab emphasizes working with fixed-size arrays and basic sorting logic using function parameters passed by reference.

- Learn how to pass arrays by reference to a function.
- Practice writing a sorting algorithm (e.g., selection sort or bubble sort).
- Reinforce array traversal and swapping.
- Learn function declarations and definitions.

## Instructions

Write a program that reads a list of integers from input, stores the integers in a fixed-size array (not a `vector`), and then calls a function to sort the array in descending order. Output the sorted array with commas between values, including after the last value.

**Do not use C++ `vector` or C dynamic memory.** Stick to static arrays.

Your program must define and call the following function:

```
void SortArray(int arr[], int size);
```

### Input

- The first input value is an integer `n` (1 ≤ n ≤ 100), representing the number of values that follow.
- Followed by `n` integers to sort.

### Output

- Output the sorted values in descending order, separated by commas. End the output with a comma.

### Sample Input

```
5 10 4 39 12 2
```

### Expected Output

```
39,12,10,4,2,
```

## Learning Tips

- To pass an array to a function, use the syntax `void func(int arr[], int size)` in both C and C++.
- Sorting can be done using many algorithms. Try selection sort or bubble sort for simplicity.
- Use the `&` operator to read the address of a variable (used in swapping if needed).
- Static arrays in C/C++ do not know their size, so always pass the size as an additional argument.
- Arrays are always passed by reference in C/C++, so no need to use pointers explicitly for function arguments.

---

## C Template

```c
#include <stdio.h>

/* Define your function here */

int main() {
    int arr[100];
    int i, size;

    // TODO: Read input into arr

    // TODO: Call SortArray

    // TODO: Output sorted array

    return 0;
}
```

## C++ Template

```cpp
#include <iostream>
using namespace std;

/* Define your function here */

int main() {
    int arr[100];
    int size;

    // TODO: Read input into arr

    // TODO: Call SortArray

    // TODO: Output sorted array

    return 0;
}
```

---

