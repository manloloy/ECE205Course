# C++ Module: Introduction to Binary Trees and Binary Search Trees (BSTs)

## What is a Binary Tree?

A **binary tree** is a tree data structure in which each node has at most **two children**:
- **Left child**
- **Right child**

### Why Learn Binary Trees?

Binary trees are foundational for many algorithms and data structures:
- Binary Search Trees (BSTs)
- Heaps
- Syntax trees (e.g., parsing expressions)
- Efficient searching and sorting

They also help students build a strong foundation in **recursion**, **pointers**, and **tree traversal** techniques.

---

## Structure of a Node in a Binary Tree

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
```

Each node stores:
- A data value
- A pointer to the left child
- A pointer to the right child

---

## Example: Manually Creating a Tree

### Code

```cpp
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);

    std::cout << "Root: " << root->data << "\n";
    std::cout << "Left child: " << root->left->data << "\n";
    std::cout << "Right child: " << root->right->data << "\n";

    // Clean up
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
```

---

## Traversals (Visiting Nodes)

### 1. Inorder Traversal (Left, Root, Right)

```cpp
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}
```

### 2. Preorder Traversal (Root, Left, Right)

```cpp
void preorder(Node* root) {
    if (root == nullptr) return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
```

### 3. Postorder Traversal (Left, Right, Root)

```cpp
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}
```

---

## Binary Search Trees (BST)

A **Binary Search Tree** is a binary tree that maintains the following property:

- **Left subtree** contains only nodes with values **less than** the current node.
- **Right subtree** contains only nodes with values **greater than** the current node.

### Why BSTs?

- Efficient lookup, insert, delete in **O(log n)** time (on average).
- Keeps data sorted for in-order traversal.

---

## Inserting in a BST

```cpp
Node* insert(Node* root, int value) {
    if (root == nullptr) return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}
```

---

## Searching in a BST

```cpp
bool search(Node* root, int value) {
    if (root == nullptr) return false;
    if (value == root->data) return true;
    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}
```

---

## Full Example: Build and Traverse a BST

### `bst_example.cpp`

```cpp
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr) return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

bool search(Node* root, int value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;
    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

int main() {
    Node* root = nullptr;

    int values[] = {10, 5, 15, 2, 7, 12, 18};
    for (int val : values) {
        root = insert(root, val);
    }

    std::cout << "Inorder traversal of BST: ";
    inorder(root);
    std::cout << "\n";

    int target = 7;
    std::cout << "Searching for " << target << ": "
              << (search(root, target) ? "Found\n" : "Not Found\n");

    return 0;
}
```

---

## Table

| Concept                | Description |
|------------------------|-------------|
| Binary Tree            | Each node has up to 2 children |
| BST Property           | Left < Root < Right |
| Inorder Traversal      | Returns sorted order for BST |
| Insert/Search Time     | O(log n) average, O(n) worst case (unbalanced) |

### Tips:
- BSTs are easy to implement with recursion.
- Use traversal methods to understand the structure.
- Balanced BSTs offer better performance.

You can later expand BSTs to support deletion, balancing (AVL/Red-Black Trees), or use them in search-based applications.
