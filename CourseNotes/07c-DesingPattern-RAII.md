# C++ Module: RAII (Resource Acquisition Is Initialization)

## Introduction

**RAII** stands for **Resource Acquisition Is Initialization**. It's a fundamental design pattern in C++ that ties resource lifetime to object lifetime. When an object is created, it acquires a resource (e.g., memory, file handle), and when it goes out of scope, its destructor automatically releases the resource.

RAII helps:

- Avoid memory leaks
- Prevent resource mismanagement
- Make code exception-safe
- Eliminate the need for manual cleanup

RAII applies to all types of resources: memory, file handles, sockets, locks, etc.

---

## Section 1: Basic RAII Example

Let's manage a raw resource like `int*` using a class.

### File: `basic_raii.cpp`

```cpp
#include <iostream>

class IntWrapper {
public:
    IntWrapper(int size) {
        data = new int[size];
        this->size = size;
        std::cout << "Allocated " << size << " integers\n";
    }

    ~IntWrapper() {
        delete[] data;
        std::cout << "Deallocated integers\n";
    }

private:
    int* data;
    int size;
};

void example() {
    IntWrapper w(10);
    std::cout << "Using the wrapped integers...\n";
}

int main() {
    example();
    std::cout << "Wrapper has gone out of scope\n";
    return 0;
}
```

### Output

```
Allocated 10 integers
Using the wrapped integers...
Deallocated integers
Wrapper has gone out of scope
```

As soon as `w` goes out of scope, its destructor is called.

---

## Section 2: RAII for FILE* with stdio.h

### Problem

If you forget to call `fclose()` after opening a `FILE*`, you risk memory leaks or corruption.

### Solution

Create a class that closes the file automatically in the destructor.

### File: `file_raii.cpp`

```cpp
#include <cstdio>
#include <iostream>

class FileRAII {
public:
    FileRAII(const char* filename, const char* mode) {
        file = std::fopen(filename, mode);
        if (!file) {
            throw std::runtime_error("Failed to open file");
        }
    }

    ~FileRAII() {
        if (file) {
            std::fclose(file);
            std::cout << "File closed\n";
        }
    }

    FILE* get() const {
        return file;
    }

private:
    FILE* file;
};

int main() {
    try {
        FileRAII f("sample.txt", "w");
        std::fprintf(f.get(), "Hello from RAII FILE*\n");
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << "FileRAII object went out of scope\n";
    return 0;
}
```

This ensures that even if an exception occurs, `fclose` is called.

---

## Section 3: STL Is RAII by Design

The Standard Template Library (STL) uses RAII internally.

### Example

```cpp
#include <vector>
#include <iostream>

void stlExample() {
    std::vector<int> v(1000); // Automatically allocated
    v[0] = 42;
    std::cout << "First element: " << v[0] << "\n";
}

int main() {
    stlExample();
    std::cout << "Vector deallocated automatically\n";
    return 0;
}
```

When `v` goes out of scope, its memory is automatically deallocated.

---

## Section 4: Optional SFML Example (RAII in Practice)

If you're using SFML, you are already using RAII. Every SFML class manages its own resources.

### File: `sfml_raii.cpp`

```cpp
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "RAII with SFML");

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Cyan);
    circle.setPosition(150.f, 150.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    // No need to call any delete or cleanup.
    return 0;
}
```

**Explanation:**  
- `sf::RenderWindow` and `sf::CircleShape` manage their own resources.
- When `main()` ends, all SFML objects clean up automatically.

---

## Section 5: NOTES

- RAII binds a resource to an object’s lifetime.
- When the object goes out of scope, its destructor cleans up the resource.
- This is safer and cleaner than manual `new`/`delete` or `fopen`/`fclose`.
- STL and SFML classes already use RAII.
- You can write your own RAII classes to manage any resource.

---

## Example using lock_guard

std::mutex and std::lock_guard (C++11 and newer)
std::mutex
A mutex provides two main functions:

- lock() — blocks the thread until it can acquire the lock.

- unlock() — releases the lock so other threads can acquire it.

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_message() {
    mtx.lock();                  // acquire the lock
    std::cout << "Hello safely!\n";
    mtx.unlock();                // release the lock
}
```
**Problem:** If a function returns early or throws an exception, unlock() might not get called — causing a deadlock.

**```std::lock_guard```**
This is where std::lock_guard helps — it's a RAII wrapper for std::mutex.

When you create a ```std::lock_guard```, it automatically locks the mutex.
When the lock_guard goes out of scope (function ends, early return, or exception), it automatically unlocks the mutex.

Example:

```cpp

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void thread_safe_print() {
    std::lock_guard<std::mutex> lock(mtx);  // lock acquired
    std::cout << "Thread-safe message\n";   // shared resource
}                                           // lock released here
```
---
