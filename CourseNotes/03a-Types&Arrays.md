# Basic Types and Arrays in C and C++

This module introduces fundamental data types in C/C++ and the basics of arrays, including how to declare, use, and pass them to functions.

---

## Basic Data Types

C and C++ are **statically typed languages**. You must declare the type of each variable when it is created.

### Common Primitive Types

| Type       | Description                      | Example Value     |
|------------|----------------------------------|-------------------|
| `int`      | Integer numbers                  | `42`, `-5`, `0`   |
| `float`    | Single-precision decimal         | `3.14`, `0.5`     |
| `double`   | Double-precision decimal         | `2.71828`         |
| `char`     | Single character (1 byte)        | `'A'`, `'z'`      |
| `bool`     | Boolean (`true`/`false`)         | `true`, `false`   |
| `void`     | No value / no return type        | used for functions |

> Note: `bool` is only available in C++ or C99 with `#include <stdbool.h>`

---

## What is an Array?

An **array** is a fixed-size collection of elements of the **same type**, stored in **contiguous memory**.

You access elements using an **index**, starting at `0`.

---

## Declaring a 1D Array

```c
int data[100];       // 100 integers
char str[81];        // 80 characters + null terminator for a string
```

### Accessing Elements

```c
data[35] = 30;
putchar(str[3]);
```

---

## Array Indexing Rules

- Indexes start at **0**
- Valid indexes go from `0` to `size - 1`

---

## Initializing Arrays

### Manual Initialization

```c
char header[3];
header[0] = '0';
header[1] = '1';
header[2] = '2';
```

### Shorthand Initialization

```c
char header[3] = { '0', '1', '2' };
int numbers[] = { 10, 20, 30 };  // size is inferred
```

---

## Passing Arrays to Functions

Arrays are passed by **reference** (as a pointer to the first element).

### Function Declaration

```c
void display(int arr[]);         // preferred for readability
void display(int *arr);          // equivalent
```

Both declarations are identical to the compiler.

> Note: The function **does not know the array’s size**, so pass it separately.

```c
void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
```

---

## 2D Arrays

A **2-dimensional array** is like a matrix with rows and columns.

### Declaration

```c
int matrix[3][4];  // 3 rows, 4 columns
```

### Accessing Elements

```c
matrix[1][2] = 42;
x = matrix[row][col];
```

---

## Initializing 2D Arrays

```c
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

---

## Loop Initialization of 2D Arrays

```c
for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        matrix[i][j] = 0;
```

---

## Passing 2D Arrays to Functions

You can pass a 2D array using its name:

```c
process(matrix);
```

### Function Declaration

You **must specify the number of columns**, so the compiler can compute memory offsets:

```c
void process(int matrix[][4])  // OK
```

> You do **not** need to specify the number of rows.

---

## Behind the Scenes

Arrays are stored in **row-major order**:

```c
int a[3][4];
```

This means:

- `a[0]` is the first row (a 1D array)
- `a[1]` is the second row
- `a[i][j]` is the value at row `i`, column `j`

Internally:

```c
a       ≡ &a[0][0]
a[i]    ≡ &a[i][0]
```

So all array elements are stored in a linear memory block, and 2D indexing is translated by the compiler into pointer arithmetic.

---
