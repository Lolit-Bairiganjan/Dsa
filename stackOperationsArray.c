#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int *stack;
};

int isEmpty(struct Stack* ptr){
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}

int isFull(struct Stack* ptr){
    if(ptr->top==(ptr->size)-1){
        return 1;
    }
    return 0;
}

int push(struct Stack* ptr, int value){
    if(isFull(ptr)){
        printf("Stack Overflow\n");
    }
    else{
        ptr->stack[++(ptr->top)] = value;
    }
}

int pop(struct Stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
    }
    else{
        return (ptr->stack[(ptr->top)--]);
    }
}

int peek(struct Stack* ptr, int position){
    if(isEmpty(ptr)){
        printf("Stack Empty\n");
        return -1;
    }
    else{
        if(position-1>ptr->top){
            printf("Index not accessible\n");
            return -1;
        }
        printf("The element is: %d\n", ptr->stack[position-1]);
    }
}

int main() {
    struct Stack* stack1 = (struct Stack*)malloc(sizeof(struct Stack));
    stack1->size = 2;
    stack1->top = -1;
    stack1->stack = (int*)malloc(sizeof(int)*stack1->size);

    push(stack1, 10);
    push(stack1, 20);
    push(stack1, 30);
    peek(stack1, 1);
    peek(stack1, 3);
}
