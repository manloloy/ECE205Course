# Lab 03C: File Separation and Makefiles in C/C++

## Objective

Learn how to separate C/C++ programs into multiple files and compile them using a `Makefile`.

Students will:

- Practice modular design by splitting functionality across header files and implementation files.
- Write and use a `Makefile` to compile programs cleanly.
- Understand how to apply this structure to both functions and classes.
- Reinforce concepts learned in earlier labs (functions, structs, classes).

## Background

In industry and large academic projects, code is rarely written in a single file. Instead, it's split into:

- **Header files** (`.h` or `.hpp`): Contain declarations (function prototypes, structs, classes).
- **Source files** (`.c` or `.cpp`): Contain actual implementations (function bodies, class definitions).
- **Main program** (`main.c` or `main.cpp`): The entry point of the program.

To compile code spread across multiple files, we use **Makefiles** — simple build automation tools that track how to compile and link files.

> **Note:** This workflow also applies to **structs in C**. Students are encouraged to try struct separation on their own using this same method.

---

## Part 1: CoinFlip Function (C++)

Revisit your coin flipping function from Lab02D. In this lab, you'll split the code into:

- `coinflip.hpp`: The function prototype.
- `coinflip.cpp`: The function definition.
- `main.cpp`: The main program to test the function.
- `Makefile`: To compile and run the program.

### File: `coinflip.hpp`

```cpp
#ifndef COINFLIP_HPP
#define COINFLIP_HPP

#include <string>

std::string CoinFlip();

#endif
```

### File: `coinflip.cpp`

```cpp
#include "coinflip.hpp"
#include <cstdlib>
using namespace std;

string CoinFlip() {
    int randVal = rand() % 2;
    return (randVal == 1) ? "Heads" : "Tails";
}
```

### File: `main.cpp`

```cpp
#include <iostream>
#include <cstdlib>
#include "coinflip.hpp"
using namespace std;

int main() {
    int numFlips;
    cin >> numFlips;

    srand(2); // Seed for testing

    for (int i = 0; i < numFlips; ++i) {
        cout << CoinFlip() << endl;
    }

    return 0;
}
```

### File: `Makefile`

```make
all: coinflip

coinflip: main.o coinflip.o
	g++ -o coinflip main.o coinflip.o

main.o: main.cpp coinflip.hpp
	g++ -c main.cpp

coinflip.o: coinflip.cpp coinflip.hpp
	g++ -c coinflip.cpp

clean:
	rm -f *.o coinflip
```
### File: `Makefile` (with detailed comments)

```make
# This is the default target. When you type `make` or `make all`, this target is run.
all: coinflip

# This rule builds the final executable named 'coinflip' by linking the object files.
coinflip: main.o coinflip.o
	g++ -o coinflip main.o coinflip.o

# This rule compiles main.cpp into main.o
main.o: main.cpp coinflip.hpp
	g++ -c main.cpp

# This rule compiles coinflip.cpp into coinflip.o
coinflip.o: coinflip.cpp coinflip.hpp
	g++ -c coinflip.cpp

# This rule is run when you type `make clean`.
# It removes all object files (*.o) and the compiled executable to start fresh.
clean:
	rm -f *.o coinflip
```

### How to Use This Makefile

- `make` or `make all`  
  Runs the first target (`all`), which depends on `coinflip`. It builds everything needed for the `coinflip` program.

- `make coinflip`  
  Specifically builds the `coinflip` executable by compiling `main.cpp` and `coinflip.cpp` if they’ve changed.

- `make clean`  
  Deletes all `.o` object files and the `coinflip` executable. This is useful when:
  - You want to recompile everything from scratch
  - You're cleaning up the folder before submission or packaging

**Tip:** Always run `make clean` before making a final submission to ensure no compiled files are included.

---

## Part 2: Book Catalog Class (C++)

Revisit your Book Catalog class from Lab03B. You'll separate this code into:

- `Book.hpp`: Class declaration.
- `Book.cpp`: Class method definitions.
- `main.cpp`: The main program.
- `Makefile`: To build the full program.

### File: `Book.hpp`

```cpp
#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string publishDate;
    string description;
    double price;

public:
    Book();
    Book(string title, string author, string publishDate, string description, double price);
    void DisplayDetails() const;
};

#endif
```

### File: `Book.cpp`

```cpp
#include "Book.hpp"
#include <iostream>
using namespace std;

Book::Book() {
    title = "";
    author = "";
    publishDate = "";
    description = "";
    price = 0.0;
}

Book::Book(string t, string a, string pd, string d, double p) {
    title = t;
    author = a;
    publishDate = pd;
    description = d;
    price = p;
}

void Book::DisplayDetails() const {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Published: " << publishDate << endl;
    cout << "Description: " << description << endl;
    cout << "Price: $" << price << endl;
    cout << "--------------------------" << endl;
}
```

### File: `main.cpp`

```cpp
#include "Book.hpp"
#include <iostream>
using namespace std;

int main() {
    int numBooks;

    cout << "Enter number of books: ";
    cin >> numBooks;

    Book books[numBooks];

    for (int i = 0; i < numBooks; ++i) {
        string title, author, date, desc;
        double price;

        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter author: ";
        getline(cin, author);

        cout << "Enter publish date: ";
        getline(cin, date);

        cout << "Enter description: ";
        getline(cin, desc);

        cout << "Enter price: ";
        cin >> price;

        books[i] = Book(title, author, date, desc, price);
    }

    cout << "\nBook Catalog:\n";
    for (int i = 0; i < numBooks; ++i) {
        books[i].DisplayDetails();
    }

    return 0;
}
```

### File: `Makefile`

```make
all: bookcatalog

bookcatalog: main.o Book.o
	g++ -o bookcatalog main.o Book.o

main.o: main.cpp Book.hpp
	g++ -c main.cpp

Book.o: Book.cpp Book.hpp
	g++ -c Book.cpp

clean:
	rm -f *.o bookcatalog
```

---

## Learning Notes

- Use `#include` guards (`#ifndef`, `#define`, `#endif`) in headers to prevent duplicate definitions.
- You must compile source files (`.cpp`) into `.o` object files before linking.
- Use `make` to simplify repeated compilation.
- File separation makes your code easier to maintain, debug, and reuse.

---

## Notes

Each part is self-contained with its own Makefile. To test:

1. Copy all files for one part into a directory.
2. Run:
   ```bash
   make
   ./coinflip     # or ./bookcatalog
   ```

Makefiles will automatically detect changes and recompile the necessary files.

