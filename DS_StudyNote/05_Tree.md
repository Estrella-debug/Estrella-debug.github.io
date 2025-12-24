# Tree Notes

## Description
**Tree (General):**
- A hierarchical data structure consisting of nodes connected by edges.
- It must be **acyclic** (no loops).
- Key components include the **Root** (topmost node), **Parent/Child** relationships, and **Leaves** (nodes with no children).

**Binary Tree (BT):**
- A specific type of tree where every node has **at most two children**.
- Children are distinguished strictly as **Left Child** and **Right Child**.

**Binary Search Tree (BST):**
- A binary tree that satisfies the following ordering property for **every node `N`**:
    - All keys in `N->left` subtree are **less than** `N->key`.
    - All keys in `N->right` subtree are **greater than** `N->key`.
- This structure enables efficient searching, insertion, and deletion, functioning similarly to a sorted list but with faster updates.

## Visualization
[Binary Search Trees (BST) Explained in Animated Demo](https://www.youtube.com/watch?v=mtvbVLK5xDQ)


## Abstract Data Type
The Binary Search Tree ADT is defined by the following set of operations:

* **Insert (or Put):** Store a key-value pair. The tree is traversed (left if smaller, right if larger) to find the correct leaf position for the new node.
* **Search (or Get/Lookup):** Retrieve a value or check for existence. Compare the key with the current node; move left if smaller, right if larger.
* **Delete (or Remove):** Remove a node with a specific key. This is more complex and handles three cases:
    1. Node is a leaf (simply remove).
    2. Node has one child (bypass the node).
    3. Node has two children (replace with In-order Successor or Predecessor).
* **Traversal:** Visit all nodes in a specific order (e.g., **In-order**, **Pre-order**, **Post-order**). In-order traversal of a BST yields sorted values.

## Time Complexity

Time complexity depends heavily on the **height ($h$)** of the tree.
- **Balanced Tree:** $h \approx \log_2 n$.
- **Skewed Tree (Worst Case):** $h \approx n$ (degenerates into a Linked List).

| Operation | Best Case | Average Case | Worst Case | Notes (Worst Case occurs when tree is skewed) |
| :--- | :--- | :--- | :--- | :--- |
| **Search/Lookup** | O(1) | O($\log n$) | O(n) | Depends on tree height. $O(n)$ if keys are inserted in sorted order without balancing. |
| **Insert** | O(1) | O($\log n$) | O(n) | Requires finding the location first (traversal), then constant time linking. |
| **Delete** | O(1) | O($\log n$) | O(n) | Requires searching, plus potential constant time adjustments (or successor finding). |

## Space Complexity

* **Space Complexity (Total):** ***O(n)***
    * **$n$** is the number of nodes stored.
    * **Explanation:** Every node requires storage for the data and pointers to children.
* **Auxiliary Space (Stack Space):** ***O(h)***
    * **$h$** is the height of the tree.
    * **Explanation:** Recursive operations (Search, Insert, Delete, Traversal) use stack space proportional to the tree height.
    * **Average Case:** $O(\log n)$ for a balanced tree.
    * **Worst Case:** $O(n)$ for a skewed tree.
