#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 2, y = 3, z = 4;
    int ***array;

    array = (int ***)malloc(x * sizeof(int **));
    if (array == NULL) {
        printf("Memory allocation for layers failed\n");
        return 1;
    }

    for (int i = 0; i < x; i++) {
        array[i] = (int **)malloc(y * sizeof(int *));
        if (array[i] == NULL) {
            printf("Memory allocation for layer %d failed\n", i);
            return 1;
        }
        for (int j = 0; j < y; j++) {
            array[i][j] = (int *)malloc(z * sizeof(int));
            if (array[i][j] == NULL) {
                printf("Memory allocation for row %d in layer %d failed\n", j, i);
                return 1;
            }
        }
    }

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < z; k++)
                array[i][j][k] = i * y * z + j * z + k + 1;

    printf("Initial 3D Array:\n");
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < z; k++)
                printf("array[%d][%d][%d] = %d, Address: %p\n", i, j, k, array[i][j][k], (void*)&array[i][j][k]);

    int new_layers = 2;
    int ***temp = (int ***)realloc(array, (x + new_layers) * sizeof(int **));
    if (temp == NULL) {
        printf("Reallocation of layers failed\n");
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) free(array[i][j]);
            free(array[i]);
        }
        free(array);
        return 1;
    }
    array = temp;

    for (int i = x; i < x + new_layers; i++) {
        array[i] = (int **)malloc(y * sizeof(int *));
        if (array[i] == NULL) {
            printf("Memory allocation for new layer %d failed\n", i);
            return 1;
        }
        for (int j = 0; j < y; j++) {
            array[i][j] = (int *)malloc(z * sizeof(int));
            if (array[i][j] == NULL) {
                printf("Memory allocation for row %d in new layer %d failed\n", j, i);
                return 1;
            }
            for (int k = 0; k < z; k++)
                array[i][j][k] = i * y * z + j * z + k + 1;
        }
    }

    printf("\nResized 3D Array:\n");
    for (int i = 0; i < x + new_layers; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < z; k++)
                printf("array[%d][%d][%d] = %d, Address: %p\n", i, j, k, array[i][j][k], (void*)&array[i][j][k]);

    for (int i = 0; i < x + new_layers; i++) {
        for (int j = 0; j < y; j++) free(array[i][j]);
        free(array[i]);
    }
    free(array);

    return 0;
}
