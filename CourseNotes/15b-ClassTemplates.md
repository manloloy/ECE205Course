# Class Templates in C++

## Overview

This module introduces **class templates** in C++, a feature that allows you to define a class with **generic types**. Class templates support reusable, type-independent code, making them useful for building data structures (like stacks, queues, or linked lists), wrappers, or utility classes.

This lecture builds upon the concept of function templates and provides a solid foundation for understanding the C++ Standard Template Library (STL). It is intended for upper-division undergraduate students at a research university.

---

## Objectives

By the end of this module, students should be able to:

- Understand how to define and use class templates
- Declare and implement template member functions
- Use class templates with different types
- Separate class template definitions into `.hpp` and `.cpp` files (briefly discussed)
- Understand practical use cases for class templates

---

## Motivation

Suppose we want to build a **Stack** class. If we want stacks of `int`, `double`, or `std::string`, we'd need to write separate classes for each type — or, use a **class template** that works for all types.

```cpp
template <typename T>
class Stack {
private:
    std::vector<T> elements;
public:
    void push(T value) {
        elements.push_back(value);
    }

    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        }
    }

    T top() const {
        return elements.back();
    }

    bool isEmpty() const {
        return elements.empty();
    }
};
```

Now `Stack<int>`, `Stack<double>`, and `Stack<std::string>` are all valid types.

---

## Syntax: Defining a Class Template

```cpp
template <typename T>
class ClassName {
    // Members using type T
};
```

- `T` is a **template parameter** that will be replaced with a specific type when the class is instantiated.
- You may use multiple template parameters: `template <typename T1, typename T2>`

---

## Example: A Simple Box

```cpp
template <typename T>
class Box {
private:
    T value;
public:
    void setValue(T val) {
        value = val;
    }

    T getValue() const {
        return value;
    }
};
```

### Usage in `main()`

```cpp
int main() {
    Box<int> intBox;
    intBox.setValue(10);
    std::cout << intBox.getValue() << "\n";

    Box<std::string> strBox;
    strBox.setValue("Hello");
    std::cout << strBox.getValue() << "\n";

    return 0;
}
```

---

## Template Classes with Multiple Types

You can define classes with more than one type:

```cpp
template <typename K, typename V>
class Pair {
private:
    K key;
    V value;
public:
    Pair(K k, V v) : key(k), value(v) {}

    void print() const {
        std::cout << "(" << key << ", " << value << ")\n";
    }
};
```

### Usage

```cpp
Pair<std::string, int> age("Alice", 25);
age.print();  // Output: (Alice, 25)
```

---

## Member Function Definitions Outside the Class

To separate the function definitions (usually for large classes):

```cpp
template <typename T>
class MyClass {
public:
    void show();
};

template <typename T>
void MyClass<T>::show() {
    std::cout << "Template instance\n";
}
```

> **Note:** Class template definitions and implementations are usually placed in header files because the compiler needs full visibility when instantiating.

---

## Comparison: Class Templates vs Inheritance

| Feature              | Class Templates                    | Inheritance                          |
|----------------------|-------------------------------------|---------------------------------------|
| Type abstraction      | Compile-time (generic types)       | Runtime (base/derived behavior)       |
| Flexibility           | Type-agnostic reuse                | Behavior customization                |
| Overhead              | None (type substitution at compile) | Possible overhead due to polymorphism |
| Use cases             | Containers, utilities              | Frameworks, game engines, hierarchy   |

---

## Common Use Cases for Class Templates

- Generic containers (Stack, Queue, LinkedList)
- Pair and Tuple-like structures
- Data wrappers
- Type-safe caching systems

The Standard Template Library (STL) uses class templates extensively:
- `std::vector<T>`
- `std::map<K, V>`
- `std::shared_ptr<T>`

---


---

## Practice Exercises

1. Write a class template `Triple<T>` that holds 3 values of type `T`.
2. Implement a generic `Queue<T>` using `std::deque<T>`.
3. Create a class `MathPair<T>` with two values of type `T` and functions for `sum()` and `diff()`.
4. Modify the `Pair<K,V>` class to include comparison operators.
5. Write a `Box<T>` class that overloads `+` to combine two boxes.

