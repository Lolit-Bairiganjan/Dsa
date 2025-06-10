#include <stdio.h>

#define SIZE 100

int queue[SIZE];
int rear = -1;
int front = -1;

void enqueue(int data){
    if(rear==SIZE - 1){
        printf("Queue is full!\n");
        return;
    }
    if(front==-1){
        front = 0;
    }
    queue[++rear] = data;
    printf("Inserted value: %d\n", data);

}

void dequeue(){
    if(front==-1||front>rear){
        printf("Queue is empty!\n");
        return;
    }
    printf("Deleted value: %d\n", queue[front]);
    front++;
}

void display(){
    if(front==-1||front>rear){
        printf("Queue is empty!\n");
        return;
    }
    for(int i=front; i<=rear; i++){
        printf("%d, ", queue[i]);
    }
    printf("\n");
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}