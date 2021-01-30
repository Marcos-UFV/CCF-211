#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* top = NULL;
void Push(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = top;
    top = temp;
}
void Pop(){
    Node* temp = top;
    if(temp == NULL) return;
    top = temp->next;
    free(temp);
}
void Print(){
    printf("List: ");
    Node* temp = top;
    while (temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");    
}
int main(){
    Push(1);
    Push(2);
    Push(3);
    Push(4);
    Print();
    Pop();
    Print();
}