# Lecture 09B: File I/O in C++

## Overview

In this lecture, we introduce **File Input and Output (File I/O)** in C++. File I/O allows a program to read data from and write data to files stored on disk. This is a foundational skill for working with configuration files, logs, save/load functionality in games, and more.

We’ll cover:
- Basic file reading and writing using `ifstream` and `ofstream`
- Common patterns and best practices
- How to read and write structured text files (e.g., `.txt`)
- Proper error checking and closing of file streams

This knowledge is critical for later using JSON-based scriptable objects in capstone projects like Lab09A.

---

## 1. Including the Header

To use file I/O in C++, include the `<fstream>` library:

```cpp
#include <fstream>
```

---

## 2. Reading From a File (`ifstream`)

### Example: Reading a list of integers from `data.txt`

**data.txt**
```
42
56
99
```

**main.cpp**
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("data.txt");  // Open file for reading
    int num;

    if (!inputFile) {
        cerr << "Error opening file.\n";
        return 1;
    }

    while (inputFile >> num) {
        cout << "Read number: " << num << endl;
    }

    inputFile.close();  // Always close files when done
    return 0;
}
```

### Output
```
Read number: 42
Read number: 56
Read number: 99
```

---

## 3. Writing to a File (`ofstream`)

### Example: Writing squares of numbers to a file

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outputFile("squares.txt");  // Open file for writing

    if (!outputFile) {
        cerr << "Error opening output file.\n";
        return 1;
    }

    for (int i = 1; i <= 5; ++i) {
        outputFile << "Square of " << i << " is " << i * i << endl;
    }

    outputFile.close();
    return 0;
}
```

**squares.txt** (output)
```
Square of 1 is 1
Square of 2 is 4
Square of 3 is 9
Square of 4 is 16
Square of 5 is 25
```

---

## 4. Appending to a File

To append data without overwriting the file, open with `ios::app` mode:

```cpp
ofstream logFile("log.txt", ios::app);
logFile << "New log entry.\n";
```

---

## 5. Error Checking

### Check if a file opened correctly:
```cpp
ifstream file("data.txt");
if (!file.is_open()) {
    cerr << "File could not be opened!\n";
}
```

### Check if reading/writing succeeded:
```cpp
if (inputFile.fail()) {
    cerr << "Failed to read from file.\n";
}
```

---

## 6. Common Patterns

### Reading a line of text:
```cpp
string line;
getline(inputFile, line);
```

### Reading tokens one by one:
```cpp
string word;
while (inputFile >> word) {
    cout << word << endl;
}
```

### Writing formatted data:
```cpp
outputFile << fixed << setprecision(2) << someFloatValue;
```

---

## 7. Practice Exercise

1. Create a file called `names.txt` with a list of names.
2. Write a C++ program that:
   - Reads each name and prints it to the screen
   - Adds a line at the end: `"File successfully read."`

---

## Notes

| Operation           | Class      | Common Methods            |
|---------------------|------------|----------------------------|
| Read from file      | `ifstream` | `>>`, `getline`, `.is_open()` |
| Write to file       | `ofstream` | `<<`, `.is_open()`         |
| File open modes     | `ios::in`, `ios::out`, `ios::app` |                        |

---




