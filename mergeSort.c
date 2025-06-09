#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int low, int mid, int high){
    int i, j, k;
    int n1 = mid-low+1;
    int n2 = high-mid;

    int *L = (int*)malloc(sizeof(int)*n1);
    int *R = (int *)malloc(n2 * sizeof(int));
    
    for(int i=0; i<n1; i++){
        L[i] = array[low+i];
    }
    for(int j=0; j<n2; j++){
        R[j] = array[mid+1+j];
    }

    i = j = 0;
    k = low;

    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            array[k++] = L[i++];
        }
        else{
            array[k++] = R[j++];
        }
    }
    while(i < n1){
        array[k++] = L[i++];
    }
    while(j < n2){
        array[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(int array[], int low, int high){
    if(low<high){
        int mid = low + (high-low)/2;

        mergeSort(array, low, mid);
        mergeSort(array, mid+1, high);

        merge(array, low, mid, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:   ");
    printArray(arr, n);

    return 0;
}