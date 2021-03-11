#include <stdlib.h>
#include <stdio.h>

struct celula{
    //item
    int chave;
    //Apontador
    struct celula* Pprox;
};

typedef struct{
    struct celula *pPrimeiro,*pUltimo;
}TLista;
//remove do inicio
void LRetira(TLista *plista,int *item){
    struct celula *pAux = NULL;
    pAux = plista->pPrimeiro;
    plista->pPrimeiro = plista->pPrimeiro->Pprox;
    *item = pAux->Pprox->chave;
    free(pAux);
}
//insere no final
void LInsere(TLista *plista,int item){
    plista->pUltimo->Pprox = (struct celula*)malloc(sizeof(struct celula));
    plista->pUltimo = plista->pUltimo->Pprox;
    plista->pUltimo->chave = item;
    plista->pUltimo->Pprox = NULL;
}
//Celula cabeça
void FLVazia(TLista *plista){
    plista->pPrimeiro = (struct celula*)malloc(sizeof(struct celula));
    plista->pUltimo = plista->pPrimeiro;
    plista->pPrimeiro->Pprox = NULL;
}

int main(){
    TLista minha_lista;
    
    FLVazia(&minha_lista);
    LInsere(&minha_lista,1);
    return 0;
}