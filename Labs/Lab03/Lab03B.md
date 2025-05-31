# Lab 03B: Introduction to C++ Classes – Book Catalog (Class Version)

## Objective

In this lab, you will convert a previously defined `struct` from C into a full **C++ class**, encapsulating data and behavior. This exercise reinforces object-oriented programming fundamentals, including:

- Class definition and usage
- Constructors for initializing member variables
- Access specifiers: `public` vs `private`
- Creating and using an array of class instances
- Member functions for clean modular design

By the end of this lab, you should be able to define a class, properly encapsulate fields, and invoke member functions on class instances.

---

## Background: C++ Classes vs C Structs

In C++, classes extend the concept of `structs` by allowing:

- **Encapsulation**: Keeping data (`private`) and exposing behavior (`public`)
- **Constructors**: Special functions that initialize objects at creation
- **Member Functions**: Functions defined inside the class to operate on member data

### Basic Class Syntax

```cpp
class Book {
private:
    string title;
    string author;

public:
    Book(string bookTitle, string bookAuthor) {
        title = bookTitle;
        author = bookAuthor;
    }

    void DisplayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};
```

Use the constructor to initialize values when an object is created:
```cpp
Book myBook("Clean Code", "Robert Martin");
```

---

## Task Description

You will:

1. Define a `Book` class in C++ with the following **private** data members:
   - `title` (string)
   - `author` (string)
   - `publishDate` (string)
   - `description` (string)
   - `price` (float)

2. Implement a **public constructor** to initialize all fields.

3. Implement a **public member function** named `DisplayDetails()` to print book information in a formatted way.

4. In your `main()` function:
   - Ask the user how many books to enter.
   - Loop and collect input for each book.
   - Create an array of `Book` objects using the constructor.
   - Loop through the array and call `DisplayDetails()` on each object.

---

## Sample Input

```
Enter number of books: 2

Enter details for book 1
Title: The Pragmatic Programmer
Author: Andrew Hunt and David Thomas
Publish Date: 1999
Description: Software engineering principles and tips
Price: 42.99

Enter details for book 2
Title: Effective C++
Author: Scott Meyers
Publish Date: 2005
Description: Best practices in C++ programming
Price: 38.50
```

## Sample Output

```
Book 1:
Title: The Pragmatic Programmer
Author: Andrew Hunt and David Thomas
Published: 1999
Description: Software engineering principles and tips
Price: $42.99

Book 2:
Title: Effective C++
Author: Scott Meyers
Published: 2005
Description: Best practices in C++ programming
Price: $38.50
```

---

## C++ Template

```cpp
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string publishDate;
    string description;
    float price;

public:
    // TODO: Define constructor
    // TODO: Define DisplayDetails function
};

int main() {
    const int MAX_BOOKS = 100;
    Book* books[MAX_BOOKS];
    int numBooks;

    // TODO: Prompt for number of books
    // TODO: Loop to create new Book instances using input
    // TODO: Loop to display details

    return 0;
}
```

---


## Learning Tips

- Use `cin.ignore()` after numeric input to avoid newline issues before using `getline()`.
- Keep all member variables private unless explicitly needed elsewhere.
- Constructors help avoid long initialization logic in `main()`.
- If using `new` to allocate memory, remember to `delete` after use to prevent memory leaks.
- The `DisplayDetails()` function demonstrates a clean separation of responsibility within a class.

This lab transitions naturally into using classes with **methods and encapsulation**. In future labs, we’ll add additional behaviors and enhancements such as sorting books, updating prices, or comparing books
