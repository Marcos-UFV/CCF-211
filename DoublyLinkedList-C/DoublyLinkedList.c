#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* head;
Node* getNewNode(int x){
    Node* newNodePtr = (Node*)malloc(sizeof(Node));
    newNodePtr->data = x;
    newNodePtr->next = NULL;
    newNodePtr->prev = NULL;
    return newNodePtr;
}
void InsertAtHead(int x){
    Node* newNode = getNewNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode; 
    
}
void Print(){
    printf("List: ");
    Node* p = head;
    while (p != NULL){
       printf(" %d",p->data);
       p = p->next;
    }
    printf("\n");    
}
void ReversePrint(){
    Node* temp = head;
    if(temp == NULL) return; // empty list, exit
    // Going to last Node
    while(temp->next != NULL) temp = temp->next;
    // Traversing backward using prev pointer
    printf("Reverse: ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}       
int main(){
    head = NULL;
    InsertAtHead(1);
    InsertAtHead(2);
    InsertAtHead(3);
    InsertAtHead(4);
    InsertAtHead(5);
    Print();
    ReversePrint();
}