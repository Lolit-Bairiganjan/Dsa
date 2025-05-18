#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* head){
    struct Node* ptr = head;
    while(ptr->next!=head){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}

int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (struct Node*)malloc(sizeof(struct Node));

    head->next->data = 20;
    head->next->next = head;
    linkedListTraversal(head);
}