#include <stdio.h>
#include <stdlib.h>

int** arrayCreation(int rows, int columns) {
    int** array = (int**)malloc(rows * sizeof(int*)); // Allocate memory for row pointers
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(columns * sizeof(int)); // Allocate memory for each row
    }
    return array;
}

void arrayValue(int** array, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int data;
            printf("Data for %dth row and %dth column: ", i, j);
            scanf("%d", &data);
            array[i][j] = data;
        }
    }
}

void arrayTraversal(int** array, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d, ", array[i][j]);
        }
        printf("\n");
    }
}

void freeArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]); // Free each row
    }
    free(array); // Free the array of pointers
}

int main() {
    int rows = 3, columns = 3;
    int** array = arrayCreation(rows, columns);
    arrayValue(array, rows, columns);
    arrayTraversal(array, rows, columns);
    freeArray(array, rows); // Free the allocated memory
    return 0;
}