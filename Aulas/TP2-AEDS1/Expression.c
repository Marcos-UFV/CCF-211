#include "Expression.h"
#include <stdio.h>
#include <stdlib.h>
Table T;
void AsksForNUmberOfClausesAndVariables(Expression *E){
    int c,n;
    printf("Entre com o Número de Cláusulas e Variáveis:");
    printf("\nC = ");
    scanf(" %d",&c);
    printf("\nN = ");
    scanf(" %d",&n);
    E->C = c;
    E->N = n;
    CreateMatrix(E);
}
void CreateMatrix(Expression *E){
    int i,j;
    E->matriz = (int **)malloc(E->C*sizeof(int *));
    for (i = 0; i < E->C; i++)
    {
        E->matriz[i] = (int *)malloc(E->N*sizeof(int));
        for (j = 0; j < E->N; j++)
        {
            E->matriz[i][j] = 0;
        }        
    }    
}
// Cláusula 1,2 3,1 4,2
void AsksForTheFormatOfTheClauses(Expression *E){
    int i;
    char c[12];
    printf("Entre com as cláusulas  da expressão:");
    for (i = 0; i < E->C; i++)
    {
        printf("\nC%d = ",(i+1));
        scanf(" %[^\n]",c);
        FillsClauses(E,c,i);
    }
    //Cria a tabela verdade de acordo com o número de variáveis
    CreateTable(&T,E->N);
    FillsTable(&T);
    PrintTable(&T);    
}
void FillsClauses(Expression *E,char *C,int L){
    int i = 0;
    int column = 0;
    int value = 0;
    while (*(C + i) != '\0')
    {
        if (IsNumericDigit(*(C + i)))
        {
           column = (*(C + i) - '0') - 1;
           value =  (*(C + i + 2) - '0');
           E->matriz[L][column] = value;
           i = i+2;
        }
        i++;        
    }    
}


int IsNumericDigit(char c){
    return (c >= '0' && c <= '9');
}
void printMatriz(Expression *E){
    printf("C = %d\nN =%d\n",E->C,E->N);
    int i,j;
    for (int i = 0; i < E->C; i++)
    {
        for (j = 0; j < E->N; j++)
        {
            printf("%d ",E->matriz[i][j]);
        }
        printf("\n");
    }    
}
void AsksForNumberOfVariables(Expression *E){
    int n,c;
    printf("Informe o número de variáveis: ");
    printf("\nN = ");
    scanf(" %d",&n);
    c = (2*n)/3;
    E->C = c;
    E->N = n;
    CreateMatrix(E);
    FillsMatrix(E);
    //Cria a tabela verdade de acordo com o número de variáveis
    CreateTable(&T,n);
    FillsTable(&T);
}
//TEM UM BUG AQUI. Está fazendo a iteração mais interna mais de 3 vezes.
void FillsMatrix(Expression *E){
    int i,j,p,v;
    for (i = 0; i < E->C; i++)
    {
        for (j = 0; j < 3; j++)
        {
          p = (rand() % (E->N));
          v = (rand() % 2) +1;  
          E->matriz[i][p] = v;   
        }        
    }    
}
void EvalueteExpression(Expression *E){
    int i,j,k,l,flag;
    int* Exp = (int *)malloc(E->C*sizeof(int));
    printf("A Expressão é verdadeira para a(s) seguinte(s) combinação(ões):\n");
    for (i = 0; i < T.L; i++)
    {
        for (j = 0; j < E->C; j++)
        {
            Exp[j] = 0;
            for (k = 0; k < E->N; k++)
            {
                if(E->matriz[j][k]){
                    if(T.matriz[i][k] == E->matriz[j][k]){
                        Exp[j] = 1;
                        break;
                    }
                }
            }
            
        }
        flag = 1;
        for (l = 0; l < E->C; l++)
        {
            if(!Exp[l])
                flag = 0;
        }
        if(flag)
            PrintTableLine(&T,i);         
    }    
}