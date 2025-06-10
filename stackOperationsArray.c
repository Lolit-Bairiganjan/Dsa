#include <stdio.h>

#define MAX 100

int Stack[MAX];
int top = -1;

int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

int isFull(){
    if(top==MAX-1){
        return 1;
    }
    return 0;
}

void push(int data){
    if(isFull()){
        printf("Stack overflow!\n");
        return;
    }
    Stack[++top] = data;
    printf("Pushed: %d\n", data);
}

int pop(){
    if(isEmpty()){
        printf("Stack Underflow!\n");
        return -1;
    }
    int popped = Stack[top--];
    printf("Popped: %d\n", popped);
    return popped;
}

void peek(){
    if(isEmpty()){
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", Stack[top]);
}

int main(){
    push(10);
    push(20);
    push(30);
    peek();         // Should print 30
    pop();          // Should remove 30
    peek();         // Should print 20
    pop();          // Should remove 20
    pop();          // Should remove 10
    pop();          // Should print underflow message
    peek();         // Should print stack is empty
    return 0;
}