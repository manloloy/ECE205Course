
## Solution (C)

```c
#include <stdio.h>
#include <stdlib.h>

// Function that returns "Heads" or "Tails" using random number
const char* CoinFlip() {
    int val = rand() % 2;
    if (val == 1) {
        return "Heads";
    }
    else {
        return "Tails";
    }
}

int main() {
    int numFlips;
    
    srand(2);  // Set seed for reproducibility
    
    // Read number of flips
    scanf("%d", &numFlips);

    // Loop and print results
    for (int i = 0; i < numFlips; ++i) {
        printf("%s\n", CoinFlip());
    }

    return 0;
}
```

---

## Solution (C++)

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

// Function that returns "Heads" or "Tails" using random number
string CoinFlip() {
    int val = rand() % 2;
    if (val == 1) {
        return "Heads";
    }
    else {
        return "Tails";
    }
}

int main() {
    int numFlips;
    
    srand(2);  // Set seed for reproducibility
    
    // Read number of flips
    cin >> numFlips;

    // Loop and print results
    for (int i = 0; i < numFlips; ++i) {
        cout << CoinFlip() << endl;
    }

    return 0;
}
```

---
