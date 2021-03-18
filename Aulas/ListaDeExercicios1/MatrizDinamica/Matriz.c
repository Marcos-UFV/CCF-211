#include <stdlib.h>
#include <stdio.h>
int i = 0;
struct celula{
    int x;
    struct celula *pProx;
};
typedef struct{
    struct celula *primeira,*ultima;
}Linha;

void criaCelulas(Linha *pLinha,int nCel){
    pLinha->ultima->pProx = (struct celula*)malloc(sizeof(struct celula));
    pLinha->ultima = pLinha->ultima->pProx;
    pLinha->ultima->x = i;
    pLinha->ultima->pProx = NULL;
    while(--nCel != 0)
        criaCelulas(pLinha,nCel);
}
void criaLinha(Linha **matriz,int n){
    matriz[i]->primeira = (struct celula*)malloc(sizeof(struct celula));
    matriz[i]->ultima = matriz[i]->primeira;
    matriz[i]->primeira->pProx = NULL;
    criaCelulas(matriz[i],n);
    i++;    
}
void imprimeMatriz(Linha **matriz,int m){
    Linha **aux = matriz;
    for(i = 0;i < m; i++){
        struct celula *cAux = aux[i]->primeira->pProx;
        while (cAux != NULL)
        {
            printf("%d ",cAux->x);
        }
        printf("\n");        
    }
}
int main(){
    Linha **matriz;
    int m,n;
    m = 5;
    n = 5;
    criaLinha(matriz,n);
    criaLinha(matriz,n);
    criaLinha(matriz,n);
    criaLinha(matriz,n);
    criaLinha(matriz,n);
    imprimeMatriz(matriz,m);
}