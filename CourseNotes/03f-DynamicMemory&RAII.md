# Dynamic Memory Allocation in C and C++

This module covers dynamic memory management using `malloc`, `calloc`, and `free` in C, and `new` and `delete` in C++. It also introduces the concept of **RAII** (Resource Acquisition Is Initialization) and **encapsulation** in object-oriented design.

---

## Why Use Dynamic Memory?

Static and automatic memory allocation:

- Require knowing the size of variables at **compile time**
- Are limited in size (stack size is small)
- Can cause **waste** or **overflow** if misjudged

Dynamic memory allocation solves these problems by allowing memory to be requested at **runtime**.

---

## Dynamic Memory in C

### `malloc`

```c
void* malloc(size_t size);
```

- Allocates `size` bytes
- Returns a `void*` to the memory (cast to desired type)
- Memory is **uninitialized**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    char *buffer;

    printf("How long should the string be? ");
    scanf("%d", &n);

    buffer = (char*) malloc((n + 1) * sizeof(char));
    if (buffer == NULL) {
        printf("Allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        buffer[i] = rand() % 26 + 'a';
    buffer[n] = '\0';

    printf("Random string: %s\n", buffer);
    free(buffer);

    return 0;
}
```

---

### `calloc` and `realloc`

```c
int *buffer1 = (int*) malloc(100 * sizeof(int));
int *buffer2 = (int*) calloc(100, sizeof(int));   // initializes to 0
int *buffer3 = (int*) realloc(buffer2, 500 * sizeof(int));
```

---

### `free`

Frees memory previously allocated with `malloc`, `calloc`, or `realloc`.

```c
free(buffer1);
free(buffer3);
```

---

## Common C Errors

### Memory Leaks

```c
void doSomething() {
    int *ptr = (int*) malloc(sizeof(int));
    // forgot to call free(ptr)
}  // ptr goes out of scope → memory leak
```

### Overwriting Allocations

```c
int *ptr = (int*) malloc(sizeof(int));
ptr = NULL;  // previous address is lost → memory leak
```

Always call `free(ptr)` before overwriting.

---

## Dynamic Memory in C++

### `new` and `delete`

```cpp
int *ptr = new int;        // allocate one int
*ptr = 5;

delete ptr;                // deallocate memory
ptr = nullptr;             // good practice
```

### Initializing with `new`

```cpp
int *ptr1 = new int(5);       // direct initialization
int *ptr2 = new int {6};      // uniform initialization (C++11+)
```

---

### Arrays with `new[]`

```cpp
int *arr = new int[5];       // allocate array of 5 ints
arr[0] = 10;

delete[] arr;                // use delete[] for arrays
arr = nullptr;
```

---

### Memory Leak via Re-assignment

```cpp
int *ptr = new int;
ptr = new int;       // leak: original address lost
```

Fix:

```cpp
delete ptr;
ptr = new int;
```

---

## RAII: Resource Acquisition Is Initialization

RAII is a C++ technique that ties resource ownership (memory, file handles, etc.) to **object lifetime**.

- Acquire resource in the **constructor**
- Release resource in the **destructor**

This ensures resources are cleaned up automatically.

---

### RAII Example: File Wrapper

```cpp
#include <fstream>
#include <string>

class FileReader {
    std::ifstream file;
public:
    FileReader(const std::string& filename) {
        file.open(filename);
    }

    ~FileReader() {
        file.close();  // always closes file
    }

    bool isOpen() const {
        return file.is_open();
    }
};
```

Using RAII:

```cpp
int main() {
    FileReader reader("data.txt");
    if (reader.isOpen()) {
        // process file
    }  // file is closed automatically
}
```

---

## Encapsulation and Memory Safety

Encapsulation = hiding internal state and providing a public interface.

Dynamic memory is an **internal detail** that should be managed safely. Don't expose raw pointers. Instead, manage memory inside a class.

### Example: Safe Array Class

```cpp
class IntArray {
    int* data;
    int size;
public:
    IntArray(int s) : size(s) {
        data = new int[size];
    }

    ~IntArray() {
        delete[] data;
    }

    int& operator[](int index) {
        return data[index];
    }

    int length() const {
        return size;
    }
};
```

Usage:

```cpp
int main() {
    IntArray arr(5);
    arr[0] = 42;
    // no need to call delete → RAII handles it
}
```

---

## Summary of Dynamic Allocation Tools

| Feature       | C                          | C++                       |
|---------------|-----------------------------|---------------------------|
| Allocate      | `malloc()`, `calloc()`      | `new`, `new[]`            |
| Free          | `free()`                    | `delete`, `delete[]`      |
| Safety Tool   | Manual, prone to leaks      | RAII with constructors    |
| Pointer Type  | `void*` → cast needed       | Strongly typed            |
| Encapsulation | Manual via structs          | Built-in with classes     |

---

## Final Notes

- Always `free()` or `delete` what you allocate
- Use `nullptr` in C++ (instead of `0` or `NULL`)
- RAII reduces errors and improves modularity
- Never call `delete` on non-dynamically allocated memory
- Encapsulation helps enforce ownership and safety
