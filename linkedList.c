#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* head){
    struct Node* current = head;
    while(current != NULL){
        printf("Data: %d\n", current->data);
        current = current->next;
    }
}

int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;
    linkedListTraversal(head);
    free(head);
}