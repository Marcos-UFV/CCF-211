#include <stdlib.h>
#include <stdio.h>
typedef struct Node{
    int data;
    struct Node* next;
} Node;

void Insert(Node**,int);
void Print(Node*);
int main(){
    Node* head = NULL;
    printf("How many numbers?\n");
    int n,i,x;
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        printf("Enter the number \n");
        scanf("%d",&x);
        Insert(&head,x);
        Print(head);
    }
}
void Insert(Node** pointerToHead,int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = (*pointerToHead);
    (*pointerToHead) = temp;
}
void Print(Node* head){
    printf("List is: ");
    while (head != NULL)
    {
        printf(" %d",head->data);
        head = head->next;
    }
    printf("\n");
    
}
