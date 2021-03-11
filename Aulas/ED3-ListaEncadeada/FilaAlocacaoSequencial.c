#include <stdio.h>
typedef struct{
    int itens[5];
    int frente,tras;
}TFila;

void FFVazia(TFila *pFila){
    pFila->frente = 0;
    pFila->tras = 0;
}
int FEhVazia(TFila *pFila){
    return pFila->frente == pFila->tras;
}
void Enfileira(TFila *pFila,int valor){
    if((pFila->tras + 1)%5 == pFila->frente) return;
    pFila->itens[pFila->tras] = valor;
    pFila->tras = (pFila->tras+1)%5;
}
void Desenfileira(TFila *pFila,int *item){
    if(FEhVazia(pFila)) return;
    *item = pFila->itens[pFila->frente];
    pFila->frente = (pFila->frente+1)%5;
}

int main(){
    TFila minha_fila;
    int removido;
    FFVazia(&minha_fila);
    Enfileira(&minha_fila,1);
    Desenfileira(&minha_fila,&removido);
    return 0;
}