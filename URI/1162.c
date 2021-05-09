#include <stdio.h>
int main(){
    int N = 0,L = 0,S,aux;
    int i,j,k;
    int V[50];   
    
    
    scanf(" %d",&N);
    for ( i = 0; i < N; i++)
    {
        scanf(" %d",&L);
        printf("Passou1!\n");
        for(j = 0;j< L;j++){
            scanf("%d",&V[j]);
            printf("Passou2!");
        }
        printf("Passou3!");  
        S = 0;
        for (j = 1; j < L; j++)
        {
           aux = V[i];
           j = i -1;
           while(j >= 0 && aux < V[j]){
               V[j + 1] = V[j];
               S++; 
               j--;
           }
           V[j + 1] = aux;           
        }
        printf("Optimal train swapping takes %d swaps.\n",S);   
    }    
}