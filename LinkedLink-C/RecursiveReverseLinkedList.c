#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head;

void Reverse(struct Node* p){
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    Reverse(p->next);
    Node* q = p->next; //p->next->next = p;
    q->next = p;
    p->next = NULL;    
}
void Insert(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp-> next = NULL;
    if(head == NULL){
        head = temp;
        return;
    } 
    Node* temp1 = head;
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
}
void Print(){
    Node* p = head;
    printf("List: ");
    while (p != NULL){
        printf(" %d",p->data);
        p = p->next;
    }
    printf("\n");    
}
int main(){
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Print();
    Reverse(head);
    Print();
}