#include <stdio.h>

void swap(int* a, int* b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

int partition(int array[], int low, int high){
    int i = low + 1;
    int j = high;
    int pivot = array[low];
    while(i <= j){
        while(i <= high && array[i] <= pivot){
            i++;
        }
        while(j >= low && array[j] > pivot){
            j--;
        }
        if(i < j){
            swap(&array[i], &array[j]);
            // Move pointers after swap
            i++;
            j--;
        }
    }
    swap(&array[low], &array[j]);
    return j;
}

void quickSort(int array[], int low, int high){
    if(low < high){
        int partitionIndex = partition(array, low, high);
        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}

void showElements(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int main(){
    int array[] = {3, 5, 2, 13, 12};
    int size = 5;
    quickSort(array, 0, size - 1);
    showElements(array, size);
    return 0;
}