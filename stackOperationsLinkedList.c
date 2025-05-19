#include <stdio.h>
#include <stdlib.h>

//stackTop, peek(), and stackBottom operations are not added becoz they're really easy. So I didn't really put time to code them.

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

struct Node* pop(struct Node** head){
    if(isEmpty(*head)){
        printf("Stack Underflow\n");
        return NULL;
    }
    else{
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return *head;
    }
}

int main(){
    struct Node* stack = NULL;

    printf("%d\n", isEmpty(stack));
    printf("%d\n", isFull());
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("%d\n", isEmpty(stack));
    pop(&stack);
    pop(&stack);
    pop(&stack);
    printf("%d\n", isEmpty(stack));
}