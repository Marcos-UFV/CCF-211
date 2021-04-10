#include "TruthTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void CreateTable(Table *T,int N){
    int i,j;
    T->L = (int) pow(2,N);
    T->C = N;
    T->matriz = (int **)malloc(T->L*sizeof(int *));
    for (i = 0; i < T->L; i++)
    {
        T->matriz[i] = (int *)malloc(T->C*sizeof(int));
        for (j = 0; j < T->C; j++)
        {
            T->matriz[i][j] = 0;
        }        
    }   
}
void FillsTable(Table *T){
    int i,j,lenght,mod,value;
    lenght = T->L;
    value = -1;
    mod = lenght/2;
    for (i = 0; i < T->C; i++)
    {       
        for (j = 0; j < T->L; j++)
        {
            if(j % mod == 0)
                value *= -1;  
            T->matriz[j][i] = value > 0?1:2;   
        }
        mod = mod/2;         
    } 
}
void PrintTable(Table *T){
    int i,j;
    for (i = 0; i < T->L; i++)
    {
        for (j = 0; j < T->C ; j++)
        {
            printf("%d ",T->matriz[i][j]);
        }
        printf("\n");        
    }    
}
void PrintTableLine(Table *T,int L){
    int i;
    for (i = 0; i < T->C; i++)
    {
        printf("%d ",T->matriz[L][i]);
    }
    printf("\n");    
}