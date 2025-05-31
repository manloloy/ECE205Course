## Solution (Instructor Use Only – C++)

```cpp
#include <iostream>
#include <string>
using namespace std;

// Define the Book class
class Book {
private:
    string title;
    string author;
    string publishDate;
    string description;
    float price;

public:
    // Constructor initializes all fields
    Book(string t, string a, string pd, string d, float p) {
        title = t;
        author = a;
        publishDate = pd;
        description = d;
        price = p;
    }

    // Display function prints all book details
    void DisplayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Published: " << publishDate << endl;
        cout << "Description: " << description << endl;
        cout << "Price: $" << price << endl;
    }
};

int main() {
    const int MAX_BOOKS = 100;
    Book* books[MAX_BOOKS];
    int numBooks;

    cout << "Enter number of books: ";
    cin >> numBooks;
    cin.ignore(); // Clear newline

    for (int i = 0; i < numBooks; ++i) {
        string title, author, publishDate, description;
        float price;

        cout << "\nEnter details for book " << (i + 1) << endl;

        cout << "Title: ";
        getline(cin, title);

        cout << "Author: ";
        getline(cin, author);

        cout << "Publish Date: ";
        getline(cin, publishDate);

        cout << "Description: ";
        getline(cin, description);

        cout << "Price: ";
        cin >> price;
        cin.ignore(); // Clear newline

        // Create a new Book object using the constructor
        books[i] = new Book(title, author, publishDate, description, price);
    }

    cout << endl;
    for (int i = 0; i < numBooks; ++i) {
        cout << "Book " << (i + 1) << ":" << endl;
        books[i]->DisplayDetails();
        cout << endl;
        delete books[i]; // Clean up dynamic memory
    }

    return 0;
}
```
