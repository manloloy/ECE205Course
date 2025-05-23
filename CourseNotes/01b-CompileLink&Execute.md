# Compile, Link, and Execute in C/C++

In this section, we learn what happens behind the scenes when running a C or C++ program.

---

## Why Compilation?

You cannot run a `.c` or `.cpp` file directly.

The source file must first be translated into binary code that the computer’s CPU can understand. This is done by a compiler, which generates an object file (usually ending in `.o`).

---

## Why Linking?

After compiling, your program may still not be complete.

Many programming languages rely on library routines — built-in functions provided by the compiler. These functions handle common tasks like input/output, math, memory, etc.

For example:
- The C function `printf()` comes from the `stdio.h` library.
- The C++ stream `cout` comes from the `iostream` library.

These functions live in compiled libraries, and you need a linker to combine your code with them. The result is an executable file (like `a.out`).

---

## Summary: Build Process

```
Text Editor → Source File (.c/.cpp)
         ↓
      Compiler → Object File (.o)
         ↓
       Linker → Executable File (e.g., a.out)
         ↓
     Run with: ./a.out
```

---

## Running a C Program

Create a file called `hello.c`:

```c
#include <stdio.h>

int main() {
    printf("Hello from C!\n");
    return 0;
}
```

### Compile and Run:

```bash
gcc hello.c       # produces a.out
./a.out           # runs the program
```

You can also specify the output file:

```bash
gcc hello.c -o my_program
./my_program
```

---

## Running a C++ Program

Create a file called `hello.cpp`:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello from C++!" << std::endl;
    return 0;
}
```

### Compile and Run:

```bash
g++ hello.cpp       # produces a.out
./a.out             # runs the program
```

Or specify the output:

```bash
g++ hello.cpp -o my_cpp_program
./my_cpp_program
```

---

## Multi-File Compilation Example

### C:

```bash
gcc main.c helper.c -o my_c_program
```

### C++:

```bash
g++ main.cpp helper.cpp -o my_cpp_program
```

Use `.h` or `.hpp` files for headers, e.g.:

```cpp
#include "functions.hpp"
```

---

## Recap

- Use `gcc` for C programs and `g++` for C++ programs.
- Header files: `.h` (C), `.hpp` (C++)
- Executables are run with `./filename`
- If you're unsure whether you're using correct syntax, you can look up a sample online or compare with working examples.

