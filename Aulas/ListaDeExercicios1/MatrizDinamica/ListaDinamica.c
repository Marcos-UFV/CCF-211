#include <stdlib.h>
#include <stdio.h>
struct Celula{
    int x;
    struct Celula *pProx;
};
typedef struct{
    struct Celula *primeira,*ultima;
}Linha;
void criaLinhaVazia(Linha *pLinha){
    pLinha->primeira = (struct Celula*)malloc(sizeof(struct Celula));
    pLinha->ultima = pLinha->primeira;
    pLinha->primeira->pProx = NULL;
}
void insereCelula(Linha *pLinha,int x){
    pLinha->ultima->pProx = (struct Celula*)malloc(sizeof(struct Celula));
    pLinha->ultima = pLinha->ultima->pProx;
    pLinha->ultima->x = x;
    pLinha->ultima->pProx = NULL;
}
void inverteLinha(Linha *pLinha){
    struct Celula *atual,*anterior,*proxima;
    atual = pLinha->primeira->pProx;
    anterior = NULL;
    while(atual != NULL){
        proxima = atual->pProx;
        atual->pProx = anterior;
        anterior = atual;
        atual = proxima;
    }
    pLinha->primeira->pProx = anterior;
}
void imprimeLinha(Linha *pLinha){
    struct Celula *aux = pLinha->primeira->pProx;
    while(aux != NULL){
        printf("%d ",aux->x);
        aux = aux->pProx;
    }
    printf("\n");
}

int main(){
    Linha linha;
    criaLinhaVazia(&linha);
    insereCelula(&linha,1);
    insereCelula(&linha,3);
    insereCelula(&linha,5);
    insereCelula(&linha,7);
    insereCelula(&linha,9);
    imprimeLinha(&linha);
    inverteLinha(&linha);
    imprimeLinha(&linha);
}