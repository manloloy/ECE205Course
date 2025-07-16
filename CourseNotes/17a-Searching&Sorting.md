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

**Time Complexity**: O(n)

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

**Time Complexity**: O(log n)

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

**Time Complexity**: O(n²)

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

**Time Complexity**: O(n²)

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

**Time Complexity**: O(n log n)

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

**Time Complexity**: O(n log n) on average, O(n²) worst case

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

```
