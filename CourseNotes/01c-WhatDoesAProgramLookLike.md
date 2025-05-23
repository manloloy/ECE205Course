# What Does a C Program Look Like?

Every function in C (and C++) has two parts:

1. **The Header** – defines the function's name, arguments, and return type.
2. **The Body** – contains the declarations and statements that make up the function.

---

## Function Header

The function header introduces a function and includes:

- **Return type** (e.g., `int`, `void`)
- **Function name** (e.g., `main`, `add`)
- **Parameter list** (inside parentheses)

Example:

```c
int main()    // return type: int, function name: main, no parameters
```

---

## Function Body

Enclosed in curly braces `{}` and contains:

- **Declarations**: where you define variables
- **Statements**: actions your program performs

Example:

```c
int main() {
    int x = 5;               // declaration + initialization
    printf("x = %d\n", x);   // statement (function call)
    return 0;
}
```

---

## Basic Syntax Rules (C and C++)

- Every statement must end with a semicolon `;`
- Every open parenthesis `(` must be closed with a `)`
- Every open curly brace `{` must be closed with a `}`
- Every quote `"` must be matched
- Every square bracket `[` must be closed
- Code runs **top to bottom**, one line at a time
- The program **starts in `main()`**
- You can **call other functions**, like `printf`
- Whitespace doesn't affect execution, but helps humans read code

---

## Output and Libraries

- The function `printf()` outputs text
- `\n` creates a newline (called an **escape character**)
- You must include the standard input/output library to use `printf`:

```c
#include <stdio.h>  // C standard input/output
```

- In C++, use:

```cpp
#include <iostream>  // C++ input/output
```

---

## Comments

Use comments to explain your code.

- **Single-line comments** start with `//`:

```c
// This is a comment
```

- **Multi-line comments** are wrapped in `/* ... */`:

```c
/* This is a multi-line comment
   that continues on the next line */
```

You can also use single-line comments after code:

```c
int x = 5; // declare x
```

---

## Full Example in C

```c
/* File: example.c
   By: Christopher Manloloyo
   login: manaloloy
   Date: 20 August 2017
*/

#include <stdio.h> // include header files

int main()  // function header
{
    // This is the function body
    printf("Hello World\n");
    printf("Bye World\n");
    return 0;
}
```

---

## Equivalent in C++

Most of the syntax is the same, except:

- Use `#include <iostream>` instead of `stdio.h`
- Use `std::cout` instead of `printf`
- You can omit `std::` by writing `using namespace std;` (we’ll cover namespaces later)

```cpp
#include <iostream>

int main() {
    std::cout << "Hello World" << std::endl;
    std::cout << "Bye World" << std::endl;
    return 0;
}
```

Or, with namespace:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    cout << "Bye World" << endl;
    return 0;
}
```
