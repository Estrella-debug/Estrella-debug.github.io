# Array Notes

## Description
**Array:** A contiguous block of memory that stores elements of the same data type. Arrays provide O(1) random access to elements by index, but insertion and deletion operations in the middle are costly O(n) due to the need to shift elements.

## Visualization
[Deep Dive into the Array Data Structure](https://youtu.be/VVZTVHuVSqw?si=QY5Fp9FGSi280zNh)


## Abstract Data Type 
An array is an ADT that supports the collection of elements identified by an index.

| Operation | Description | Time Complexity |
| :--- | :--- | :--- |
| **Access** | Retrieve the value of an element at a specific index. | O(1) |
| **Update** | Modify the value of an element at a specific index. | O(1) |
| **Insert** | Add an element at a specific position, shifting subsequent elements. | O(n) |
| **Delete** | Remove an element at a specific position, shifting subsequent elements. | O(n) |
| **Traversal** | Visit each element in the array sequentially. | O(n) |

Arrays are widely used due to their simplicity and efficiency in index-based access.

## Array Declaration
### Static Array
#### Declaration
```c
// 1D array with five elements
int array[5];
```

#### Initialization
```c
// Initialize the integer array with 10, 20, 30, 40, 50
int array[5] = {10, 20, 30, 40, 50};

// Initialize by for loop
for (int i = 0; i < 5; i++) {
    array[i] = i + 1;
}
```

#### Access
```c
// Retrieve the third element from array (index 2)
printf("%d", array[2]);
```

#### Traverse
```c
// Traverse the entire array and print
for (int i = 0; i < 5; i++) {
    printf("%d", array[i]);
}
```

### Dynamic Array(using malloc/realloc in C/C++)
#### Declaration
```c
/// Dynamic array initialization by malloc()
int *array;
int n = 10;
array = (int *) malloc(n * sizeof(int));
```

#### Initialization
```c
// Initialize by for loop
for (int i = 0; i < n; i++) {
    array[i] = i + 1;
}
```

#### Access
```c
// Access the element by index
for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
}
```

#### Traverse
```c
// Traverse the entire array and print
for (int i = 0; i < n; i++) { // Corrected loop condition to 'n'
    printf("%d", array[i]);
}
```

### Resize(realloc Example)


```c
int *array;
int n = 10;
array = (int *) malloc(n * sizeof(int));

// Initialize the array
for (int i = 0; i < n; i++) {
    array[i] = i + 1;
}

// Double the size of the array
n = n * 2;
int *temp = (int *) realloc(array, n * sizeof(int));

if (temp == NULL) {
    free(array);
    return -1; // Handle memory allocation failure
}

array = temp;

// Initialize the new elements
for (int i = n / 2; i < n; i++) {
    array[i] = i + 1;
}
// Note: free(array) should be called later when the array is no longer needed.
```

## Time Complexity
Time complexity describes how execution time scales with the input size $n$.

| Operation | Best Case | Average Case | Worst Case | Explanation |
| :--- | :--- | :--- | :--- | :--- |
| **Access** by Index | O(1) | O(1) | O(1) | Direct memory address calculation. |
| **Update** by Index | O(1) | O(1) | O(1) | Single write operation. |
| **Insert** at End | O(1) | O(1) | O(1) | Simple write (if capacity allows). |
| **Insert** at Start/Middle | O(n) | O(n) | O(n) | Requires shifting $O(n)$ elements. |
| **Delete** at End | O(1) | O(1) | O(1) | Simple logical removal. |
| **Delete** at Start/Middle | O(n) | O(n) | O(n) | Requires shifting $O(n)$ elements forward. |
| **Traversal** | O(n) | O(n) | O(n) | Must visit all $n$ elements. |

## Space Complexity

* **Space Complexity:** ***O(n)***
    * **Explanation:** The space required to store $n$ elements is directly proportional to $n$.
* **Auxiliary Space:** ***O(1)***
    * **Explanation:** The extra space used by auxiliary variables (like loop counters or temporary pointers) is constant and does not depend on the input size $n$.
