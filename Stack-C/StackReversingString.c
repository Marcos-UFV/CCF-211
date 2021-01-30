#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    char letter;
    struct Node* nextLetter;
}Node;
Node* top = NULL;
void Push(char l){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->letter = l;
    temp->nextLetter = top;
    top = temp;
}
void Pop(){
    Node* temp = top;
    top = temp->nextLetter;
    free(temp);
}
char Top(){
    if(top != NULL) return top->letter;
}
int main(){
    char Name[100];
    printf("Enter a string: ");
    scanf(" %[^\n]",Name);
    int i = 0;
    while (Name[i] != '\0')
    {
        Push(Name[i++]);        
    }
    i = 0;
    printf("Output = ");
    while (Name[i] != '\0')
    {
        printf("%c",Top());
        i++;
        Pop();
    }
    printf("\n");    
    
}