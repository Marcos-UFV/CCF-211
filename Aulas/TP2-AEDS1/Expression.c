#include "Expression.h"
#include <stdio.h>
#include <stdlib.h>

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