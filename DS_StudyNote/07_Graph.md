# Graph Notes

## Description
**Graph:**
- A non-linear data structure consisting of a finite set of **Vertices** (Nodes) and a set of **Edges** connecting these vertices.
- Unlike trees, graphs generally have no unique root, can contain cycles, and can be disconnected.

**Key Classifications:**
- **Directed (Digraph) vs. Undirected:**
    - **Undirected:** Edges have no direction (relationships are two-way, e.g., $A-B$ implies $B-A$).
    - **Directed:** Edges have a direction (e.g., $A \to B$ does not imply $B \to A$).
- **Weighted vs. Unweighted:**
    - **Weighted:** Edges carry a value (cost, distance, bandwidth).
    - **Unweighted:** All edges are considered equal.
- **Cyclic vs. Acyclic:**
    - A graph with at least one path that starts and ends at the same vertex is **Cyclic**.

## Visualization
[Graph Data Structure - Introduction and Representation](https://www.youtube.com/watch?v=5hPfm_uqXmw)


## Representation Strategy
The choice of representation drastically affects the time and space complexity.

**1. Adjacency Matrix:**
- A 2D array `M[V][V]` where `M[i][j] = 1` (or weight) if an edge exists between $i$ and $j$.
- **Best for:** Dense graphs (many edges, $E \approx V^2$).
- **Pros:** $O(1)$ lookup to check if an edge exists.

**2. Adjacency List:**
- An array of linked lists (or vectors). Array index represents a vertex, and the linked list contains all its neighbors.
- **Best for:** Sparse graphs (few edges, $E \ll V^2$).
- **Pros:** Space-efficient; faster to iterate over neighbors.

## Abstract Data Type
The Graph ADT typically includes the following operations:

* **Add Vertex:** Add a new node to the graph.
* **Add Edge (v1, v2):** Create a connection between two vertices (setting weight if applicable).
* **Remove Vertex:** Delete a node and remove all edges incident to it.
* **Remove Edge (v1, v2):** Delete the connection between two vertices.
* **Has Edge (or IsAdjacent):** Check if a direct connection exists between two vertices.
* **Get Neighbors:** Return a list of all vertices adjacent to a specific vertex.

## Time Complexity

Complexity depends on the representation method.
* **$V$**: Number of Vertices
* **$E$**: Number of Edges

| Operation | Adjacency Matrix | Adjacency List | Notes |
| :--- | :--- | :--- | :--- |
| **Add Vertex** | O($V^2$) | O(1) | Matrix requires resizing/copying the entire 2D array. |
| **Add Edge** | O(1) | O(1) | Matrix: direct index access. List: insert at head. |
| **Remove Vertex**| O($V^2$) | O($V + E$) | Matrix: shift rows/cols. List: remove node and search all lists to remove edges pointing to it. |
| **Remove Edge** | O(1) | O($V$) | Matrix: set to 0. List: traverse linked list of neighbors. |
| **Has Edge/Check**| O(1) | O($degree(V)$) | Matrix is instant. List requires searching the neighbor list. |
| **Get Neighbors** | O($V$) | O($degree(V)$) | Matrix: scan entire row. List: return the list directly. |

## Space Complexity

* **Adjacency Matrix:** ***O($V^2$)***
    * **Explanation:** Requires $V \times V$ space regardless of how many edges exist. Inefficient for sparse graphs.
* **Adjacency List:** ***O($V + E$)***
    * **Explanation:** Requires an array of size $V$ plus nodes for each edge ($2E$ for undirected, $E$ for directed). Ideal for real-world networks which are usually sparse.

## Common Algorithms

* **Traversal:**
    * **BFS (Breadth-First Search):** $O(V + E)$. Uses a **Queue**. Finds shortest path in unweighted graphs.
    * **DFS (Depth-First Search):** $O(V + E)$. Uses a **Stack** (or recursion). Useful for cycle detection and topological sorting.
* **Shortest Path:**
    * **Dijkstra:** $O((V+E)\log V)$ using a Priority Queue. (Greedy, non-negative weights).
    * **Bellman-Ford:** $O(VE)$. (Dynamic Programming, handles negative weights).
* **Minimum Spanning Tree (MST):**
    * **Prim's Algorithm:** $O(E \log V)$. Builds tree node by node.
    * **Kruskal's Algorithm:** $O(E \log E)$. Builds tree edge by edge using Union-Find.
