---

## 🔒 Solutions (for TA/Instructor Use Only)

---

###  C Solution

```c
#include <stdio.h>

int main() {
    int quarters, dimes, nickels, pennies;
    double dollars;

    scanf("%d %d %d %d", &quarters, &dimes, &nickels, &pennies);

    dollars = (quarters * 25 + dimes * 10 + nickels * 5 + pennies) / 100.0;

    printf("Amount: $%.2f\n", dollars);

    return 0;
}
```

---

###  C++ Solution

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int quarters, dimes, nickels, pennies;
    double dollars;

    cin >> quarters >> dimes >> nickels >> pennies;

    dollars = (quarters * 25 + dimes * 10 + nickels * 5 + pennies) / 100.0;

    cout << fixed << setprecision(2);
    cout << "Amount: $" << dollars << endl;

    return 0;
}
```

