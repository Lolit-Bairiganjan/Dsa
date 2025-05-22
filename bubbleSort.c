#include <stdio.h>

int bubbleSort(int array[], int size){
    for(int i=0; i<size; i++){
        int sorted = 1; // Assume sorted
        for(int j=0; j<(size-i-1); j++){
            if(array[j]>array[j+1]){
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                sorted = 0; // Found a swap, so not sorted
            }
        }
        if(sorted){
            return 1; // Early exit: already sorted
        }
    }
    return 0; // Needed full passes
}

void printElements(int array[], int size){
    for(int i=0; i<size; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int main(){
    int array[5] = {5, 4, 3, 2, 1};
    int size = (sizeof(array)/sizeof(int));
    printf("%d\n", bubbleSort(array, size));
    printElements(array, size);
    return 0;
}