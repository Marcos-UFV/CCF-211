#include <stdlib.h>
#include <stdio.h>
void alocaEPreenche(int** v,int n){
    (*v) = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf(" %d",&temp);
        *(*(v) + i) = temp;
    }
    
}
void imprimeVetor(int* v,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(v + i));
    }
    printf("\n");
    
}