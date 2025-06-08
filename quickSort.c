#include <stdio.h>

void swap(int* a, int* b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void quickSort(int arrray[], int low, int high){

}

void showElements(int array[], int size){
    for(int i=0; i<size; i++){
        printf("%d, ", array[i]);
    }
}

int main(){
    int array[] = {3, 5, 2, 13, 12};
    int size = 5;
    quickSort(array, size);

    return 0;
}