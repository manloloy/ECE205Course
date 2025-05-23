# The `for` Loop in C and C++

The `for` loop is a control structure that repeats a block of code a specific number of times.

---

## Syntax

```c
for (initialization; condition; update) {
    // loop body (compound statement)
}
```

- The **initialization** runs once at the beginning
- The **condition** is checked before each iteration
- The **update** runs after each iteration

---

## Semantics

1. Run the initialization statement
2. Evaluate the condition
3. If true, run the loop body
4. Run the update statement
5. Repeat from step 2

---

## Example: Basic `for` Loop in C

```c
#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {
        printf("i = %d\n", i);
    }

    return 0;
}
```

---

## Example: Basic `for` Loop in C++

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 5; i++) {
        cout << "i = " << i << endl;
    }

    return 0;
}
```

---

## Using `break` in a `for` Loop

The `break` statement exits the loop immediately.

### C Example

```c
#include <stdio.h>

int main() {
    for (int i = 0; i < 10; i++) {
        if (i == 5)
            break;

        printf("i = %d\n", i);
    }

    return 0;
}
```

### C++ Example

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 10; i++) {
        if (i == 5)
            break;

        cout << "i = " << i << endl;
    }

    return 0;
}
```

---

## Using `continue` in a `for` Loop

The `continue` statement skips the rest of the loop body and jumps to the next iteration.

### C Example

```c
#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {
        if (i == 2)
            continue;

        printf("i = %d\n", i);
    }

    return 0;
}
```

### C++ Example

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 5; i++) {
        if (i == 2)
            continue;

        cout << "i = " << i << endl;
    }

    return 0;
}
```

In both examples, the value `2` is skipped.

---

## The `do...while` Loop

The `do...while` loop guarantees that the loop body runs **at least once**.

### Syntax

```c
do {
    // loop body
} while (condition);
```

---

## Example: `do...while` in C

```c
#include <stdio.h>

int main() {
    int i = 0;

    do {
        printf("i = %d\n", i);
        i++;
    } while (i < 3);

    return 0;
}
```

---

## Example: `do...while` in C++

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 0;

    do {
        cout << "i = " << i << endl;
        i++;
    } while (i < 3);

    return 0;
}
```

The `do...while` loop is useful when you want to **run the loop body at least once**, even if the condition is false initially.
