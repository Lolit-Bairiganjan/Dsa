#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->key = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int main() {
    struct Node* root = createNode(10);
    printf("%d", root->key);
    return 0;
}