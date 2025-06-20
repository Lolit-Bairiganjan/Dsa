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

void inOrder(struct Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    if(prev>root->key){
        printf("Not a binary search tree!\n");
        return;
    }
    printf("%d, ", root->key);
    inOrder(root->right);
}

int main() {
    struct Node* root = createNode(4);
    struct Node* p1 = createNode(1);
    struct Node* p2 = createNode(6);
    root->left = p1;
    root->right = p2;
    struct Node* p1_1 = createNode(5);
    struct Node* p1_2 = createNode(2);
    p1->left = p1_1;
    p1->right = p1_2;
    inOrder(root);
    return 0;
}