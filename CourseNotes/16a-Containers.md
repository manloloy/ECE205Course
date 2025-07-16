# Lecture Module 10A: Introduction to C++ Containers

## Overview

This module introduces **C++ containers**, which are core components of the C++ Standard Template Library (STL). Containers are template classes that store collections of objects. Each type of container provides specific performance tradeoffs, memory layouts, and access patterns.

This lecture is intended for upper-division students at a research university. A solid understanding of classes and templates is expected.

---

## Objectives

By the end of this module, students should be able to:

- Understand what containers are and when to use them
- Distinguish between different types of containers: sequence, associative, and unordered
- Use basic container operations: insert, erase, iterate, access
- Compare efficiency and use cases of common containers
- Apply iterators and range-based loops to traverse containers

---

## Categories of STL Containers

C++ containers are categorized as follows:

| Category              | Containers                                  | Description                              |
|-----------------------|---------------------------------------------|------------------------------------------|
| Sequence containers   | `vector`, `deque`, `list`, `array`          | Maintain ordering of inserted elements   |
| Associative containers| `set`, `map`, `multiset`, `multimap`        | Store sorted elements with fast lookup   |
| Unordered containers  | `unordered_set`, `unordered_map`, etc.      | Store elements in hash table format      |

---

## 1. Sequence Containers

### Vector

Dynamic array with fast access and amortized constant-time push at the end.

```cpp
#include <vector>

std::vector<int> nums = {1, 2, 3};
nums.push_back(4);
nums[2] = 10;

for (int val : nums)
    std::cout << val << " ";
```

### Deque

Double-ended queue allowing fast insert/remove at both ends.

```cpp
#include <deque>

std::deque<int> dq = {10, 20};
dq.push_front(5);  // {5, 10, 20}
dq.push_back(25);  // {5, 10, 20, 25}
```

### List

Doubly linked list. No random access but fast insert/delete in middle.

```cpp
#include <list>

std::list<std::string> names = {"Alice", "Bob"};
names.push_front("Zara");
names.insert(std::next(names.begin()), "Charlie");
```

---

## 2. Associative Containers

### Set

Stores **unique** sorted keys.

```cpp
#include <set>

std::set<int> s = {3, 1, 4, 1};
s.insert(2);  // Result: 1, 2, 3, 4

for (int val : s)
    std::cout << val << " ";
```

### Map

Stores key-value pairs with unique keys in sorted order.

```cpp
#include <map>

std::map<std::string, int> ages;
ages["Alice"] = 25;
ages["Bob"] = 30;
std::cout << ages["Alice"];  // 25
```

---

## 3. Unordered Containers (Hash-Based)

Faster lookup on average, no order guarantees.

### Unordered Set

```cpp
#include <unordered_set>

std::unordered_set<int> us = {1, 2, 3};
us.insert(4);
```

### Unordered Map

```cpp
#include <unordered_map>

std::unordered_map<std::string, double> balance;
balance["Alice"] = 150.25;
```

---

## Iterating Over Containers

### Range-Based Loop

```cpp
std::vector<int> data = {1, 2, 3};
for (int x : data)
    std::cout << x << " ";
```

### Using Iterators

```cpp
std::list<int> lst = {4, 5, 6};
for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    std::cout << *it << " ";
```

---

## Performance and Use Case Table

| Container       | Lookup | Insert/Delete | Access | Ordered | Best Use Case                        |
|------------------|--------|---------------|--------|---------|--------------------------------------|
| `vector`         | O(1)   | End: O(1)     | O(1)   | Yes     | Arrays with frequent access          |
| `deque`          | O(1)   | Ends: O(1)    | O(1)   | Yes     | Queues needing front/back access     |
| `list`           | O(n)   | O(1)          | O(n)   | Yes     | Frequent insert/delete in middle     |
| `set`            | O(log n)| O(log n)     | O(log n)| Yes     | Unique sorted data                   |
| `map`            | O(log n)| O(log n)     | O(log n)| Yes     | Sorted key-value pairs               |
| `unordered_set`  | O(1)*  | O(1)*         | O(1)*  | No      | Fast membership testing              |
| `unordered_map`  | O(1)*  | O(1)*         | O(1)*  | No      | Fast key-value access                |

`*` Average case, assumes good hash function


---

## Practice Problems

1. Write a program using a `vector` to store a user-defined list of numbers. Output their sum.
2. Use a `set` to keep track of unique words entered by a user.
3. Create a `map<string, int>` to count occurrences of words in a sentence.
4. Compare performance of `vector` vs `list` when inserting elements at the beginning.
5. Use `unordered_map` to simulate a simple username-password lookup.

---

