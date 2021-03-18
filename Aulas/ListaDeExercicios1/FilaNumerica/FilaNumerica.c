#include <stdio.h>
#include <stdlib.h>
struct item{
    int num;
    struct item* pProx;
};
typedef struct{
    struct item *frente,*tras;
}TFila;

void FFVazia(TFila *pFila){
    pFila->frente = (struct item*)malloc(sizeof(struct item));
    pFila->tras = pFila->frente;
    pFila->frente->pProx = NULL;
}
void FEnfileira(TFila *pFila,int item){
    pFila->tras->pProx = (struct item*)malloc(sizeof(struct item));
    pFila->tras = pFila->tras->pProx;
    pFila->tras->num = item;
    pFila->tras->pProx = NULL;
}
int FVazia(TFila *pFila){
    return pFila->frente == pFila->tras;
}
void FDesenfileira(TFila *pFila,int *item){
    struct item *aux; 
    if(FVazia(pFila)) printf("Underflow\n");
    else{
        aux = pFila->frente;
        pFila->frente = pFila->frente->pProx;
        (*item) = pFila->frente->num;
        free(aux);
    }
}
int main(){
    TFila minha_fila;
    FFVazia(&minha_fila);
    for(int i=1;i <=5;i++)
        FEnfileira(&minha_fila,i);
    for(int i=0;i<5;i++){
        int num;
        FDesenfileira(&minha_fila,&num);
        printf("Valor desenfileirado: %d\n",num);
    }   

}