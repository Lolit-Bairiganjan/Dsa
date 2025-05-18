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

int isFull(){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        return 1;
    }
    free(newNode);
    return 0;
}

int push(struct Node** head, int data){
    if(isFull()){
        printf("Stack Overflow\n");
        return -1;
    }
    struct Node* temp = *head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp;
    *head = newNode;
    return 0;
}

int pop(struct Node** head){
    if(isEmpty(*head)){
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return 0;
}

int main(){
    struct Node* stack = NULL;

    printf("%d\n", isEmpty(stack));
    printf("%d\n", isFull());
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("%d\n", isEmpty(stack));
}