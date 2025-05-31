
## Solutions (C and C++) - Instructor Use Only

### C Solution

```c
#include <stdio.h>

// Function to sort array in descending order
void SortArray(int arr[], int size) {
    int i, j, temp, maxIndex;

    for (i = 0; i < size; ++i) {
        maxIndex = i;
        for (j = i + 1; j < size; ++j) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        // Swap
        temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

int main() {
    int arr[100];
    int size, i;

    // Read number of values
    scanf("%d", &size);

    // Read values into array
    for (i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    // Sort array
    SortArray(arr, size);

    // Output sorted values with trailing comma
    for (i = 0; i < size; ++i) {
        printf("%d,", arr[i]);
    }
    printf("\n");

    return 0;
}
```

---

### C++ Solution

```cpp
#include <iostream>
using namespace std;

// Function to sort array in descending order
void SortArray(int arr[], int size) {
    int i, j, temp, maxIndex;

    for (i = 0; i < size; ++i) {
        maxIndex = i;
        for (j = i + 1; j < size; ++j) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        // Swap
        temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

int main() {
    int arr[100];
    int size;

    // Read number of values
    cin >> size;

    // Read values into array
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Sort array
    SortArray(arr, size);

    // Output sorted values with trailing comma
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ",";
    }
    cout << endl;

    return 0;
}
```


