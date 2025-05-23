# Sets and Maps in C++

C++ provides **associative containers** in the STL that allow fast searching, insertion, and deletion using a key-based structure.

- `std::set` stores **unique values**
- `std::map` stores **key-value pairs** with **unique keys**

Both are typically implemented as **balanced binary search trees** (e.g., red-black tree).

To use them:

```cpp
#include <set>
#include <map>
using namespace std;
```

---

## `std::set`

A `set<T>` is a container that:
- Holds **unique** elements
- Automatically sorts them
- Allows fast lookup, insertion, and deletion

### Example: Basic Set Usage

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> mySet;

    mySet.insert(5);
    mySet.insert(3);
    mySet.insert(9);
    mySet.insert(3);  // duplicate, ignored

    for (int val : mySet)
        cout << val << ' ';
    cout << endl;

    mySet.erase(5);
    if (mySet.find(9) != mySet.end())
        cout << "9 is in the set\n";
}
```

### Output:
```
3 5 9
9 is in the set
```

---

### Common `set` Operations

| Operation            | Description                                |
|----------------------|--------------------------------------------|
| `s.insert(x)`        | Inserts value `x` if not present            |
| `s.erase(x)`         | Removes value `x`                           |
| `s.find(x)`          | Returns iterator to `x` or `end()`         |
| `s.count(x)`         | Returns 1 if `x` exists, 0 otherwise        |
| `s.size()`           | Number of elements                         |
| `s.empty()`          | Checks if set is empty                      |
| `s.begin(), s.end()` | Iterators to traverse                       |

---

## `std::map`

A `map<Key, Value>` is a container that:
- Holds key-value pairs
- Keys are unique and sorted
- Each key maps to exactly one value

### Example: Basic Map Usage

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> age;

    age["Alice"] = 30;
    age["Bob"] = 25;
    age["Charlie"] = 35;

    age["Alice"] = 31;  // overwrite

    for (auto p : age)
        cout << p.first << " is " << p.second << " years old\n";

    if (age.count("Bob"))
        cout << "Bob is in the map\n";

    age.erase("Charlie");
}
```

### Output:
```
Alice is 31 years old
Bob is 25 years old
Charlie is 35 years old
Bob is in the map
```

---

### Common `map` Operations

| Operation             | Description                                |
|-----------------------|--------------------------------------------|
| `m[key] = val`        | Insert or update `key` with `val`          |
| `m.at(key)`           | Access `val` for `key` (throws if not found) |
| `m.find(key)`         | Returns iterator or `m.end()`             |
| `m.count(key)`        | Returns 1 if key exists, 0 otherwise       |
| `m.erase(key)`        | Removes `key`                              |
| `m.size()`            | Number of key-value pairs                  |
| `m.empty()`           | Check if map is empty                      |

---

### Iterating Over a Map

```cpp
map<string, int> scores;
scores["Alice"] = 90;
scores["Bob"] = 85;

for (map<string, int>::iterator it = scores.begin(); it != scores.end(); ++it)
    cout << it->first << ": " << it->second << endl;
```

Or using C++11 range-based for loop:

```cpp
for (const auto& [key, value] : scores)
    cout << key << ": " << value << endl;
```

---

## Set vs Map

| Feature         | `set<T>`            | `map<Key, Value>`         |
|-----------------|---------------------|----------------------------|
| Stores          | Unique values       | Key-value pairs            |
| Access by key   | Value = Key         | Key maps to Value          |
| Syntax          | `s.insert(x)`       | `m[key] = value`           |
| Default sort    | Ascending           | Ascending by key           |
| Lookup          | `s.find(x)`         | `m.find(key)`              |

---

## Example: Counting Word Frequencies

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> wordCount;
    string word;

    while (cin >> word)
        ++wordCount[word];

    for (const auto& [word, count] : wordCount)
        cout << word << ": " << count << endl;
}
```

---

## Notes

- Use `set<T>` for **sorted unique elements**
- Use `map<Key, Value>` for **keyed associations**
- Both provide **fast lookup**, iterators, and are **ordered by default**
- All elements are automatically sorted (unless using `unordered_map` or `unordered_set`)
