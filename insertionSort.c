#include <stdio.h>
#include <time.h>

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
    clock_t start, end;
    int array[100000];
    for(int i=0; i<100000; i++){
        array[i] = 100000-i;
    }
    int size = (sizeof(array)/sizeof(int));
    start = clock();
    insertionSort(array, size);
    end = clock();
    printElements(array, size);
    printf("Shifting time: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}