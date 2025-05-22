#include <stdio.h>

void bubbleSort(int array[], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<(size-i-1); j++){
            if(array[j]>array[j+1]){
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printElements(int array[], int size){
    for(int i=0; i<size; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int main(){
    int array[5] = {2, 1, 5, 11, 9};
    int size = (sizeof(array)/sizeof(int));
    bubbleSort(array, size);
    printElements(array, size);
    return 0;
}