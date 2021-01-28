#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* Reverse(Node* head){
    Node *current,*prev,*next;
    current = head;
    prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
/*
Node* Insert(Node* head,int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}*/
Node* Insert(Node* head,int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL) head = temp;
    else {
        Node* temp1 = head;
        while (temp1->next != NULL) temp1 = temp1->next;
        temp1->next = temp;        
    }
    return head;
}
void Print(Node* head){
    printf("List: ");
    while(head != NULL){
        printf(" %d",head->data);
        head = head->next;
    }
    printf("\n");

}
int main(){
    Node* head = NULL; // Local variable
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,8);
    Print(head);
    head = Reverse(head);
    Print(head);

}