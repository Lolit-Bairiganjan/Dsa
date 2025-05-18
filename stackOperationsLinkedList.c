#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int isEmpty(struct Node* head){
    if(head==NULL){
        return 1;
    }
    return 0;
}

int isFull(struct Node* head){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        return 1;
    }
    free(newNode);
    return 0;
}

int main(){
    struct Node* stack = (struct Node*)malloc(sizeof(struct Node));
    stack->data = 10;
    stack->next = (struct Node*)malloc(sizeof(struct Node));
    stack->next->data = 20;
    stack->next->next = NULL;

    printf("%d\n", isEmpty(stack));
    printf("%d\n", isFull(stack));
}