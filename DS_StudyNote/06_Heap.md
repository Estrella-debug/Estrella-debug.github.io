# Heap Notes

## Description
**Heap:**
- A specialized tree-based data structure that satisfies the **Heap Property**.
- It is widely used to implement **Priority Queues** and in the **Heap Sort** algorithm.

**Shape Property (Structure):**
- A heap is a **Complete Binary Tree**.
- **Complete:** Every level is completely filled, except possibly the last level, and all nodes in the last level are filled from **left to right**.
- This structural constraint allows heaps to be efficiently implemented using an **Array** without any gaps (no need for pointers).

**Heap Property (Order):**
- **Max Heap:** For every node $i$, the value of $i$ is greater than or equal to the values of its children ($Parent \ge Children$). The **maximum** element is at the root.
- **Min Heap:** For every node $i$, the value of $i$ is less than or equal to the values of its children ($Parent \le Children$). The **minimum** element is at the root.

## Visualization
[Heaps and Heap Sort - Visualized](https://www.youtube.com/watch?v=2DmK_H7IdTo)

## Abstract Data Type
The Heap ADT is defined by the following core operations:

* **Insert (or Push):** Add a new element to the heap.
    * *Mechanism:* Add the element to the end of the array (bottom-left available spot), then **Bubble Up** (or Sift Up/Percolate Up) to restore the heap property.
* **Extract Max/Min (or Pop):** Remove and return the root element (the extremum).
    * *Mechanism:* Replace the root with the last element in the array, remove the last element, then **Bubble Down** (or Sift Down/Heapify Down) to restore the heap property.
* **Peek (or Top):** Return the root element without removing it.
* **Decrease/Increase Key:** Update the value of a key at a specific index and adjust its position (Bubble Up or Down) to maintain order.
* **Build Heap:** Convert an arbitrary array of $n$ elements into a valid heap.

## Time Complexity

Time complexity is determined by the height of the tree, which is $\log n$ for a complete binary tree.

| Operation | Best Case | Average Case | Worst Case | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **Peek/Top** | O(1) | O(1) | O(1) | Direct access to the root (index 0). |
| **Insert** | O(1) | O($\log n$) | O($\log n$) | Requires bubbling up from leaf to root. |
| **Extract Max/Min**| O($\log n$) | O($\log n$) | O($\log n$) | Requires bubbling down from root to leaf. |
| **Build Heap** | O(n) | O(n) | O(n) | Using the standard "bottom-up" approach (Floyd's algorithm). Naive insertion is $O(n \log n)$. |
| **Heap Sort** | O($n \log n$) | O($n \log n$) | O($n \log n$) | Involves building the heap ($O(n)$) + extracting $n$ times ($O(n \log n)$). |

## Space Complexity

* **Space Complexity (Total):** ***O(n)***
    * **$n$** is the number of elements.
    * **Explanation:** A heap is typically implemented as an array storing exactly $n$ elements.
* **Auxiliary Space:** ***O(1)***
    * **Explanation:** Unlike standard trees using node pointers, heaps utilize array indexing math to locate relationships, requiring no extra storage for pointers.
    * **Array Indexing Formulas (0-based index):**
        * **Parent:** $\lfloor (i-1) / 2 \rfloor$
        * **Left Child:** $2i + 1$
        * **Right Child:** $2i + 2$
