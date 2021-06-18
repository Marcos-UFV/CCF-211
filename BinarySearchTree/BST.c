#include <stdlib.h>
#include <stdio.h>
typedef struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
}BstNode;
BstNode* getNewNode(int data){
    BstNode* newNode = (BstNode*)malloc(sizeof(BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}   
BstNode* insert(BstNode* root,int data){
    if(root == NULL){ // empty tree
        root = getNewNode(data);
    }else if(data <= root->data){
        root->left = insert(root->left,data);
    }else{
        root->right = insert(root->right,data);
    }
    return root;
}
int search(BstNode* root,int data){
    if(root == NULL) return 0;
    else if(root->data == data) return 1;
    else if(data <= root->data) return search(root->left,data);
    else return search(root->right,data);
}
int main(){
    int number;
    BstNode* root = NULL; // Creating an empty tree
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,8);
    root = insert(root,12);
    printf("Enter number be searched\n");
    scanf(" %d",&number);
    if(search(root,number)) printf("Found\n");
    else printf("Not Found\n");

}