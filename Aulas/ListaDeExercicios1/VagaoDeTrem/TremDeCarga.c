#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 50 // Vapacidade do vagão
int identificaVagao = 1;
typedef struct{
    char descricao[20];
}Item;
struct Vagao{
    Item *itens;
    int id;
    struct Vagao *pProx; 
};
typedef struct{
    struct Vagao *primeiro,*ultimo;
}Trem;
void chegouAEstacao(Trem *pTrem){
    pTrem->primeiro = (struct Vagao*)malloc(sizeof(struct Vagao));
    pTrem->ultimo = pTrem->primeiro;
    pTrem->primeiro->pProx = NULL;
}
void encarrilharVagao(Trem *pTrem,Item *itens){
    pTrem->ultimo->pProx = (struct Vagao*)malloc(sizeof(struct Vagao));
    pTrem->ultimo = pTrem->ultimo->pProx;
    pTrem->ultimo->itens = itens;
    pTrem->ultimo->id = identificaVagao++;
    pTrem->ultimo->pProx = NULL;   
}
void imprimeTrem(Trem *pTrem){
    struct Vagao *aux = pTrem->primeiro->pProx;
    while(aux != NULL){
        printf("Vagão nº %d\n\tCarga no vagão\n",aux->id);
        for(int i =0;i< MAX;i++){
            printf("%s\n",aux->itens[i].descricao);
        }
        aux = aux->pProx;
    }
}
int main(){
    Trem meu_trem;
    chegouAEstacao(&meu_trem);
    Item itens[MAX];
    char descricao[10] = "Item";
    for (int i = 0; i < MAX; i++)
    {
        strcpy(itens[i].descricao,descricao);
    }
    encarrilharVagao(&meu_trem,itens);
    imprimeTrem(&meu_trem);
    
}