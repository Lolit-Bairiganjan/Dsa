#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void deleteFromBeginning(struct Node** head){
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromIndex(struct Node** head, int index){
    if(index==0){
        deleteFromBeginning(head);
        return;
    }
    int counter = 1;
    struct Node* cursor = *head;
    while(counter<index){
        cursor = cursor->next;
        counter++;
    }
    struct Node* nodeDelete = cursor->next;
    struct Node* nextNode = cursor->next->next;
    cursor->next = nextNode;
    free(nodeDelete);

}

int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = NULL;

    deleteFromIndex(&head, 1);
    printf("%d\n", head->data);
}