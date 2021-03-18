
#include <stdio.h>
#define MaxTam 100

typedef struct{
    int chave;
}TipoItem;
typedef struct{
    TipoItem itens[MaxTam];
    int topo;
}TipoPilha;
void FPVazia(TipoPilha *pPilha){
    pPilha->topo = 0;
}
int Vazia(TipoPilha *pPilha){
    return pPilha->topo == 0;
}
void Empilha(TipoPilha *pPilha,TipoItem nItem){
    if(pPilha->topo == MaxTam) printf("Overflow");
    else{
        pPilha->itens[pPilha->topo++] = nItem;
    }
}
void Desempilha(TipoPilha *pPilha,TipoItem *rItem){
    if(Vazia(pPilha)) printf("Underflow");
    else{
        (*rItem) = pPilha->itens[pPilha->topo--];        
    }
}
int Tamanho(TipoPilha *pPilha){
    return pPilha->topo;
}
int main(){
    TipoPilha minha_pilha;
    FPVazia(&minha_pilha);
    printf("Está vazia? %d\n",Vazia(&minha_pilha));
    for (int i = 1; i <= 50; i++)
    {
       TipoItem item;
       item.chave = i;
       Empilha(&minha_pilha,item);
    }
    printf("Tamanho da pilha: %d\n",Tamanho(&minha_pilha));
    TipoItem itemRemovido;
    Desempilha(&minha_pilha,&itemRemovido);
    printf("Item removido %d\n",itemRemovido.chave);
    Desempilha(&minha_pilha,&itemRemovido);
    printf("Item removido %d\n",itemRemovido.chave);
    printf("Tamanho da pilha: %d\n",Tamanho(&minha_pilha));
    
}