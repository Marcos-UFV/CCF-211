#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char c;
    struct Node* nextC;
}Node;
Node* top = NULL;
void Push(char c){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->c = c;
    temp->nextC = top;
    top = temp;
}
int IsEmpty(){
    return (top == NULL);
}
void Pop(){
    if(IsEmpty()) return;
    Node* temp = top;
    top = temp->nextC;
    free(temp);
}
char Top(){
    return top->c;
}
void Print(){
    Node* temp = top;
    printf("List: ");
    while(temp != NULL){
        printf("%c ",temp->c);
        temp = temp->nextC;
    }
    printf("\n");
}
int ArePair(char opening,char closing){
    if(opening == '(' && closing == ')') return 1;
    else if(opening == '{' && closing == '}') return 1;
    else if(opening == '[' && closing == ']') return 1;
    else return 0;
}
int AreParenthesesBalanced(char* exp,int n){
    for(int i=0;i < n;i++){
        if(*(exp + i) == '(' || *(exp + i) == '{' || *(exp + i) == '[')
            Push(*(exp + i));
        else if(*(exp + i) == ')' || *(exp + i) == '}' || *(exp + i) == ']' ){
            if(IsEmpty() || !ArePair(Top(),*(exp + i)))
                return 0;
            else
                Pop();
        }
    }
    return IsEmpty();
}
int main(){
   int count = -1;
   char expression[100];
   printf("Enter an expression: ");
   scanf(" %[^\n]",expression);
   while (expression[++count] != '\0');
    
    
   if(AreParenthesesBalanced(expression,count))
    printf("Balanced\n");
   else
    printf("Not balanced\n");
   
}