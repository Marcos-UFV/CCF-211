#include <stdlib.h>
#include <stdio.h>
struct celula{
    int chave;
    struct celula* pProx;
};
typedef struct{
    struct celula *pPrimeira,*pUltima;
}TLista;

void FLVazia(TLista *pLista){
    pLista->pPrimeira = (struct celula*)malloc(sizeof(struct celula));
    pLista->pUltima = pLista->pPrimeira;
    pLista->pPrimeira->pProx = NULL;
}
int Vazia(TLista *pLista){
    return pLista->pPrimeira == pLista->pUltima;
}
void LInsere(TLista *pLista,int x){
    //A diferença até aqui é que não se utilizou uma variável temporada e nem foi preciso percorrer toda lista para inserir no final
    pLista->pUltima->pProx = (struct celula*)malloc(sizeof(struct celula));
    pLista->pUltima = pLista->pUltima->pProx;
    pLista->pUltima->chave = x;
    pLista->pUltima->pProx = NULL;
}
void LInverte(TLista *pLista){
    struct celula *atual,*anterior,*proxima;
    atual = pLista->pPrimeira->pProx; //Para que a primeira célula continue sendo a célula cabeça
    anterior = NULL;
    while(atual != NULL){
        proxima = atual->pProx;
        atual->pProx = anterior;
        anterior = atual;
        atual = proxima;
    }
    pLista->pPrimeira->pProx = anterior;
}
void LRetira(TLista *pLista,int *rInt){
    struct celula *rCelula;
    if(Vazia(pLista)) printf("Lista vazia");
    else{
        rCelula = pLista->pPrimeira->pProx;
        (*rInt) =rCelula->chave;
        pLista->pPrimeira->pProx = rCelula->pProx;
        if(pLista->pPrimeira->pProx == NULL) pLista->pUltima = pLista->pPrimeira;
        free(rCelula); 
    }
}
void LImprime(TLista *pLista){
    struct celula *aux = pLista->pPrimeira->pProx;
    while (aux != NULL)
    {
        printf("Valor: %d\n",aux->chave);
        aux = aux->pProx;
    }    
}
int main(){
    TLista minha_lista;

    FLVazia(&minha_lista);
    printf("Lista está vazia? %d\n",Vazia(&minha_lista));
    LInsere(&minha_lista,2);
    printf("Lista está vazia? %d\n",Vazia(&minha_lista));
    LInsere(&minha_lista,4);
    LInsere(&minha_lista,6);
    LInsere(&minha_lista,8);
    LImprime(&minha_lista);
    LInverte(&minha_lista);
    LImprime(&minha_lista);
    int removido;
    LRetira(&minha_lista,&removido);
    printf("O item removido foi %d\n",removido);
    LImprime(&minha_lista);
}

