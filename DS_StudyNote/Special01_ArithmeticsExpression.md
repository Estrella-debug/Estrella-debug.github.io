# Arithmetic Expressions: Stacks & Trees Notes

These are my notes on processing math expressions using **Stacks** and **Trees**. The main focus is understanding how a computer actually interprets a calculation like `(3 + 5) * (2 - 4)`.

## 1. What is an Arithmetic Expression?

Simply put, it’s a math problem. But in Computer Science, we care more about the **structure** (what gets calculated first) than just the final number.

### 1.1 Components

An expression is made up of two main things:

* **Operands**: The "data" itself.
    * Constants: `3`, `10`, `2.5`
    * Variables: `x`, `y`
* **Operators**: The "actions" performed on the data.
    * Binary: `+`, `-`, `*`, `/`
    * Unary: `-x` (negation), `sin(x)`

### 1.2 Evaluation Rules

How does the computer know what to solve first?
1. **Precedence**: Priority. For example, `*` beats `+`, so in a tree, `*` will be the parent (or evaluated later), and `+` will be deeper.
2. **Associativity**: If the priority is the same (like two `+` signs), we usually go Left-to-Right.

---

## 2. Representations

Using `(3 + 5) * (2 - 4)` as an example, here is how humans see it versus how machines see it.

### 2.1 Human vs. Machine View

| Representation | Format / Example | Description |
| :--- | :--- | :--- |
| **Raw String** | `"(3 + 5) * (2 - 4)"` | For humans. Since it's linear (one line), we **must** use parentheses to group things correctly. |
| **Token Sequence** | `[NUM(3), PLUS, NUM(5), ...]` | The code chops the string into meaningful chunks (Tokens). |
| **Numeric Value** | `-16` | The final answer. |

### 2.2 Expression Tree (The Structural View)

This is the visual representation of the logic.

**Key Point:** You will notice **there are no parentheses nodes** in this tree.
The hierarchy does the talking—you have to solve the bottom children before you can solve the top root.

* **Leaves**: Always numbers (Operands).
* **Internal Nodes**: Always symbols (Operators).

```text
      *
     / \
    +   -
   / \ / \
  3  5 2  4
```
---

## 3. Prefix, Infix, Postfix: Three Notations, One Tree

This is the most important concept connecting Trees and Expressions. Depending on how we **traverse** (walk through) the Expression Tree, we get three different notations.

| Traversal Logic | Order | Notation Name | Example Result |
| :--- | :--- | :--- | :--- |
| **Inorder** | Left → Root → Right | **Infix** | `(3 + 5) * (2 - 4)` |
| **Preorder** | Root → Left → Right | **Prefix** (Polish) | `* + 3 5 - 2 4` |
| **Postorder** | Left → Right → Root | **Postfix** (Reverse Polish) | `3 5 + 2 4 - *` |

### Why do we care?
* **Infix** is for **Humans**. It's easy to read but hard for computers (needs parentheses).
* **Prefix & Postfix** are for **Machines**. They **do not need parentheses**.
    * Because the order is fixed by the position of the operator, the computer knows exactly what to calculate next.

---

## 4. Where does the Stack come in?

We defined the **Tree** to visualize the structure, but we use the **Stack** to actually **calculate** (evaluate) it efficiently.

### 4.1 Evaluating Postfix with a Stack
Computers love **Postfix** notation because it's linear and easy to solve using a Stack.

**Algorithm for `3 5 + 2 4 - *`**:
1. Read `3`, `5` → **Push** to Stack.
2. Read `+` → **Pop** `5` and `3`, calculate `3+5=8`, **Push** `8`.
3. Read `2`, `4` → **Push** to Stack.
4. Read `-` → **Pop** `4` and `2`, calculate `2-4=-2`, **Push** `-2`.
5. Read `*` → **Pop** `-2` and `8`, calculate `8 * -2 = -16`.
6. **Result:** `-16`.

### 4.2 Converting Infix to Postfix (Shunting Yard)
To convert a human-readable string `(A+B)*C` into a machine-friendly Postfix `AB+C*`, we also use a Stack to temporarily hold operators (like `+` or `*`) until their operands are ready.

---

## 5. Summary

* **Expression Tree**: The **structural** view. It explains *logic*.
    * Parentheses are implicit (built into the tree shape).
* **Stack**: The **algorithmic** view. It explains *execution*.
    * Used to evaluate Postfix or traverse the tree.
* **Notations**:
    * Preorder Traversal = Prefix Notation
    * Inorder Traversal = Infix Notation
    * Postorder Traversal = Postfix Notation
