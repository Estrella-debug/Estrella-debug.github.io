# CS203A – Data Structures · Code Practice

## Array

### Practice I: Code Review and Refinement
- Review the [Practice_Array_1](Array_1.c).
- Refactor and complete the code to improve safety, readability, and correctness.
  - Add Header files, main(), error checking for memory allocation, memory deallocation

### Practice II: Observing Array Behavior
- Use the [Example C code](Example_Array.c) to study memory allocation with `malloc` and `realloc`.
- [Array_2_1](Array_2_1.c) Add the following line to observe memory addresses during execution:    
  ```c
  printf("Index %d -> Value: %d, Address: %p\n", i, array[i], (void*)&array[i]);
- Compare the memory layout before and after reallocation to understand the behavior of dynamic arrays.
  - Understand how arrays are stored in contiguous memory
  - Observe memory layout before and after realloc()
  - Verify if the array was moved during resizing

|                     | Before      | After       |
|---------------------|-------------|-------------|
| Size                | 10 integers | 20 integers |
| Start Address       | 0x...B81450 | 0x...B81450 |
| End Address         | 0x...B814EC | 0x...B8158C |
| Each integer takes  | 4 bytes     | 4 bytes     |
  
- Extend this concept to [2D](Array_2_2.c), [3D](Array_2_3.c), or higher-dimensional arrays to explore how memory is allocated for multidimensional arrays.
- Execute the binary code multiple times to observe the memory locations during the initial allocation with malloc and subsequent expansion with realloc.
