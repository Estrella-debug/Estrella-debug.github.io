# Queue & Stack notes

## Description
### Queue (FIFO)
- A linear data structure operating on the **First-In-First-Out (FIFO)** principle.
- Elements are added at the **"rear"** (enqueue) and removed from the **"front"** (dequeue).
- Common operations:
    - **Enqueue:** Add an element to the rear.
    - **Dequeue:** Remove an element from the front.
    - **Front/Peek:** Access the front element without removing it.
    - **IsEmpty:** Check if the queue contains any elements.
### Stack (LIFO/FILO)
- A linear data structure operating on the **Last-In-First-Out (LIFO)** or **First-In-Last-Out (FILO)** principle.
- Elements are added and removed from the same end, called the **"top"**.
- Common operations:
    - **Push:** Add an element to the top.
    - **Pop:** Remove the top element.
    - **Peek/Top:** Access the top element without removing it.
    - **IsEmpty:** Check if the stack contains any elements.

## Visualization
[Introduction to Stacks and Queues (Data Structures & Algorithms #12)](https://youtu.be/A3ZUpyrnCbM?si=mmjeKRUDn5JXkA40)

## Abstract Data Type 

Both Stack and Queue are **Abstract Data Types (ADTs)**, meaning they are defined by their logical behavior and the set of operations they support, independent of their underlying implementation (Array or Linked List).

* **Stack ADT:** Defined by the strict LIFO order and operations like `Push`, `Pop`, and `Peek`.
* **Queue ADT:** Defined by the strict FIFO order and operations like `Enqueue`, `Dequeue`, and `Front`.

## Implementation

### Array (Static or Dynamic)
| Feature | Stack | Queue |
| :--- | :--- | :--- |
| **Pros** | **Good cache locality** (faster access). Simple implementation. | **Good cache locality**. |
| **Cons** | **Fixed size** (static array) or costly **resize operation** (dynamic array, amortized O(1)). | **Wasted space** (if using a simple front pointer) or complex **"Circular Array"** implementation to optimize space. |
| **Notes** | The "Top" index simply moves up and down. | Needs two pointers: `front` (for dequeue) and `rear` (for enqueue). |

### Linked List
| Feature | Stack | Queue |
| :--- | :--- | :--- |
| **Pros** | **Dynamic size** (no overflow issues). **O(1)** operations for `Push` and `Pop` (using the head). | **Dynamic size**. **O(1)** operations for `Enqueue` (using the tail) and `Dequeue` (using the head). |
| **Cons** | **Extra memory** required for pointers in each node. **Poor cache locality**. | **Extra memory** for pointers. **Poor cache locality**. |
| **Notes** | The head of the list serves as the **"Top"**. | The head of the list serves as the **"Front"** and the tail serves as the **"Rear"**. |

## Time Complexity

Time complexity for the primary operations in typical implementations.

| Operation | Stack (Array/Linked List) | Queue (Array/Linked List) | Explanation |
| :--- | :--- | :--- | :--- |
| **Push / Enqueue** | O(1) | O(1) | Both operations only involve a fixed number of pointer or index updates (assuming non-resizing array or known list head/tail). |
| **Pop / Dequeue** | O(1) | O(1) | Both operations only involve a fixed number of pointer or index updates. |
| **Peek / Front/Top** | O(1) | O(1) | Accessing the data at the known index/pointer (Top or Front) is immediate. |
| **Search** (Non-Standard) | O(n) | O(n) | Requires traversing all $n$ elements sequentially. |

## Space Complexity

* **Space Complexity (Total):** ***O(n)***
    * **Explanation:** The space required to store $n$ elements for both Stack and Queue is directly proportional to the number of elements stored.
* **Auxiliary Space:** ***O(1)***
    * **Explanation:** The extra space used by auxiliary variables (e.g., `top` index, `front`/`rear` pointers, or temporary variables) is constant and does not depend on the input size $n$.
