## Solutions (For Instructor Use Only)

### C Solution

```c
#include <stdio.h>

int main() {
    int userNum;

    // Read input from user
    scanf("%d", &userNum);

    // Loop until the number becomes 0
    while (userNum > 0) {
        // Print the remainder (either 0 or 1)
        printf("%d", userNum % 2);

        // Update the number
        userNum = userNum / 2;
    }

    // Print newline at end
    printf("\n");

    return 0;
}
```

---

### C++ Solution

```cpp
#include <iostream>
using namespace std;

int main() {
    int userNum;

    // Read input from user
    cin >> userNum;

    // Loop until the number becomes 0
    while (userNum > 0) {
        // Print the remainder (either 0 or 1)
        cout << (userNum % 2);

        // Update the number
        userNum = userNum / 2;
    }

    // Print newline at end
    cout << endl;

    return 0;
}
```
