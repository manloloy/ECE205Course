# C++ Module: Introduction to Recursion

## What Is Recursion?

**Recursion** is a programming technique where a function calls itself in order to solve smaller instances of the same problem.

At its core, recursion allows us to:
- Break complex problems into simpler subproblems.
- Use elegant, compact logic to solve problems that involve repetitive, self-similar steps.

---

## When Should You Use Recursion?

Recursion is ideal when:
- A problem can be divided into subproblems of the same type.
- You can clearly define a **base case** (the stopping condition).
- You want to avoid manual loops and state-tracking for elegant solutions.

Common recursive problems:
- Factorials
- Fibonacci sequences
- Tree traversal
- Directory traversal
- Divide and conquer algorithms like **Merge Sort**, **Quick Sort**

---

## Anatomy of a Recursive Function

Every recursive function must include:
1. **Base case** – a condition where the function stops calling itself.
2. **Recursive step** – where the function calls itself with a smaller/simpler input.

---

## Simple Example: Factorial

**Definition:**  
`n! = n * (n - 1) * (n - 2) * ... * 1`  
And `0! = 1` by definition.

### `factorial.cpp`

```cpp
#include <iostream>

// Recursive factorial function
int factorial(int n) {
    if (n == 0) return 1; // Base case
    return n * factorial(n - 1); // Recursive step
}

int main() {
    int number = 5;
    std::cout << "Factorial of " << number << " is " << factorial(number) << "\n";
    return 0;
}
```

---

## Visualizing Recursive Calls (for factorial)

For `factorial(3)`, the calls look like this:

```
factorial(3)
 → 3 * factorial(2)
      → 2 * factorial(1)
           → 1 * factorial(0)
                → 1  [base case]
```

Then it resolves:
```
1 → 1
factorial(1) → 1 * 1 = 1
factorial(2) → 2 * 1 = 2
factorial(3) → 3 * 2 = 6
```

---

## Another Example: Fibonacci Numbers

**Definition:**

```
fib(0) = 0  
fib(1) = 1  
fib(n) = fib(n-1) + fib(n-2)
```

### `fibonacci.cpp`

```cpp
#include <iostream>

// Recursive Fibonacci
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    for (int i = 0; i <= 10; ++i)
        std::cout << "fib(" << i << ") = " << fib(i) << "\n";
    return 0;
}
```

⚠️ Note: This is not the most efficient implementation. It recalculates many values multiple times. You can improve this using **memoization**.

---

## What is Memoization?

**Memoization** is an optimization technique used to speed up recursive functions by storing (or “memoizing”) the results of expensive function calls and returning the cached result when the same inputs occur again.

For example, `fib(5)` will calculate `fib(4)` and `fib(3)` — but `fib(3)` will be calculated again inside `fib(4)`. Memoization stores that value after the first time it’s computed.

You can use an array or `std::unordered_map<int, int>` to cache these values.

---

## Iterative vs Recursive Trade-Offs

| Aspect                | Recursive                              | Iterative                              |
|-----------------------|-----------------------------------------|-----------------------------------------|
| **Clarity**           | Often shorter and more elegant          | May be longer and more manual           |
| **Performance**       | May use more memory (due to call stack) | Generally faster with less memory       |
| **Risk**              | Risk of stack overflow                  | No risk of stack overflow               |
| **Debugging**         | Can be harder due to deep call stack    | Easier step-by-step tracing             |
| **Suitability**       | Good for tree and divide/conquer problems | Good for loops and straightforward iteration |

**General Rule:**  
Use recursion when:
- The problem is naturally recursive (e.g., trees, graphs, backtracking).
- Readability and clarity are more important than raw speed.

Use iteration when:
- Performance and memory are critical.
- The problem does not require multiple simultaneous recursive calls.

---

## Final Example: Recursive Merge Sort

**Merge Sort** is a classic sorting algorithm based on recursion and divide-and-conquer.

### `mergesort.cpp`

```cpp
#include <iostream>
#include <vector>

// Merge two sorted halves into one sorted result
void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp;
    int i = left;
    int j = mid + 1;

    // Compare elements from both halves and copy the smaller one
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    // Copy remaining elements
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    // Copy back to original array
    for (int k = 0; k < temp.size(); ++k)
        arr[left + k] = temp[k];
}

// Recursively divide and sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return; // Base case

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);       // Sort left half
    mergeSort(arr, mid + 1, right);  // Sort right half
    merge(arr, left, mid, right);    // Merge the two halves
}

int main() {
    std::vector<int> numbers = {8, 2, 5, 1, 9, 6, 3};

    std::cout << "Before sorting: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << "\n";

    mergeSort(numbers, 0, numbers.size() - 1);

    std::cout << "After sorting: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << "\n";

    return 0;
}
```

---

## Table

| Term          | Description |
|---------------|-------------|
| Recursion     | Function calls itself to solve subproblems |
| Base Case     | Stops the recursion |
| Recursive Step| Calls itself with simpler input |
| Call Stack    | Each recursive call adds a frame to the stack |
| Risk          | Too many recursive calls can overflow the stack |
| Memoization   | Stores results of function calls to avoid recomputation |
| Trade-off     | Recursive = elegant but can be slower, Iterative = faster but more manual |

---

## Notes

- Recursion breaks down complex problems.
- Every recursive function needs a base case and a recursive step.
- Use recursion for divide-and-conquer problems and when code clarity is important.
- Memoization is a powerful tool to optimize recursive functions.
- Merge Sort is a real-world recursive sorting algorithm.

