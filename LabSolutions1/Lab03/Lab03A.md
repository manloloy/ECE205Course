## Solution (Instructor Use Only – C)

```c
#include <stdio.h>

#define MAX_BOOKS 100

// Define the Book structure
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
    int i;

    // Prompt user for number of books
    printf("Enter number of books: ");
    scanf("%d", &numBooks);
    getchar(); // Clear newline after number input

    // Loop to collect book information
    for (i = 0; i < numBooks; ++i) {
        printf("\nEnter details for book %d\n", i + 1);

        printf("Title: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);

        printf("Author: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);

        printf("Publish Date: ");
        fgets(books[i].publishDate, sizeof(books[i].publishDate), stdin);

        printf("Description: ");
        fgets(books[i].description, sizeof(books[i].description), stdin);

        printf("Price: ");
        scanf("%f", &books[i].price);
        getchar(); // Clear newline after price
    }

    // Output book summary
    printf("\n");
    for (i = 0; i < numBooks; ++i) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s", books[i].title);
        printf("Author: %s", books[i].author);
        printf("Published: %s", books[i].publishDate);
        printf("Description: %s", books[i].description);
        printf("Price: $%.2f\n", books[i].price);
        printf("\n");
    }

    return 0;
}
```
