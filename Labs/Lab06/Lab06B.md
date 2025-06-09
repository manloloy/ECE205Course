# Lab06B: Doubly Linked Lists in C++

## Objectives

- Understand the structure and operations of a doubly linked list in C++
- Practice forward and backward traversal
- Modify list structure through insertion and deletion
- Reinforce dynamic memory handling and pointer updates

---

## Background

A **doubly linked list** is a linear data structure in which each node points to both its **next** and **previous** node. This bidirectional structure makes it easier to traverse the list in either direction and simplifies some insertion and deletion operations compared to singly linked lists.

Each node in a doubly linked list contains:
- An integer `value`
- A pointer to the `next` node
- A pointer to the `previous` node

---

## Task

You are given a C++ program that creates a doubly linked list with values from `1` through `10`. Your job is to:

1. **Traverse** and print the list **forward** (from head to tail) and **backward** (from tail to head).
2. **Delete** the node with value `4` and ensure the list remains intact.
3. **Insert** a new node with value `99` **after** the node with value `6`.
4. **Print** the final list forward and backward again to verify the modifications.

### Expected Output

#### Initial List
- Forward: `1 2 3 4 5 6 7 8 9 10`
- Backward: `10 9 8 7 6 5 4 3 2 1`

#### After Deleting 4
- Forward: `1 2 3 5 6 7 8 9 10`
- Backward: `10 9 8 7 6 5 3 2 1`

#### After Inserting 99 after 6
- Forward: `1 2 3 5 6 99 7 8 9 10`
- Backward: `10 9 8 7 99 6 5 3 2 1`

---

## Starter Code (students must complete the helper functions)

```cpp
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
};

void printForward(Node* head);
void printBackward(Node* tail);
void deleteNode(Node*& head, Node*& tail, int target);
void insertAfter(Node*& head, Node*& tail, int afterValue, int newValue);

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Step 1: Build doubly linked list with values from 1 to 10
    for (int i = 1; i <= 10; ++i) {
        Node* newNode = new Node{i, nullptr, nullptr};
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    cout << "Initial List:" << endl;
    printForward(head);
    printBackward(tail);

    // Step 2: Delete node with value 4
    deleteNode(head, tail, 4);

    // Step 3: Insert 99 after 6
    insertAfter(head, tail, 6, 99);

    cout << "\nModified List:" << endl;
    printForward(head);
    printBackward(tail);

    // Step 4: Free memory
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
```

---

## Student Instructions

- Complete `printForward`, `printBackward`, `deleteNode`, and `insertAfter`.
- Follow the behavior specified in the expected output.
- Be careful with pointer updates when inserting and deleting.
- Validate output by comparing it to the expected diagrams.

## Submission
-Show your TA the output of your program. If you have any questions, please ask.

---



## Notes

In this lab, students learned to:

- Traverse doubly linked lists forward and backward
- Properly update `prev` and `next` pointers when inserting or deleting nodes
- Manage dynamic memory to build and modify data structures manually

This forms a critical foundation for implementing more complex data structures like deques, priority queues, and even filesystem structures.
