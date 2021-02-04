#include <stdio.h>
typedef struct E{
    int N1,N2,D1,D2;
    char OP;
    int num;
    int den;
}E;
int IsNumericDigit(char c){
    return (c >= '0' && c <= '9');
}
int IsOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
void Operations(E* e){
    int N1,N2,D1,D2,num,den;
    N1 = e->N1;
    N2 = e->N2;
    D1 = e->D1;
    D2 = e->D2;
    switch (e->OP)
    {
        case '+':num = (N1*D2 + N2*D1);den =(D1*D2); break;
        case '-':num = (N1*D2 - N2*D1);den =(D1*D2); break;
        case '*':num = (N1*N2);den =(D1*D2);  break;
        case '/':num =(N1*D2);den = (N2*D1);  break;
    
    }
    e->num = num;
    e->den = den;
}

void AssignValues(char* exp,int N,E* e ){
    int x = 0,i=0;
    int values[4];
    for(int i = 0; i < N;i++)
    {
        if(i <= N/2 && IsOperator(*(exp + i)))
            e->OP = *(exp + i);
        if(IsNumericDigit(*(exp + i))){
            int num =0;
            while(i < N && IsNumericDigit(*(exp + i))){
                num = (num*10) + *(exp + i) - '0';
                i++;
            }
            values[x++] = num;
        }
            
        
    }
    e->N1 = values[0];
    e->D1 = values[1];
    e->N2 = values[2];
    e->D2 = values[3];
}
void FormatData(E* e){
    int num,den,maior;
    num = e->num;
    den = e->den;
    maior = num > den?num:den;
    int i = 2;
    for(i = 2; i < maior;i++){
        if(num % i == 0 && den % i == 0){
            num = num/i;
            den = den/i;
        }            
    }
    printf("%d/%d = %d/%d\n",e->num,e->den,num,den);
}
int main(){
    int N;
    while (scanf("%d",&N))
    {
        for(int i = 0;i < N;i++){
            int length = -1;
            E e;
            char exp[1000];
            scanf(" %[^\n]",exp);
            
            while(exp[++length] != '\0');

            AssignValues(exp,length,&e);
            Operations(&e);

            FormatData(&e);
        }       
    }    
}