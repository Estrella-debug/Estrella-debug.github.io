# Linked List notes

## Description
**Linked List:** A linear sequence of nodes where elements are stored in non-contiguous memory locations. Each node comprises two parts: a data field (value) and a pointer/reference field that links to the next node in the sequence. While traversal is sequential O(n), insertion or deletion (when the preceding node is known) is highly efficient at O(1).

## Visualization
[Learn Linked Lists in 13 minutes 🔗](https://youtu.be/N6dOwBde7-M?si=KtX3MxpE8041VqX8)


## Abstract Data Type
A linked list is an ADT defined by the following core operations.

| Operation | Description | Time Complexity (General) |
| :--- | :--- | :--- |
| **Create** | Initialize an empty linked list (e.g., set the `head` pointer to NULL). | O(1) |
| **Insert** | Add a new node at a specific position. | O(1) (At head or after a known node) / O(n) (At tail or specific index) |
| **Delete** | Remove a node at a specific position. | O(1) (Node is known and not the head) / O(n) (By value or index) |
| **Search** | Find a node containing a specific value. | O(n) |
| **Traverse** | Visit each node in the linked list sequentially. | O(n) |
| **Update** | Modify the value of a node at a specific position (requires prior search/access). | O(1) (Node is known) / O(n) (By index) |

Linked lists are crucial for tasks requiring **dynamic memory usage** and **frequent insertion/deletion** operations, offering advantages over fixed-size arrays.

## Time Complexity

Time complexity describes how execution time scales with the input size $n$.

| Operation | Best Case | Average Case | Worst Case | Explanation |
| :--- | :--- | :--- | :--- | :--- |
| **Access/Search** (by value/index) | O(1) | O(n) | O(n) | Must traverse sequentially until the element is found or the end is reached. |
| **Insert** (at Head) | O(1) | O(1) | O(1) | Only requires updating the head pointer. |
| **Insert** (at Tail, *if tail pointer is maintained*) | O(1) | O(1) | O(1) | Requires updating the tail node's `next` pointer and the tail pointer. |
| **Insert** (in Middle, *node is known*) | O(1) | O(1) | O(1) | Only pointer redirection is needed. |
| **Delete** (Node is known) | O(1) | O(1) | O(1) | Requires redirecting the *previous* node's pointer (Note: **Singly** lists often require $O(n)$ to find the previous node). |
| **Traversal** | O(n) | O(n) | O(n) | Must visit all $n$ nodes. |

## Space Complexity

* **Space Complexity (Total):** ***O(n)***
    * **Explanation:** The space required to store $n$ nodes is directly proportional to $n$. Each node stores the data plus one or more pointers/references.
* **Auxiliary Space:** ***O(1)***
    * **Explanation:** Operations typically require only a fixed, constant amount of extra space (e.g., for temporary pointers like `current` or `new_node`) regardless of the list size $n$.
