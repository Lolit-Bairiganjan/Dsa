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

int isOperator(char toCheck){
    if(toCheck=='+'||toCheck=='-'||toCheck=='*'||toCheck=='/'||toCheck=='('||toCheck==')'){
        return 1;
    }
    return 0;
}

int precedance(char operator){
    if(operator=='*'||operator=='/'){
        return 2;
    }
    else if(operator=='+'||operator=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    struct Node* stack = NULL;

    char infixExpression[50];
    char postfixExpression[50];

    printf("Enter your infix expression: ");
    fgets(infixExpression, sizeof(infixExpression), stdin);
    infixExpression[strcspn(infixExpression, "\n")] = '\0';

    int postfixIndex = 0;

    for(int i=0; infixExpression[i]!='\0'; i++){
        if(!isOperator(infixExpression[i])){
            postfixExpression[postfixIndex] = infixExpression[i];
            postfixIndex++;
        }
        else if(infixExpression[i]=='('){
            push(&stack, infixExpression[i]);
        }
        else if(infixExpression[i]==')'){
            while(!isEmpty(stack)&&stack->data!='('){
                postfixExpression[postfixIndex++] = pop(&stack);
            }
            pop(&stack);
        }
        else{
            if(isEmpty(stack)){
                push(&stack, infixExpression[i]);
            }
            else{
                while(!isEmpty(stack) && stack->data != '(' && precedance(stack->data) >= precedance(infixExpression[i])){
                    postfixExpression[postfixIndex++] = pop(&stack);
                }
                push(&stack, infixExpression[i]);
            }
        }
    }
    while(!isEmpty(stack)){
        postfixExpression[postfixIndex++] = pop(&stack);
    }
    postfixExpression[postfixIndex] = '\0';

    printf("The infix expression is: %s\n", infixExpression);
    printf("The postfix expression is: %s\n", postfixExpression);
}