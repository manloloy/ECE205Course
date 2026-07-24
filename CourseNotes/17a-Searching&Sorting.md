# Searching and Sorting Algorithms in C++

## Overview

This lecture introduces **fundamental searching and sorting algorithms**, a critical part of algorithmic thinking and data manipulation. These concepts serve as building blocks for more complex algorithms in domains like databases, graphics, and artificial intelligence. Understanding their performance characteristics and implementation in C++ will prepare students to analyze, optimize, and reason about real-world programs.

This lecture is intended for students at a research university who already have experience with arrays, loops, functions, and templates.

---

## Objectives

By the end of this module, students should be able to:

- Implement and compare basic searching algorithms
- Implement and compare common sorting algorithms
- Analyze the time and space complexity of each algorithm
- Choose appropriate algorithms based on data properties and application needs

---

## Section 1: Searching Algorithms

### 1.1 Linear Search

**Description**: Scan each element until the target is found or the list ends.

**How It Works**:
1. Start at the first element (index 0).
2. Compare the current element to the target value.
3. If it matches, return the current index — done.
4. If not, move to the next element and repeat.
5. If the end of the array is reached with no match, return "not found."

**Time Complexity**: O(n)

**Why**: There's no assumption that the data is sorted, so there's no way to rule out any element without checking it. In the worst case (the target is the last element, or isn't present at all), every one of the `n` elements gets visited exactly once — a single loop that runs up to `n` times, which is the defining shape of O(n) from the Big-O notes.

```cpp
int linearSearch(const std::vector<int>& arr, int target) {
    for (std::size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) return i;
    }
    return -1; // Not found
}
```

**Use Case**: Unsorted data or small datasets

---

### 1.2 Binary Search

**Description**: Recursively (or iteratively) split a sorted array to find the target.

**How It Works** (requires the array to already be sorted):
1. Look at the middle element of the current search range.
2. If it matches the target, return its index — done.
3. If the target is smaller than the middle element, repeat the search on the left half only.
4. If the target is larger, repeat the search on the right half only.
5. Repeat until the target is found, or the search range becomes empty (no match).

**Time Complexity**: O(log n)

**Why**: Every comparison throws away half of the remaining elements — the search never has to look at the half it just ruled out. Starting from `n` elements, after `k` halvings there are `n / 2^k` elements left; the search ends once that reaches 1, i.e. when `k = log₂ n`. This is exactly the halving pattern from the Big-O notes' O(log n) section.

```cpp
int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0, high = static_cast<int>(arr.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
```

**Use Case**: Efficient search in sorted datasets

---

## Section 2: Sorting Algorithms

### 2.1 Selection Sort

**Description**: Repeatedly find the smallest (or largest) element and move it to the correct position.

**How It Works**:
1. Treat the array as split into a "sorted" part (initially empty, at the front) and an "unsorted" part (initially everything).
2. Scan the entire unsorted part to find its smallest element.
3. Swap that smallest element into the first position of the unsorted part, growing the sorted part by one.
4. Repeat steps 2–3, always scanning only what's left unsorted, until nothing remains unsorted.

**Time Complexity**: O(n²)

**Why**: For each of the `n` positions being filled, the algorithm scans the rest of the unsorted elements to find the minimum. That scan shrinks by one each pass: `n-1` comparisons, then `n-2`, then `n-3`, ... down to `1`. That sum is `n(n-1)/2`, which simplifies to O(n²) — the same nested-loop derivation used for bubble sort in the Big-O notes. This holds no matter how the input is ordered: selection sort always scans the full unsorted remainder to find the minimum, so best, average, and worst case are all O(n²).

```cpp
void selectionSort(std::vector<int>& arr) {
    for (std::size_t i = 0; i < arr.size(); ++i) {
        std::size_t minIndex = i;
        for (std::size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        std::swap(arr[i], arr[minIndex]);
    }
}
```

**Use Case**: Simple implementation, small datasets

---

### 2.2 Insertion Sort

**Description**: Build the sorted array by inserting elements one by one.

**How It Works**:
1. Treat the first element as a "sorted" section of size 1.
2. Take the next element (the "key") and compare it to the elements before it, from right to left.
3. Shift each element that's larger than the key one position to the right, opening up a gap.
4. Insert the key into the gap — its correct position within the sorted section.
5. Repeat for each remaining element until the whole array is sorted.

**Time Complexity**: O(n²) worst/average case, **O(n) best case**

**Why**: In the worst case (e.g., reverse-sorted input), every new element has to be compared against and shifted past *all* of the previously-sorted elements — the same `n + (n-1) + ... + 1` pattern as selection sort, giving O(n²). But unlike selection sort, insertion sort's inner loop can stop as soon as it finds the right spot. If the array is already sorted, each element only needs one comparison to confirm it's already in place, so the whole pass is a single O(n) scan. This adaptiveness — fast on nearly-sorted data, slow on reverse-sorted data — is why insertion sort shows up as the "nearly sorted data" use case in the table below, and why its best-case row differs from selection sort's.

```cpp
void insertionSort(std::vector<int>& arr) {
    for (std::size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = static_cast<int>(i) - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
```

**Use Case**: Partially sorted data, adaptive behavior

---

### 2.3 Merge Sort

**Description**: Recursively split the array and merge sorted halves.

**How It Works**:
1. If the (sub)array has 0 or 1 elements, it's already sorted — base case, stop.
2. Otherwise, split the array into two roughly equal halves.
3. Recursively sort the left half using this same process.
4. Recursively sort the right half using this same process.
5. **Merge** the two now-sorted halves back into one sorted array: repeatedly compare the smallest remaining element of each half and take whichever is smaller, until both halves are exhausted.

**Time Complexity**: O(n log n)

**Why**: The array is cut in half at every level of recursion — the same halving pattern as binary search — which produces `log₂ n` levels total. At each level, merging all the pieces back together touches every element exactly once, which is O(n) work *per level* (spread across however many merge calls are happening at that level). Total work is (work per level) × (number of levels) = O(n) × O(log n) = **O(n log n)** — this is the same "nested operations multiply" reasoning from the Big-O notes, just applied to recursion depth instead of nested loops.

```cpp
void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    std::size_t i = 0, j = 0;
    int k = left;
    while (i < L.size() && j < R.size()) {
        arr[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
    }
    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

**Use Case**: Large datasets with stable sorting required

---

### 2.4 Quick Sort

**Description**: Select a pivot and partition the array around it.

**How It Works**:
1. Choose a **pivot** element from the (sub)array (this implementation uses the last element).
2. **Partition** the array around the pivot: rearrange elements so everything smaller than the pivot ends up before it and everything larger ends up after it. After partitioning, the pivot sits in its final, correct sorted position.
3. Recursively apply the same process to the sub-array of elements *before* the pivot.
4. Recursively apply the same process to the sub-array of elements *after* the pivot.
5. Once every sub-array has shrunk to size 0 or 1, the whole array is sorted — no separate merge step is needed, because partitioning already places elements relative to a value that's in its final position.

**Time Complexity**: O(n log n) on average, **O(n²) worst case**

**Why**: Each partition pass touches every element in that range once, so partitioning is O(n) work. If the pivot happens to split the array into two roughly equal halves each time, that gives `log n` levels of recursion — the same shape as merge sort, so O(n) × O(log n) = O(n log n) on average. But if the pivot is consistently the smallest or largest remaining element (for example, already-sorted input with this last-element pivot choice), each partition only peels off *one* element instead of splitting the array in half. That produces `n` levels of recursion instead of `log n`, giving O(n) × O(n) = **O(n²)** in the worst case. This is exactly why pivot selection matters in practice — randomizing the pivot or picking a median-of-three makes the worst case very unlikely to occur on typical or adversarial input.

```cpp
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot)
            std::swap(arr[++i], arr[j]);
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
```

**Use Case**: Most practical general-purpose sort; used in STL’s `std::sort`

---

## Section 3: STL Sorting and Searching

C++ provides high-performance generic algorithms in `<algorithm>`:

```cpp
#include <algorithm>
#include <vector>

std::vector<int> nums = {5, 3, 8, 1};
std::sort(nums.begin(), nums.end());
bool found = std::binary_search(nums.begin(), nums.end(), 3);
```

- `std::sort` uses introsort (hybrid of quicksort, heapsort, and insertion sort)
- `std::binary_search` assumes sorted input

---

## Table

> **Note on notation:** each Best/Average/Worst column below is written with $O$, following the common convention used by most references (cppreference, interview-prep sheets, etc.). Once a case is fixed (e.g. "worst case"), the value is actually known exactly, not just bounded above — so the more precise symbol is $\Theta$. See [16c-BigOmegaBigTheta.md](./16c-BigOmegaBigTheta.md) for the exact per-case $\Theta$ treatment of every row in this table.

| Algorithm      | Time (Best) | Time (Average) | Time (Worst) | Space | Stable | Use Case                          |
|----------------|-------------|----------------|---------------|--------|--------|-----------------------------------|
| Linear Search  | O(1)        | O(n)           | O(n)          | O(1)   | N/A    | Unsorted data                     |
| Binary Search  | O(1)        | O(log n)       | O(log n)      | O(1)   | N/A    | Sorted data                       |
| Selection Sort | O(n²)       | O(n²)          | O(n²)         | O(1)   | No     | Simple implementation             |
| Insertion Sort | O(n)        | O(n²)          | O(n²)         | O(1)   | Yes    | Nearly sorted data                |
| Merge Sort     | O(n log n)  | O(n log n)     | O(n log n)    | O(n)   | Yes    | Stable sort needed                |
| Quick Sort     | O(n log n)  | O(n log n)     | O(n²)         | O(log n)| No    | Fast general-purpose sort         |

---

## Practice Exercises

1. Implement and compare linear and binary search on a sorted list of integers.
2. Sort a list of strings alphabetically using insertion sort.
3. Write a C++ program that uses merge sort to sort student grades.
4. Use `std::sort` and `std::binary_search` to find whether a user-supplied number exists in a dataset.
5. Compare the performance of `selectionSort` and `std::sort` on a dataset with 10,000 random integers.

---
