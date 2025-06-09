# Constructor Overloading in C++

## Objective
This module introduces students to **constructor overloading** in C++. Students will learn how to define multiple constructors in a class with different parameter types or counts and understand how constructors with default arguments work. This topic builds directly on the concept of function overloading and gives more flexibility when instantiating objects.

---

## Background

A constructor is a special function in a class that is automatically called when an object is created. Like other functions in C++, constructors can be **overloaded**, meaning a class can have more than one constructor as long as their parameter lists differ.

Constructor overloading enables the creation of objects with different levels of detail and initial values.

---

## Syntax and Rules

- Constructors must have the same name as the class.
- A class may have multiple constructors if each has a distinct parameter list.
- A constructor with no arguments is called the **default constructor**.
- Like other functions, constructors can use **default parameter values**, but care must be taken to avoid ambiguity.

---

## C++ Example: Constructor Overloading

```cpp
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    // Default constructor
    Book() {
        title = "Unknown";
        author = "Unknown";
        year = 0;
    }

    // Constructor with title only
    Book(string t) {
        title = t;
        author = "Unknown";
        year = 0;
    }

    // Constructor with title and author
    Book(string t, string a) {
        title = t;
        author = a;
        year = 0;
    }

    // Constructor with all parameters
    Book(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }

    void PrintInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << endl;
    }
};

int main() {
    Book book1;
    Book book2("The Odyssey");
    Book book3("The Iliad", "Homer");
    Book book4("1984", "George Orwell", 1949);

    book1.PrintInfo();
    book2.PrintInfo();
    book3.PrintInfo();
    book4.PrintInfo();

    return 0;
}
