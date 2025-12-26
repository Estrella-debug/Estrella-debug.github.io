# Special Topic: Spanning Tree Notes

These are my notes on **Spanning Trees**, focusing on how to find the minimal connected structure in a graph. This concept is crucial for network design and optimization problems.

## 1. What is a Spanning Tree?

### 1.1 Informal Definition

A **spanning tree** of a connected graph $G$ is a subgraph that:

* **Spans** all vertices of $G$ (includes every single node).
* Forms a **tree** (it is connected and has **no cycles**).
* Uses the **minimum number of edges** necessary to keep all vertices connected.

**Key Properties:**
* If a graph has $n$ vertices, its spanning tree has exactly **$n-1$ edges**.
* It connects all vertices with **no loops**.
* It is **not unique** — a single graph can have multiple valid spanning trees.



### 1.2 Why do we care?

Real-world applications include:
* **Network Design**: Connecting computers/cities with minimum cable.
* **Circuit Design**: Wiring electrical components without creating short-circuit loops.
* **Transportation**: Planning a subway system that reaches every station.

> **Key Insight:** A spanning tree gives us the **backbone structure** of a graph — it keeps the essential connections needed to reach everywhere, stripping away the redundancy.

---

## 2. Minimum Spanning Tree (MST)

### 2.1 Weighted Graphs and MST

When edges have **weights** (cost, distance, latency):

* **Minimum Spanning Tree (MST)**: The spanning tree with the **lowest total edge weight**.
* **Goal**: Connect everyone at the **minimum total cost**.

### 2.2 Critical Properties

These two properties are the foundation of all MST algorithms:

1.  **Cut Property**: For any "cut" (splitting vertices into two groups), the **minimum weight edge** crossing that cut *must* be part of the MST.
2.  **Cycle Property**: For any cycle in the graph, the **maximum weight edge** in that cycle *cannot* be part of the MST.

---

## 3. MST Algorithms: The Greedy Approaches

We usually rely on two classic algorithms. Both are "greedy" (they make the best immediate choice).

### 3.1 Kruskal's Algorithm

**Strategy**: "Add the cheapest edges first, as long as they don't form a cycle."

**Algorithm**:
1. Sort all edges by weight (Low → High).
2. Iterate through sorted edges:
    * If adding the edge $(u, v)$ creates a cycle? **Skip it**.
    * If not? **Add it** to the MST.
3. Stop when we have $n-1$ edges.

* **Data Structure**: Union-Find (Disjoint Set) to detect cycles efficiently.
* **Complexity**: $O(E \log E)$.
* **Best for**: Sparse graphs (fewer edges).



### 3.2 Prim's Algorithm

**Strategy**: "Start from one node and grow the tree like a mold, always grabbing the closest neighbor."

**Algorithm**:
1. Pick an arbitrary starting node.
2. Repeat until all nodes are visited:
    * Look at all edges connecting the **Tree** to the **Non-Tree** nodes.
    * Pick the edge with the **minimum weight**.
    * Add that node and edge to the MST.

* **Data Structure**: Priority Queue (Min-Heap) to find the min edge efficiently.
* **Complexity**: $O(E \log V)$.
* **Best for**: Dense graphs (lots of edges).



### 3.3 Comparison: Kruskal vs. Prim

| Aspect | Kruskal's Algorithm | Prim's Algorithm |
| :--- | :--- | :--- |
| **Perspective** | **Edge-centric** (looks at all edges globally) | **Vertex-centric** (grows locally from a node) |
| **Logic** | Sort edges, merge components | Explore neighbors, expand frontier |
| **Data Structure** | Union-Find | Priority Queue |
| **Best Use Case** | Sparse Graphs | Dense Graphs |

---

## 4. Tree vs. Graph: Structural Perspective

### 4.1 From Graph to Tree

**Spanning Tree Extraction** is essentially **simplification**:
* **Graph**: Complex, cyclic, multiple paths between nodes.
* **Tree**: Simple, acyclic, unique path between nodes.

### 4.2 Tree Properties

Once we reduce a graph to a Spanning Tree $T$:
* **Unique Path**: There is exactly one path between any two nodes.
* **Fragile**: Removing any single edge disconnects the graph (bridges).
* **Cycle Creation**: Adding any single edge from the original graph creates exactly one cycle.

---

## 5. Implementation Patterns

### 5.1 Union-Find (for Kruskal's)

To implement Kruskal's fast, we need:
```cpp
// 1. Find: Which set does x belong to?
int find(int x);

// 2. Union: Merge the sets of x and y
void unionSets(int x, int y);
```
### 5.2 Priority Queue (for Prim's)

To implement Prim's, we need a Min-Heap:
```cpp
// Store pairs of (weight, vertex)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
```

### 5.3 Graph Representation

* **Edge List**: Perfect for Kruskal's (easy to sort).
* **Adjacency List**: Perfect for Prim's (easy to traverse neighbors).

---
## 6. Summary

**Big Picture**: Spanning trees bridge the gap between the full complexity of graphs and the simple structure of trees. They provide the essential connectivity with minimal overhead.
* **MST** solves optimization problems (min cost, min wire).
* **Kruskal's** sorts edges (Global approach).
* **Prim's** grows from a node (Local approach).
