#include <stdio.h>

void insertionSort(int array[], int size){
    for(int i=1; i<size; i++){
        int key = array[i];
        int j = i-1;
        while(j>=0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
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
    insertionSort(array, size);
    printElements(array, size);
    return 0;
}