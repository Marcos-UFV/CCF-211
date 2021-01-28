#include <stdlib.h>
#include <stdio.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

void Print(Node* p){
    if(p == NULL){
        printf("\n");
        return; //Exit recursion
    } 
    printf("%d ",p->data); // First print the value in the node
    Print(p->next); // Recursive call
}
void ReversePrint(Node* p){
    if (p == NULL) return;
    ReversePrint(p->next);
    printf("%d ",p->data);    
}


Node* Insert(Node* head,int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL) head = temp;
    else
    {
        Node* temp1 = head;
        while(temp1->next != NULL) temp1 = temp1->next;
        temp1->next = temp;
    }
    return head;    
}
int main(){
    Node* head = NULL;
    head = Insert(head,1);
    head = Insert(head,2);
    head = Insert(head,3);
    head = Insert(head,4);
    
    Print(head);
    ReversePrint(head);
    printf("\n");

    
    

}