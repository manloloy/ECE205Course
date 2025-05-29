
## Solutions (For Instructor Use Only)
### C Solution

```c
#include <stdio.h>

int main() {
    int inputYear;
    int isLeapYear = 0;

    scanf("%d", &inputYear);

    // Check if year is divisible by 4
    if (inputYear % 4 == 0) {
        // Century year check
        if (inputYear % 100 == 0) {
            // Must also be divisible by 400
            if (inputYear % 400 == 0) {
                isLeapYear = 1;
            } else {
                isLeapYear = 0;
            }
        } else {
            isLeapYear = 1;
        }
    } else {
        isLeapYear = 0;
    }

    // Print result
    if (isLeapYear) {
        printf("%d - leap year\n", inputYear);
    } else {
        printf("%d - not a leap year\n", inputYear);
    }

    return 0;
}
```



### C++ Solution

```cpp
#include <iostream>
using namespace std;

int main() {
    int inputYear;
    bool isLeapYear = false;

    cin >> inputYear;

    // Check if the year is divisible by 4
    if (inputYear % 4 == 0) {
        // If it is also divisible by 100, it must be divisible by 400
        if (inputYear % 100 == 0) {
            if (inputYear % 400 == 0) {
                isLeapYear = true;
            } else {
                isLeapYear = false;
            }
        } else {
            isLeapYear = true; // Not a century year, but divisible by 4
        }
    } else {
        isLeapYear = false; // Not divisible by 4 at all
    }

    // Output result
    if (isLeapYear) {
        cout << inputYear << " - leap year" << endl;
    } else {
        cout << inputYear << " - not a leap year" << endl;
    }

    return 0;
}
```
