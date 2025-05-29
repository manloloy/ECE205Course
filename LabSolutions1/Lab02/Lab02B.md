## Solution - C

```c
#include <stdio.h>

int main() {
    int a = 10;
    int b = 25;

    // Create pointers
    int* ptrA = &a;
    int* ptrB = &b;

    // Print before swap
    printf("Before swap:\n");
    printf("a = %d, b = %d\n", a, b);
    printf("Address of a: %p\n", (void*)ptrA);
    printf("Address of b: %p\n", (void*)ptrB);

    // Swap values using pointers
    int temp = *ptrA;  // Store value at ptrA
    *ptrA = *ptrB;     // Assign value at ptrB to location at ptrA
    *ptrB = temp;      // Assign stored value to location at ptrB

    // Print after swap
    printf("\nAfter swap:\n");
    printf("a = %d, b = %d\n", a, b);
    printf("Address of a: %p\n", (void*)ptrA);
    printf("Address of b: %p\n", (void*)ptrB);

    return 0;
}
```

---

## Solution - C++

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 25;

    // Create pointers
    int* ptrA = &a;
    int* ptrB = &b;

    // Print before swap
    cout << "Before swap:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "Address of a: " << ptrA << endl;
    cout << "Address of b: " << ptrB << endl;

    // Swap values using pointers
    int temp = *ptrA;   // Store value at ptrA
    *ptrA = *ptrB;      // Assign value at ptrB to ptrA
    *ptrB = temp;       // Assign stored value to ptrB

    // Print after swap
    cout << "\nAfter swap:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "Address of a: " << ptrA << endl;
    cout << "Address of b: " << ptrB << endl;

    return 0;
}
```


