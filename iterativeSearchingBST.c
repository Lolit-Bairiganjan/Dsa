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

int searchBST(struct Node* root, int data){
    if(root == NULL) return 0;
    struct Node* temp = root;
    while(temp!=NULL){
        if(temp->key==data) return 1;
        else if(data>temp->key){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    return 0;
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
    if(searchBST(root, 70)){
        printf("Key Found! :)\n");
    }
    else{
        printf("Not Found! :(\n");
    }
    return 0;
}