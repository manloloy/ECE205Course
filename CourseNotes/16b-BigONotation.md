# Lecture: Big-O Notation & Algorithmic Complexity

**Duration:** 60 Minutes  
**Target Audience:** Computer Science Students (Introductory to Intermediate Data Structures & Algorithms)  
**Prerequisites:** Basic knowledge of loops, arrays, and basic algebra.

---

## ⏱️ Lecture Agenda

| Time | Section | Topic |
| :--- | :--- | :--- |
| **00:00 – 00:10** | **Section 1** | Introduction & Formal Definition of Big-O |
| **00:10 – 00:35** | **Section 2** | The 6 Key Complexity Classes (Code & Mechanics) |
| **00:35 – 00:50** | **Section 3** | **Interactive Class Activity** (15 min participation) |
| **00:50 – 01:00** | **Section 4** | Rules of Big-O Arithmetic & Wrap-Up |

---

## Section 1: Introduction & Formal Definition (10 Minutes)

### 1.1 Why Big-O?
We do not measure execution speed purely in seconds because hardware, compiler optimizations, and background tasks vary. Instead, we measure **how execution time scales relative to input size ($n$) in the worst-case scenario**.

### 1.2 Formal Definition
Let $f(n)$ and $g(n)$ be non-negative functions from $\mathbb{N} \to \mathbb{R}^+$. We say that:

$$f(n) \in O(g(n))$$

if and only if there exist positive constants $c > 0$ and $n_0 \ge 1$ such that:

$$f(n) \le c \cdot g(n) \quad \text{for all } n \ge n_0$$

> **Key Takeaway:** $g(n)$ acts as a strict **upper bound** on the growth rate of $f(n)$ for sufficiently large inputs.

---

## Section 2: Deep Dive into Key Complexity Classes (25 Minutes)

---

### 1. $O(1)$ — Constant Time
The algorithm takes the same amount of time regardless of how large the input array or data set is.

* **Calculation:** No loops depending on $n$; direct memory access or fixed arithmetic steps.

#### C++ Example
```cpp
int getFirstElement(const std::vector<int>& arr) {
    if (arr.empty()) return -1;
    return arr[0]; // Exactly 1 operation
}
```

#### Python Example
```python
def get_first_element(arr: list[int]) -> int:
    if not arr:
        return -1
    return arr[0]  # Exactly 1 operation
```

---

### 2. $O(\log n)$ — Logarithmic Time
Each step reduces the problem size by a constant fraction (usually half).

* **Calculation:** The loop variable is multiplied or divided by a constant ($k > 1$) in each iteration.

#### Mechanics: How do we calculate $\log_2 n$?
If we start with $n$ elements and halve the problem at every step, after $k$ steps we have $\frac{n}{2^k}$ elements remaining. The loop finishes when:

$$\frac{n}{2^k} = 1 \implies 2^k = n \implies k = \log_2 n$$

#### C++ Example (Binary Search)
```cpp
int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

#### Python Example (Binary Search)
```python
def binary_search(arr: list[int], target: int) -> int:
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1
```

---

### 3. $O(n)$ — Linear Time
Running time scales proportionally with input size $n$.

* **Calculation:** A single loop running from $1$ to $n$ with step increment $+1$.

#### C++ Example
```cpp
int findSum(const std::vector<int>& arr) {
    int sum = 0;
    for (int num : arr) { // Runs n times
        sum += num;
    }
    return sum;
}
```

#### Python Example
```python
def find_sum(arr: list[int]) -> int:
    total = 0
    for num in arr:  # Runs n times
        total += num
    return total
```

---

### 4. $O(n \log n)$ — Linearithmic Time
Common in efficient divide-and-conquer sorting algorithms (Merge Sort, Quick Sort average case).

* **Calculation:** Dividing the problem into $\log n$ levels of recursion, where each level performs $O(n)$ work combining/processing elements.

#### C++ Example (Merge Step Intuition)
```cpp
// Merging two sorted halves takes O(n) time.
// Repeating this across log(n) recursive levels yields O(n log n).
void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);       // Left half
    mergeSort(arr, m + 1, r);   // Right half
    merge(arr, l, m, r);        // O(n) merge work at this level
}
```

#### Python Example (Built-in Timsort)
```python
def sort_data(arr: list[int]) -> list[int]:
    # Python's built-in sorted() runs Timsort: O(n log n) worst/average case
    return sorted(arr)
```

---

### 5. $O(n^2)$ — Quadratic Time
Performance is proportional to the square of the input size.

* **Calculation:** Nested loops where both outer and inner loops iterate up to $n$.

#### C++ Example (Bubble Sort)
```cpp
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

#### Python Example (Bubble Sort)
```python
def bubble_sort(arr: list[int]) -> None:
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
```

#### Operation Count Calculation
The total operations equal:

$$(n-1) + (n-2) + \dots + 1 = \frac{n(n-1)}{2} = \frac{1}{2}n^2 - \frac{1}{2}n \implies O(n^2)$$

---

### 6. $O(n^3)$ — Cubic Time
Common in naive matrix multiplication or three-nested-loop algorithms.

* **Calculation:** Three nested loops each running up to $n$.

#### C++ Example (Matrix Multiplication)
```cpp
using Matrix = std::vector<std::vector<int>>;

Matrix multiplyMatrices(const Matrix& A, const Matrix& B, int n) {
    Matrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {         // Loop 1: n times
        for (int j = 0; j < n; ++j) {     // Loop 2: n times
            for (int k = 0; k < n; ++k) { // Loop 3: n times
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
```

#### Python Example (Triple Loop)
```python
def triple_loop_example(n: int) -> int:
    count = 0
    for i in range(n):  # Loop 1
        for j in range(n):  # Loop 2
            for k in range(n):  # Loop 3
                count += 1
    return count
```

---

## Section 3: Interactive Class Activity (15 Minutes)

> **Instructor Instructions:** Split students into pairs or small groups. Give them **8 minutes** to analyze the three problems below, then spend **7 minutes** reviewing solutions together on the board.

---

### 🙋 Task 1: Code Complexity Analysis (Group Work)
Determine the Big-O time complexity for each snippet and justify your answer.

#### Snippet A (C++)
```cpp
void mysteryA(int n) {
    for (int i = 1; i < n; i *= 2) {
        std::cout << i << std::endl;
    }
}
```

#### Snippet B (Python)
```python
def mystery_b(n: int):
    for i in range(n):
        j = 1
        while j < n:
            j *= 2
```

---

### ✍️ Task 2: Formal Proof Exercise
**Prompt:** Prove formally using the definition of Big-O that:

$$f(n) = 3n^2 + 5n + 2 \in O(n^2)$$

Find valid constants $c$ and $n_0$.

---

### 💡 Solutions & Explanation Key (For Review)

#### Solution to Snippet A:
* **Answer:** $O(\log n)$
* **Reason:** $i$ doubles in each step ($1, 2, 4, 8, \dots$). It takes $\log_2 n$ iterations to reach $n$.

#### Solution to Snippet B:
* **Answer:** $O(n \log n)$
* **Reason:** The outer loop executes $n$ times. The inner `while` loop multiplies $j$ by 2 each time, running $\log n$ times per outer loop pass. Total work: $n \times \log n = O(n \log n)$.

#### Solution to Proof Task:
We need to find $c$ and $n_0$ such that $3n^2 + 5n + 2 \le c \cdot n^2$ for all $n \ge n_0$.

For all $n \ge 1$:
* $5n \le 5n^2$
* $2 \le 2n^2$

Therefore:

$$3n^2 + 5n + 2 \le 3n^2 + 5n^2 + 2n^2 = 10n^2$$

* Choose $c = 10$ and $n_0 = 1$.
* Since $3n^2 + 5n + 2 \le 10n^2$ holds for all $n \ge 1$, $3n^2 + 5n + 2 \in O(n^2)$. $\blacksquare$

---

## Section 4: Rules of Big-O Arithmetic & Summary (10 Minutes)

### 4.1 Simplifying Rules
1. **Drop Low-Order Terms:**  
   $$O(n^3 + 1000n^2 + 50n) \implies O(n^3)$$
2. **Drop Constant Factors:**  
   $$O(500 \cdot n) \implies O(n)$$
3. **Sequential Operations (Addition):**  
   $$O(f(n)) + O(g(n)) = O(\max(f(n), g(n)))$$
4. **Nested Operations (Multiplication):**  
   $$O(f(n)) \times O(g(n)) = O(f(n) \cdot g(n))$$

### 4.2 Growth Rate Hierarchy
Ranked from fastest (most efficient) to slowest:

$$O(1) < O(\log n) < O(n) < O(n \log n) < O(n^2) < O(n^3)$$

---

**Take-Home Challenge:** what complexity class recursive Fibonacci ($T(n) = T(n-1) + T(n-2)$) 
