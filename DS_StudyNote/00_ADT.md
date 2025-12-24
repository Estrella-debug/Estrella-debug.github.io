#  Abstract Data Type (ADT) Notes

##  Core Concept

* **Definition:** An ADT is a way to describe a data structure by focusing on **what it does** (its **behavior**) instead of **how it works inside** (its internal implementation).
* **Key Advantage:** **Hiding the implementation complexity** is the biggest win. ADTs allow developers to prioritize logic and problem-solving, effectively skipping low-level details.

##  What an ADT Specifies

An Abstract Data Type fundamentally specifies:

1.  **A set of operations.**
2.  **The mathematical model of the data.**

## Common Examples of ADTs

* Stacks
* Queues
* Lists
* Sets

## Visualization
[【資料結構】第一講：Data Abstraction and bag #2 Abstract data types](https://youtu.be/FgVOhDfbT-8?si=1DdxVuUd7Qbu4J2l)

##  Examples of ADTs in Libraries

### 1. Standard Template Library (STL) in C++

* **Collection:** Offers well-defined structures (e.g., `vector`, `list`, `stack`, `queue`).
* **Abstraction:** Structures are defined by their **operations/behavior**; implementation is **abstracted**.
* **Separation:** Lets developers focus on problem-solving without knowing the internal code.

### 2. Boost C++ Libraries

* **Interface:** Library **headers (.h files)** define the **interface** and **behavior**.
* **Implementation:** Corresponding **.cpp files** provide the concrete **implementation**.
* **Design Benefit:** Interface/implementation separation allows focusing on **what the features do**.
