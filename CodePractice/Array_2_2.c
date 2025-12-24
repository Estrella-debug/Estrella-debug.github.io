#include <stdio.h>
#include <stdlib.h>

int main() {
    int m = 3, n = 5;
    int **array;

    array = (int **)malloc(m * sizeof(int *));
    if (array == NULL) {
        printf("Memory allocation for rows failed\n");
        return 1;
    }

    printf("Initial array pointer address: %p\n", (void*)array);

    for (int i = 0; i < m; i++) {
        array[i] = (int *)malloc(n * sizeof(int));
        if (array[i] == NULL) {
            printf("Memory allocation for row %d failed\n", i);
            return 1;
        }
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            array[i][j] = i * n + j + 1;

    printf("First element address: %p\n", (void*)&array[0][0]);
    printf("Last element address : %p\n", (void*)&array[m-1][n-1]);

    printf("\nInitial 2D Array:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            printf("array[%d][%d] = %d, Address: %p\n", i, j, array[i][j], (void*)&array[i][j]);

    int **temp = (int **)realloc(array, (m + 2) * sizeof(int *));
    if (temp == NULL) {
        printf("Reallocation of row pointers failed\n");
        for (int i = 0; i < m; i++) free(array[i]);
        free(array);
        return 1;
    }

    printf("\nArray pointer after realloc: %p\n", (void*)temp);
    array = temp;

    for (int i = m; i < m + 2; i++) {
        array[i] = (int *)malloc(n * sizeof(int));
        if (array[i] == NULL) {
            printf("Memory allocation for new row %d failed\n", i);
            return 1;
        }
        for (int j = 0; j < n; j++)
            array[i][j] = i * n + j + 1;
    }

    printf("First element after resize: %p\n", (void*)&array[0][0]);
    printf("Last element after resize : %p\n", (void*)&array[m+1][n-1]);

    printf("\nResized 2D Array:\n");
    for (int i = 0; i < m + 2; i++)
        for (int j = 0; j < n; j++)
            printf("array[%d][%d] = %d, Address: %p\n", i, j, array[i][j], (void*)&array[i][j]);

    for (int i = 0; i < m + 2; i++) free(array[i]);
    free(array);

    return 0;
}
