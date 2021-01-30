#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* head;
void Insert(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}
void Remove(){
    Node* temp = head;
    head = temp->next;
    free(temp);
}
void Print(){
    printf("List: ");
    Node* temp = head;
    while (temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");    
}
int main(){
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Print();
    Remove();
    Print();
}