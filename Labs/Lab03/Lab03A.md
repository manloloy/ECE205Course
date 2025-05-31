# Lab 03A: Introduction to Structs in C – Book Catalog

## Objective

Learn how to define and use `struct` types in C to organize and store related data. In this lab, you will:

- Define a `struct` for storing book information.
- Create an array of struct instances.
- Dynamically read in data from the user using loops and `scanf`.
- Display the collected data in a formatted output.

This foundational lab will prepare you for working with more advanced data abstractions, such as C++ classes in future modules.

## Background

In C, a `struct` is a user-defined type that allows grouping variables of different types under one name. It is commonly used to represent objects or records. Structs are the basis of data abstraction in C and can be expanded into full classes in C++.

Example of a struct:
```c
struct Book {
    char title[100];
    char author[100];
    char publishDate[20];
    char description[200];
    float price;
};
```

Structs can be stored in arrays, passed to functions, or used to model real-world data. To access struct members, use the dot operator:
```c
bookArray[i].price = 9.99;
```

To allocate space for a list of `n` books, define the array as:
```c
struct Book books[SIZE];
```
where `SIZE` should be a constant or user-provided input.

Note: You cannot dynamically resize standard arrays in C. If the number of books is determined by user input, make sure to declare an array large enough to hold the expected number of entries. For this lab, assume the maximum number of books is 100.
Note: dynamic allocation is possible using malloc(). Students are encouraged to explore this topic.
---

## Instructions

1. Define a `struct Book` with the following fields:
   - `title` (string of up to 100 characters)
   - `author` (string of up to 100 characters)
   - `publishDate` (string of up to 20 characters)
   - `description` (string of up to 200 characters)
   - `price` (float)

2. Prompt the user to enter the number of books to store (assume max 100).

3. For each book, ask the user to enter all the fields described above. Use `scanf` and `fgets` where appropriate.

4. After all entries are collected, print a clean summary of all book details, one by one.

---

## Sample Input

```
Enter number of books: 2

Enter details for book 1
Title: The C Programming Language
Author: Brian Kernighan and Dennis Ritchie
Publish Date: 1978
Description: Classic text on C programming
Price: 45.50

Enter details for book 2
Title: Clean Code
Author: Robert C. Martin
Publish Date: 2008
Description: Guide to writing clean software
Price: 39.99
```

## Sample Output

```
Book 1:
Title: The C Programming Language
Author: Brian Kernighan and Dennis Ritchie
Published: 1978
Description: Classic text on C programming
Price: $45.50

Book 2:
Title: Clean Code
Author: Robert C. Martin
Published: 2008
Description: Guide to writing clean software
Price: $39.99
```

---

## C Template

```c
#include <stdio.h>

#define MAX_BOOKS 100

struct Book {
    char title[100];
    char author[100];
    char publishDate[20];
    char description[200];
    float price;
};

int main() {
    struct Book books[MAX_BOOKS];
    int numBooks;

    // TODO: Prompt user for number of books

    // TODO: Loop to input book details

    // TODO: Loop to print book details

    return 0;
}
```

---

## Tips and Reminders

- Use `fgets()` instead of `scanf("%s", ...)` for string input to allow spaces.
- Always `#define` constants like `MAX_BOOKS` instead of using magic numbers.
- After using `scanf` for numeric input, call `getchar()` to consume the newline character before using `fgets()`.

This lab sets the groundwork for transitioning to **classes in C++** in the next lab (Lab04B), where we will encapsulate this structure with methods like `PrintBook()`.
