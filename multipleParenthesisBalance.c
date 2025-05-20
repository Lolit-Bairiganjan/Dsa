#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char data;
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

int push(struct Node** head, char data){
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

char pop(struct Node** head){
    if(isEmpty(*head)){
        printf("Stack Underflow\n");
        return '\0';
    }
    else{
        struct Node* temp = *head;
        char popped = temp->data;
        *head = (*head)->next;
        free(temp);
        return popped;
    }
}

int parenthesisMatching(char open, char close){
    if(
        (open=='(' && close==')')||
        (open=='{' && close=='}')||
        (open=='['&& close==']')
    ){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    struct Node* stack = NULL;
    char expression[50];
    printf("Enter your mathematical expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';
    printf("Your mathematical expression is: %s\n", expression);
    for(int i=0; expression[i]!='\0'; i++){
        if(expression[i]=='('||expression[i]=='{'||expression[i]=='['){
            push(&stack, expression[i]);
        }
        else if (expression[i]==')'||expression[i]=='}'||expression[i]==']'){
            if(isEmpty(stack)){
                printf("Parenthesis Not Balanced!\n");
                return -1;
            }
            char popped_char = pop(&stack);
            if(!parenthesisMatching(popped_char, expression[i])){
                printf("Parenthesis Not Balanced!\n");
                return -1;
            }
        }
        
    }
    if(isEmpty(stack)){
        printf("Parenthesis Balanced!\n");
        return 0;
    }
    else{
        printf("Parenthesis Not Balanced!\n");
        return -1;
    }
}