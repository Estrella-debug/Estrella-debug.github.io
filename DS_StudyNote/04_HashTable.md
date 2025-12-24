# Hash Table Notes

## Description
**Hash Table (or Hash Map):**
- A data structure that stores key-value pairs using an underlying array (or list of buckets).
- It uses a hash function to compute an index (a bucket location) from a given key.
- This mapping enables average constant-time complexity (O(1)) for insertion, deletion, and lookup operations.
- Hash tables are ideal for fast data retrieval due to this efficiency.

## Visualization
[Hash Table Data Structure - Basics | Animation | Visualization](http://www.youtube.com/watch?v=Wct0Z2g9XgU)


## Abstract Data Type 
The Hash Table ADT is defined by the following set of operations, which manage the key-value mapping:

* **Insert (or Put):** Store a key-value pair. The key is hashed to determine the bucket location.
* **Lookup (or Get):** Retrieve the value associated with a given key. The key is hashed to find the bucket, and the key is then compared (to handle collisions).
* **Delete (or Remove):** Remove the key-value pair associated with a given key.
* **Resize (or Rehashing):** When the table becomes too full (high load factor), the underlying array is usually doubled in size, and all existing elements are re-hashed and re-inserted into the new array.
* **Contains (or Check):** Check if a specific key exists in the table.

## Time Complexity

Time complexity depends heavily on the **load factor ($\lambda$)** and the quality of the hash function. The complexities below assume a good hash function and a well-managed load factor ($\lambda \le 0.75$).

| Operation | Best Case | Average Case | Worst Case | Notes (Worst Case occurs during high collision) |
| :--- | :--- | :--- | :--- | :--- |
| **Insert** | O(1) | O(1) | O(n) | Degenerates to O(n) if all keys hash to the same bucket (e.g., poor hash function or high load factor). |
| **Lookup/Search** | O(1) | O(1) | O(n) | Same reason as insertion. In chaining, this means traversing a linked list of length $n$. |
| **Delete** | O(1) | O(1) | O(n) | Same reason as insertion. Requires finding the element first. |
| **Resize/Rehashing** | O(N) | O(N) | O(N) | $N$ is the total number of elements in the table. This is triggered when $\lambda$ exceeds a threshold. |

## Space Complexity

* **Space Complexity (Total):** **O(n + m)**, or simply ***O(n)***
    * **$n$** is the number of key-value pairs stored.
    * **$m$** is the number of buckets in the underlying array.
    * **Explanation:** The space is determined by the size of the array ($m$) plus the space required for the $n$ data elements (and any collision structures, like linked list nodes). Since $m$ is usually proportional to $n$ to maintain an O(1) average time, the complexity is often simplified to $O(n)$.
* **Auxiliary Space (excluding storage for $n$ elements):** ***O(m)***
    * **Explanation:** The space required just for the bucket array itself.
