#include <stdio.h>
#include <stdlib.h>

struct celula{
    // Item
    int chave;
    // Apontador
    struct celula *Pprox;
};

typedef struct{
    struct celula *pTopo;
}TPilha;
void FPVazia(TPilha *pPilha){
    pPilha->pTopo = NULL;
}
void Empilha(TPilha *pPilha,int valor){

    struct celula  *pAux = NULL;
    pAux = (struct celula*)malloc(sizeof(struct celula));
    pAux->Pprox = pPilha->pTopo;
    pAux->chave = valor;
    pPilha->pTopo = pAux;
}
void Desempilha(TPilha *pPilha,int *item){
    struct celula *pAux = NULL;
    pAux = pPilha->pTopo;
    *item = pAux->chave;
    pPilha->pTopo = pPilha->pTopo->Pprox;
    free(pAux);
}
int main(){
    
    TPilha minha_pilha;
    int i;
    FPVazia(&minha_pilha);

    Empilha(&minha_pilha,1);
    Desempilha(&minha_pilha,&i);

    return 0;
}