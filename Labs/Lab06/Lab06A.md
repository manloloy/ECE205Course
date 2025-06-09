# Lab06A – Singly Linked Lists

## Objectives
In this lab, students will:
- Practice working with singly linked lists in C++
- Learn to traverse and modify linked list structures
- Implement deletion and insertion operations
- Understand pointer manipulation and node relationships

## Background
Linked lists are dynamic data structures consisting of nodes. Each node contains data and a pointer to the next node in the list. Unlike arrays, linked lists do not require contiguous memory and can grow or shrink during execution.

A **singly linked list** has nodes that point only to the next node in the sequence. Understanding how to navigate and modify these structures is crucial for efficient memory management and dynamic data handling.

This lab focuses on:
- Removing a node with a specific value (5)
- Inserting a new node (100) between two existing nodes (7 and 8)

## Instructions
You are given a C++ template with a pre-built linked list containing integers from 1 to 10. Your tasks are:

1. **Traverse and print the list.**
2. **Remove the node with value 5.** Update pointers accordingly.
3. **Print the list again** to verify removal.
4. **Insert a new node with value 100** between nodes with values 7 and 8.
5. **Print the final list** to verify insertion.

### Expected Diagrams

**Initial Linked List:**
```
1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9 → 10
```

**After removing 5:**
```
1 → 2 → 3 → 4 → 6 → 7 → 8 → 9 → 10
```

**After inserting 100 between 7 and 8:**
```
1 → 2 → 3 → 4 → 6 → 7 → 100 → 8 → 9 → 10
```

## C++ Template

```cpp
#include <iostream>
using namespace std;

// Define the node structure
struct Node {
    int value;
    Node* next;
};

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

// TODO: Define a function to delete the node with value 5
// TODO: Define a function to insert 100 between 7 and 8

int main() {
    // Create the initial linked list with values 1 to 10
    Node* head = new Node{1, nullptr};
    Node* current = head;
    for (int i = 2; i <= 10; ++i) {
        current->next = new Node{i, nullptr};
        current = current->next;
    }

    cout << "Initial list:" << endl;
    printList(head);

    // TODO: Call function to delete node with value 5
    // TODO: Print the list after deletion

    // TODO: Call function to insert 100 between 7 and 8
    // TODO: Print the final list

    return 0;
}
```

## Notes
- Always check for `nullptr` when traversing or modifying nodes.
- Use temporary pointers to hold positions while modifying `next` pointers.
- Review how pointer assignment works—mistakes can easily break the list.
- Draw the list on paper while you code to visualize changes.

---

## Submission
Show your TA the output of your program. If you have any questions, make sure you ask.

## Extension (Optional)
Try modifying the list to:
- Insert at the beginning
- Insert at the end
- Delete the last node
- Count the total number of nodes
```

