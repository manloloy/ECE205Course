# Vectors and Iterators in C++

## What is a `vector`?

A `vector` in C++ is a dynamic array — a class template from the STL that **grows or shrinks** at runtime.

It provides:
- Flexible sizing
- Type safety via templates
- Built-in operations (e.g., `push_back`, `size`, `swap`)
- Iterator support

```cpp
#include <vector>
using namespace std;

vector<int> vectorOfInts;
vector<double> vectorOfDoubles;
vector<string> vectorOfStrings;
```

---

## Template Declaration (Simplified)

```cpp
template <typename T>
class vector {
public:
    // useful member functions
private:
    T* myArray;  // dynamically allocated array
};
```

---

## Core Vector Operations (assuming `vector<T> v`)

| Expression         | Description                                          |
|--------------------|------------------------------------------------------|
| `v.capacity()`     | Number of elements allocated (not necessarily used) |
| `v.size()`         | Number of elements currently in use                 |
| `v.max_size()`     | Max number of elements ever allowed by system       |
| `v.empty()`        | Returns true if `v.size() == 0`                      |
| `v.reserve(n)`     | Ensures capacity is at least `n` (does not change size) |
| `v.push_back(x)`   | Adds `x` to end                                      |
| `v.pop_back()`     | Removes last element                                 |
| `v.front()`        | Reference to first element                           |
| `v.back()`         | Reference to last element                            |
| `v[i]`             | Unchecked access to element at index `i`            |
| `v.at(i)`          | Checked access; throws if out-of-range              |
| `v1 = v2`          | Copy assignment                                      |
| `v1.swap(v2)`      | Exchanges contents                                   |
| `v1 == v2`         | True if contents equal                              |
| `v1 < v2`          | Lexicographical comparison                          |

---

## Example: Size and Capacity

```cpp
vector<double> v(3);         // initializes with 3 default values (0.0)
cout << v.capacity() << ' ' << v.size();  // Output: 3 3
```

```cpp
vector<double> v(3, 4.0);    // initializes with 3 values of 4.0
cout << v.capacity() << ' ' << v.size() << endl;

v.reserve(6);
cout << v.capacity() << ' ' << v.size();  // Output: 6 3
```

---

## Example: Push and Pop

```cpp
vector<double> v;
v.push_back(1.1);
v.push_back(2.2);
v.push_back(3.3);

cout << v.front() << ' ' << v.back() << endl;

v.pop_back();
cout << v.front() << ' ' << v.back() << endl;

v.front() = 4.4;
v.back() = 5.5;
cout << v.front() << ' ' << v.back() << endl;
```

### Output:
```
1.1 3.3
1.1 2.2
4.4 5.5
```

---

## Vectors vs Arrays

| Feature              | Vector                        | Array                      |
|----------------------|-------------------------------|----------------------------|
| Size at runtime      | Dynamic (resizable)           | Fixed at compile time      |
| Bound checking       | Optional (`.at()` or `[i]`)   | None                       |
| Memory               | Heap                          | Stack/Heap (static/dynamic)|
| Type safety          | Yes (via templates)           | No polymorphism            |
| Member functions     | Rich STL methods              | Manual logic required      |

---

# Iterators

Iterators act like **generalized pointers**, allowing you to access container elements.

### Core methods

- `begin()` – Iterator to **first** element
- `end()` – Iterator **past** the last element

### Iterator declaration

```cpp
vector<int>::iterator it;
```

---

## Simple Iterator Example

```cpp
vector<int> v;
v.push_back(5);
v.push_back(4);
v.push_back(8);

vector<int>::iterator it;
for (it = v.begin(); it != v.end(); ++it)
    cout << *it << ' ';
```

### Output:
```
5 4 8
```

---

## Full Example: Vector + Iterator

```cpp
vector<double> v;
for (int i = 2; i <= 5; i++)
    v.push_back(2.2 * i);   // 4.4, 6.6, 8.8, 11.0

vector<double>::iterator it, it1, it2;

for (it = v.begin(); it != v.end(); ++it)
    cout << *it << ' ';
cout << "<--- Original Vector" << endl;

it1 = v.begin();
it2 = v.end();
*it1 = 1.1;
*(it2 - 1) = 9.9;

for (it = v.begin(); it != v.end(); ++it)
    cout << *it << ' ';
cout << "<---- Modified Vector" << endl;

it1 += 3;  // jump to last
it2 -= 3;  // move back to second
cout << *it1 << ' ' << *it2 << "<--- jump" << endl;

--it1;
++it2;
cout << *it1 << ' ' << *it2 << "<---- inc & dec" << endl;

cout << it1[1] << ' ' << it1[-1] << "<---- subscript" << endl;
```

### Output:
```
4.4 6.6 8.8 11 <--- Original Vector
1.1 6.6 8.8 9.9 <---- Modified Vector
9.9 6.6 <--- jump
8.8 8.8 <---- inc & dec
9.9 6.6 <---- subscript
```

---

## Notes

- `vector` gives dynamic array behavior with STL features.
- Iterators let you loop, modify, and navigate container elements efficiently.
- Use `begin()` and `end()` with iterators to write generic code.
- Prefer `.at()` for safe access, `[i]` for fast unchecked access.
