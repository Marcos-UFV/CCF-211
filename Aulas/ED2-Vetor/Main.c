#include "Vetor.h"
#include <stdio.h>
int main(){
    int *v,n;
    printf("Entre com o tamanho do vetor: \n");
    scanf(" %d",&n);
    alocaEPreenche(&v,n);
    imprimeVetor(v);
   for (int i = 0; i < n; i++)
   {
       printf("%d",v[i]);
   }
   printf("\n");
   
}