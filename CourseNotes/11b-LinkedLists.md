# C++ Module: Introduction to Linked Lists

## What is a Linked List?

A **linked list** is a linear data structure in which elements (called **nodes**) are connected using **pointers** rather than being stored in contiguous memory locations like arrays.

Each node contains:
- **Data**: the value stored.
- **Pointer(s)**: a reference to the next node (and optionally the previous node, in a **doubly linked list**).

---

## Why Use Linked Lists?

### Motivation

Arrays in C++ have limitations:
- Fixed size (must be declared ahead of time).
- Expensive insertions and deletions (due to shifting elements).

**Linked lists** overcome these issues:
- Dynamic size.
- Easier insertions and deletions (especially at the beginning or middle).

However, linked lists:
- Require more memory (due to pointers).
- Have slower access time (no indexing like arrays).

---

## Types of Linked Lists

- **Singly Linked List**: Each node points to the next node only.
- **Doubly Linked List**: Each node points to both the next and the previous node.
- **Circular Linked List**: The last node points back to the head (can be singly or doubly linked).

---

## Part 1: Singly Linked List

### Node Structure

```cpp
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};
```

---

### Creating a List and Iterating

### `singly_linked_list.cpp`

```cpp
#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to print all elements in the list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL\n";
}

int main() {
    // Creating nodes
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    std::cout << "Singly Linked List: ";
    printList(head);

    // Free memory
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
```

---

### Searching for a Value in the List

```cpp
bool findValue(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);

    printList(head);

    int target = 10;
    if (findValue(head, target))
        std::cout << target << " found in the list.\n";
    else
        std::cout << target << " not found.\n";

    // Free memory (same cleanup as before)
}
```

---

## Part 2: Doubly Linked List

### Node Structure

```cpp
struct DNode {
    int data;
    DNode* prev;
    DNode* next;

    DNode(int value) : data(value), prev(nullptr), next(nullptr) {}
};
```

---

### Creating and Traversing in Both Directions

### `doubly_linked_list.cpp`

```cpp
#include <iostream>

struct DNode {
    int data;
    DNode* prev;
    DNode* next;

    DNode(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Print forward
void printForward(DNode* head) {
    DNode* current = head;
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }
    std::cout << "NULL\n";
}

// Print backward
void printBackward(DNode* tail) {
    DNode* current = tail;
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->prev;
    }
    std::cout << "NULL\n";
}

int main() {
    DNode* head = new DNode(1);
    DNode* second = new DNode(2);
    DNode* third = new DNode(3);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout << "Forward: ";
    printForward(head);

    std::cout << "Backward: ";
    printBackward(third);

    // Free memory
    delete third;
    delete second;
    delete head;

    return 0;
}
```

---

## Notes

| Feature           | Array        | Linked List        |
|-------------------|--------------|--------------------|
| Size              | Fixed        | Dynamic            |
| Memory layout     | Contiguous   | Scattered          |
| Random access     | Yes          | No                 |
| Insert/Delete     | Costly       | Efficient (local)  |
| Memory overhead   | Low          | Higher (pointers)  |

### Key Takeaways:
- Linked lists are useful when you need dynamic memory and frequent insertions/deletions.
- Singly linked lists allow efficient traversal forward.
- Doubly linked lists support traversal in both directions at the cost of extra memory.
- Always free the memory you allocate with `new` to avoid memory leaks.
