#include "TremSequencial.h"
#include <string.h>
#include <stdio.h>

int identificadorVagao = 1;
void FTremVazio(Trem *pTrem){
    pTrem->topo = 0;
}
int TremVazio(Trem *pTrem){
    return pTrem->topo == 0;
}
void AcoplarVagao(Trem *pTrem,Vagao *vagao){
    if(pTrem->topo == MaxTam) printf("Carga máxima já atingida\n");
    else pTrem->vagoes[pTrem->topo++] = (*vagao);     
}
void DesacoplarVagao(Trem *pTrem,Vagao *rVagao){
    if(TremVazio(pTrem)) printf("O trem ainda está vazio\n");
    else(*rVagao) = pTrem->vagoes[pTrem->topo--];
}
int QuantidadeVagoes(Trem *pTrem){
    return pTrem->topo;
}
void CriaVagao(Vagao *pVagao){
    pVagao->qtd = 0;
    pVagao->id = identificadorVagao++;
}
void AdicionaItem(Vagao *pVagao,Item *pItem){
    pVagao->itens[pVagao->qtd++] = (*pItem);
}
/*void AdicionaItens(Vagao *pVagao,Item *itens,int qtd){
    pVagao->qtd = qtd;
    pVagao->itens = itens;
}*/
void ImprimeTrem(Trem *pTrem){
    printf("Descrição completa do trem:\n");
    int qtd = pTrem->topo;
    for (int i = 0; i < qtd; i++)
    {
        printf("\tVagão número %d\n",pTrem->vagoes[i].id);
        printf("Carga: \n");
        int nItens = pTrem->vagoes[i].qtd;
        for(int j=0;j < nItens;j++)
            printf("Descrição: %s\n",pTrem->vagoes[i].itens[j].descricao);
    }
    
}
void RemoverItens(Vagao *pVagao){
    pVagao->qtd = 0;
}
int main(){
    Trem meu_trem;
    FTremVazio(&meu_trem);
    Item itens[MaxItem];
    for(int i=0;i<3;i++){
        Vagao vagao;
        CriaVagao(&vagao);
        for(int j=0;j<MaxItem;j++){
            strcpy(itens[j].descricao,"Este é um Item");
            AdicionaItem(&vagao,&itens[j]);
        }             
        
        AcoplarVagao(&meu_trem,&vagao);
    }
    ImprimeTrem(&meu_trem);
    RemoverItens(&meu_trem.vagoes[meu_trem.topo]);
    Vagao vagaoRemovido;
    DesacoplarVagao(&meu_trem,&vagaoRemovido);
    ImprimeTrem(&meu_trem);
}