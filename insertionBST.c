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

struct Node* insertionBST(struct Node* root, int data){
    if(root == NULL) return createNode(data);
    struct Node* parent = NULL;
    struct Node* current = root;
    while(current!=NULL){
        parent = current;
        if(data>current->key){
            current = current->right;
        }
        else if(data<current->key){
            current = current->left;
        }
        else{
            printf("Data already exists!\n");
            return root;
        }
    }
    if(data > parent->key){
        parent->right = createNode(data);
    }
    else{
        parent->left = createNode(data);
    }
    return root;
}

int main() {
    struct Node* root = createNode(50);
    struct Node* p1 = createNode(40);
    struct Node* p2 = createNode(60);
    struct Node* p1_1 = createNode(20);
    struct Node* p1_2 = createNode(45);
    struct Node* p2_1 = createNode(55);
    struct Node* p2_2 = createNode(70);
    root->left = p1;
    root->right = p2;
    p1->left = p1_1;
    p1->right = p1_2;
    p2->left = p2_1;
    p2->right = p2_2;
    insertionBST(root, 75);
    return 0;
}