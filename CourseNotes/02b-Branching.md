# Branching in C and C++

This module covers conditional branching using `if/else` and `switch` statements. We'll also introduce **boolean expressions**, which form the basis of these decisions.

---

## Boolean Expressions

### What is a Boolean Expression?

A **boolean expression** is a logical condition that evaluates to either **true** or **false**. It is used to make decisions in a program.

### Why Are Boolean Expressions Important?

They allow your program to choose between different paths based on input, state, or computation.

### How Are Boolean Expressions Used?

They are used in control structures like:

```c
if (condition) { ... }
```

or

```c
while (condition) { ... }
```

### Boolean Types in C vs. C++

| Language | Type Used | Notes |
|----------|-----------|-------|
| C        | No `bool` type by default | Use `int` (0 is false, non-zero is true) |
| C++      | Built-in `bool` type | Values are `true` and `false` |

If you're using **C99 or later**, you can include `stdbool.h` in C:

```c
#include <stdbool.h>
bool flag = true;
```

---

## The `if/else` Statement

### What Is It?

An `if/else` is a **conditional control statement**. It executes one block of code if a condition is **true**, and another if it's **false**.

### Syntax

```c
if (condition) {
    // code if condition is true
} else {
    // code if condition is false
}
```

### Example in C

```c
#include <stdio.h>

int main() {
    int number;

    printf("Enter a magical number: ");
    scanf("%d", &number);

    if (number >= 100) {
        printf("Your number is very magical!\n");
    } else {
        printf("Your number needs more magic :(\n");
    }

    return 0;
}
```

---

### Example in C++

```cpp
#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "Enter a magical number: ";
    cin >> number;

    if (number >= 100) {
        cout << "Your number is very magical!" << endl;
    } else {
        cout << "Your number needs more magic :(" << endl;
    }

    return 0;
}
```

---

### Key Points

- A condition must evaluate to **true (non-zero)** or **false (zero)**.
- Only one block runs depending on the result.
- You can nest `if/else` to check more than two options.

---

## The `switch` Statement

The `switch` statement is used to select one block of code to run from **many** options.

### Syntax

```c
switch (expression) {
    case constant1:
        // code
        break;
    case constant2:
        // code
        break;
    default:
        // code if no match
}
```

### C Example

```c
#include <stdio.h>

int main() {
    int grade;

    printf("Enter your grade (1–3): ");
    scanf("%d", &grade);

    switch (grade) {
        case 1:
            printf("Freshman\n");
            break;
        case 2:
            printf("Sophomore\n");
            break;
        case 3:
            printf("Junior\n");
            break;
        default:
            printf("Invalid grade\n");
    }

    return 0;
}
```

---

### C++ Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int option;

    cout << "Choose an option (1–3): ";
    cin >> option;

    switch (option) {
        case 1:
            cout << "Option 1 selected." << endl;
            break;
        case 2:
            cout << "Option 2 selected." << endl;
            break;
        case 3:
            cout << "Option 3 selected." << endl;
            break;
        default:
            cout << "Invalid option." << endl;
    }

    return 0;
}
```

---

### Notes on `switch`

- Only works with **integer-type expressions**
- Each `case` must use a **constant**
- `break` prevents **fall-through** to the next case

