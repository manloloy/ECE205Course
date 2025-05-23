# The `while` Loop in C and C++

The `while` loop is a fundamental control structure used to repeat a block of code **while a condition remains true**.

---

## Syntax

```c
while (<condition>) <statement>
```

- `while` is a **keyword**
- `<condition>` is an expression evaluated before each iteration
- `<statement>` is the body of the loop

---

## Semantics

1. Evaluate the condition
2. If true, execute the statement
3. Repeat from step 1
4. If false, exit the loop

---

## Example: Single Statement Body (C)

```c
#include <stdio.h>

int main() {
    int count = 1;

    while (count <= 5)
        printf("Count: %d\n", count++);

    return 0;
}
```

---

## Example: Single Statement Body (C++)

```cpp
#include <iostream>
using namespace std;

int main() {
    int count = 1;

    while (count <= 5)
        cout << "Count: " << count++ << endl;

    return 0;
}
```

---

## Compound Statements

A **compound statement** (also called a block) allows you to group multiple statements together using braces `{}`.

### Syntax

```c
while (<condition>) {
    <statement>
    <statement>
    ...
}
```

---

## Example: Compound Statement (C)

```c
#include <stdio.h>

int main() {
    int i = 0;

    while (i < 3) {
        printf("i is %d\n", i);
        i++;
    }

    return 0;
}
```

---

## Example: Compound Statement (C++)

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 0;

    while (i < 3) {
        cout << "i is " << i << endl;
        i++;
    }

    return 0;
}
```

---

## `break` Statement

The `break` statement is used to **immediately exit** a loop, regardless of the condition.

### Example: `break` in C

```c
#include <stdio.h>

int main() {
    int i = 0;

    while (1) {  // infinite loop
        if (i == 3)
            break;

        printf("i = %d\n", i);
        i++;
    }

    return 0;
}
```

### Example: `break` in C++

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 0;

    while (true) {
        if (i == 3)
            break;

        cout << "i = " << i << endl;
        i++;
    }

    return 0;
}
```

---

## `continue` Statement

The `continue` statement skips the **rest of the current loop body** and proceeds to the next iteration.

### Example: `continue` in C

```c
#include <stdio.h>

int main() {
    int i = 0;

    while (i < 5) {
        i++;
        if (i == 3)
            continue;

        printf("i = %d\n", i);
    }

    return 0;
}
```

### Example: `continue` in C++

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 0;

    while (i < 5) {
        i++;
        if (i == 3)
            continue;

        cout << "i = " << i << endl;
    }

    return 0;
}
```

In both examples, the value `3` is **skipped** in the output.
