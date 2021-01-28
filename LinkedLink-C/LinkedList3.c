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
void Print(){
    Node* temp = head;
    while (temp != NULL){
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Delete(int n){
    Node* temp1 = head;
    if(n == 1){
        head = temp1->next; // head now points to second node.
        free(temp1);
        return;
    }
    int i;
    for(i = 0;i<n-2;i++)
        temp1 = temp1->next;
    // temp1 points to (n -1)th Node
    Node* temp2 = temp1->next; //nthNode
    temp1->next = temp2->next; //(n+1)th Node
    free(temp2); //delte temp2;
}
int main(){
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print();
    int n;
    printf("Enter a position\n");
    scanf("%d",&n);
    Delete(n);
    Print();
}