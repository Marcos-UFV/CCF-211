#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char c;
    struct Node* next;
}Node;

Node* top = NULL;
void Push(char c){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->c = c;
    temp->next = top;
    top = temp;
}
char Top(){
    return top->c;
}
void Pop(){
    Node* temp = top;
    top = temp->next;
    free(temp);    
}
void Print(){
    Node* temp = top;
    printf("Stack: ");
    while(temp != NULL){
        printf("%c",temp->c);
        temp = temp->next;
    }
    printf("\n");
}
// Function to verify whether an operator is right associative or not
int IsRightAssociative(char op){
    return (op == '$');
}
//Function to get weight of an operator, An operator with higher weight will have higher precedence
int GetOperatorWeight(char op){
    int weight = -1;
    switch (op){
    case '+':
    case '-': 
            weight = 1;break;
    case '*':
    case '/': 
            weight = 2;break;
    case '^':
            weight = 3;break;
    
    }
    return weight;
}
//Function to perform an operation and return output
int HasHigherPrecedence(char op1,char op2){
    
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);

    // If operators have equal precedence, return true if they are left associative
    // return false, if right associative.
    // if operator is left-associative, left one should be given priority
    if(op1Weight == op2Weight){
        if(IsRightAssociative(op1)) return 0;
        else return 1;
    }
    return op1Weight > op2Weight;
}
int IsOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/'|| c == '^');
}
int IsOperand(char c){
    return (c >= '0' && c <= '9');
}
int IsEmpty(){
    return (top == NULL);
}
//Function to evaluate Postfix expression and return output
void InfixToPostfix(char* exp,int length){
    char postfix[length];
    int n= 0;
    for(int i =0;i < length;i++){
        // Scanning each character from left.
        //If character is a delimiter, move on.
        if(*(exp + i) == ' ' || *(exp + i) == ',') continue;

        //If character is operator, pop two elements from stack, perform operation anad push the result back.
        else if(IsOperator(*(exp + i))){
            
            while(!IsEmpty() && HasHigherPrecedence(Top(),*(exp + i))){
                postfix[n] = Top();
                Pop();
                n++;
            }
            Push(*(exp + i));
        }
        // Else if character is an operanad
        else if(IsOperand(*(exp + i))){
            postfix[n] = *(exp + i);
            n++;
        }
    }
    while(!IsEmpty()){
        postfix[n] = Top();
        Pop();
        n++;
    }
    for(int i= 0;i < length;i++){
        *(exp + i) = postfix[i];
    }
}
int main(){
   char infix[100];
   int length = -1;
   printf("Enter Infix Expression: ");
   scanf("%[^\n]",infix);
   while(infix[++length] != '\0');

   InfixToPostfix(infix,length);
   for(int i = 0; i < length;i++){
       printf("%c",infix[i]);
   }
   printf("\n");
   

   
}