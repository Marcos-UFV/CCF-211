#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int n;
    struct Node* nextC;
}Node;
Node* top = NULL;
void Push(int n){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->n = n;
    temp->nextC = top;
    top = temp;
}
void Pop(){
    Node* temp = top;
    top = temp->nextC;
    free(temp);
}
int Top(){
    return top->n;
}
void Print(){
    Node* temp = top;
    printf("Stack: ");
    while(temp != NULL){
        printf("%d ",temp->n);
        temp = temp->nextC;
    }
    printf("\n");
}
int IsOperator(int n){
    return (n == '+' || n == '-'||n == '*' || n == '/');
}
int IsNumericDigit(char c){
    return (c >= '0' && c <= '9');
}
int Perform(char op,int op1,int op2){
    switch (op){
        case '+':return op1+op2;break;
        case '-':return op1-op2;break;
        case '*':return op1*op2;break;
        case '/':return op1/op2;break;    
        default:break;
    }
}
int EvaluetePostfix(char* exp,int n){
    
    for (int i = 0; i < n; i++)
    {
        
        if(*(exp + i) == ' ' || *(exp + i) == ',' ) continue;

        if(IsOperator(*(exp + i))){
            int op1 = Top();Pop();
            int op2 = Top();Pop();
            int res = Perform(*(exp + i),op2,op1);
            Push(res);
            Print();
        }else if(IsNumericDigit(*(exp + i))){
            //int operand = (*(exp + i) - '0');
            int operand = 0;
            while(i < n && IsNumericDigit(*(exp + i))){
                operand = (operand*10) + (*(exp + i) - '0');
                i++;
            }
            i--;
            Push(operand);
            Print();
        }
    }
    return Top();
    
}
int main(){
    char expression[100];
    int count = -1;
    int res;
    printf("Enter an expression: ");
    scanf(" %[^\n]",expression);
    
    while(expression[++count] != '\0');

    
    res = EvaluetePostfix(expression,count);
    printf("%d\n",res);
}