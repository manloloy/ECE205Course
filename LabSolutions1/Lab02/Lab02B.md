# Lab 02B: Pointer Addressing and Dereferencing

## Objective

In this lab, you will gain experience using pointers in both C and C++. You will write a program to swap two integers by manipulating their memory using pointers. You will also print their memory addresses to reinforce understanding of the concepts.

---

## Background

Pointers are variables that store the memory address of another variable. Two important pointer operations:

- `&` (Address-of operator): Gets the address of a variable.
- `*` (Dereference operator): Accesses the value stored at a given memory address.

Example:

```c
int x = 10;
int* ptr = &x;     // ptr holds the address of x
printf("%d", *ptr); // prints 10
```

---

## Task

1. Initialize two integer variables: `a = 10`, `b = 25`.
2. Create two pointers, `ptrA` and `ptrB`, that point to `a` and `b`.
3. Print the values and addresses before the swap.
4. Swap the values using only pointer operations.
5. Print the values and addresses after the swap.

---

## Sample Output

```
Before swap:
a = 10, b = 25
Address of a: 0x7ffee06c3a8c
Address of b: 0x7ffee06c3a88

After swap:
a = 25, b = 10
Address of a: 0x7ffee06c3a8c
Address of b: 0x7ffee06c3a88
```

---

## C Template

```c
#include <stdio.h>

int main() {
    int a = 10;
    int b = 25;

    // Create pointers to a and b
    int* ptrA = &a;
    int* ptrB = &b;

    // Print initial values and addresses
    printf("Before swap:\n");
    printf("a = %d, b = %d\n", a, b);
    printf("Address of a: %p\n", (void*)ptrA);
    printf("Address of b: %p\n", (void*)ptrB);

    // TODO: Swap values using only pointers

    printf("\nAfter swap:\n");
    printf("a = %d, b = %d\n", a, b);
    printf("Address of a: %p\n", (void*)ptrA);
    printf("Address of b: %p\n", (void*)ptrB);

    return 0;
}
```

---

## C++ Template

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 25;

    // Create pointers to a and b
    int* ptrA = &a;
    int* ptrB = &b;

    // Print initial values and addresses
    cout << "Before swap:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "Address of a: " << ptrA << endl;
    cout << "Address of b: " << ptrB << endl;

    // TODO: Swap values using only pointers

    cout << "\nAfter swap:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "Address of a: " << ptrA << endl;
    cout << "Address of b: " << ptrB << endl;

    return 0;
}
```

---


