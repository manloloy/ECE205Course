
## Solutions

---

### C++ Solution

```cpp
#include <iostream>
#include <cctype>
using namespace std;

int main() {
   unsigned int i;
   string userInput;
   string userInputNoSymbols;
   
   // Read entire line including spaces and punctuation
   getline(cin, userInput);
   
   // Loop through each character
   for (i = 0; i < userInput.length(); ++i) {
      // Only keep alphabetic characters
      if (isalpha(userInput.at(i))) {
         userInputNoSymbols += userInput.at(i);
      }
   }
   
   // Print filtered result
   cout << userInputNoSymbols << endl;

   return 0;
}
```

---

### C Solution

```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char userInput[200];
    int i;

    // Read a line of input from the user
    fgets(userInput, sizeof(userInput), stdin);

    // Loop through each character in the input
    for (i = 0; userInput[i] != '\0'; ++i) {
        // Check if the character is alphabetic
        if (isalpha(userInput[i])) {
            // Print the alphabetic character
            putchar(userInput[i]);
        }
    }

    // Print a newline after output
    putchar('\n');

    return 0;
}
```

---
