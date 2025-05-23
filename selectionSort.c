#include <stdio.h>

void selectionSort(int array[], int size){
    for(int i=0; i<size; i++){
        int smallest = array[i];
        int k = i;
        for(int j=i+1; j<size; j++){
            if(array[j]<smallest){
                smallest = array[j];
                k = j;
            }
        }
        int temp = array[i];
        array[i] = array[k];
        array[k] = temp;
    }
}

void showElements(int array[], int size){
    for(int i=0; i<size; i++){
        printf("%d, ", array[i]);
    }
}

int main(){
    int array[5] = {5, 4, 3, 2, 1};
    int size = sizeof(array)/sizeof(int);
    selectionSort(array, size);
    showElements(array, size);
}