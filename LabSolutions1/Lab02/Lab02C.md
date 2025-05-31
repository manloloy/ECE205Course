## Solution (C)

```c
#include <stdio.h>

int main() {
    int numValues;
    double values[100];  // Pre-allocated array space
    int i;
    double maxValue;

    // Read number of values
    scanf("%d", &numValues);

    // Read input values into array
    for (i = 0; i < numValues; ++i) {
        scanf("%lf", &values[i]);
    }

    // Find maximum value
    maxValue = values[0];
    for (i = 1; i < numValues; ++i) {
        if (values[i] > maxValue) {
            maxValue = values[i];
        }
    }

    // Print normalized values
    for (i = 0; i < numValues; ++i) {
        printf("%.2lf ", values[i] / maxValue);
    }
    printf("\n");

    return 0;
}
```

---

## Solution (C++)

```cpp
#include <iostream>
using namespace std;

int main() {
    int numValues;
    double values[100];  // Array to hold values
    int i;
    double maxValue;

    // Read number of values
    cin >> numValues;

    // Read input values into array
    for (i = 0; i < numValues; ++i) {
        cin >> values[i];
    }

    // Find maximum value
    maxValue = values[0];
    for (i = 1; i < numValues; ++i) {
        if (values[i] > maxValue) {
            maxValue = values[i];
        }
    }

    // Print normalized values with two decimals
    cout.setf(ios::fixed);
    cout.precision(2);

    for (i = 0; i < numValues; ++i) {
        cout << values[i] / maxValue << " ";
    }
    cout << endl;

    return 0;
}
```
