#include "ListaProduto.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void inicializaLista(ListaProduto *pLista){
    pLista->pPrimeiro = (struct Produto*)malloc(sizeof(struct Produto));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
}
void imprimeLista(ListaProduto *pLista){
    struct Produto *pAux = pLista->pPrimeiro->pProx;
    while(pAux != NULL){
        imprimeProduto(pAux);
        pAux = pAux->pProx;
    } 
}
void insereLista(ListaProduto *pLista,int cod,float preco,char * desc){
    pLista->pUltimo->pProx = (struct Produto*)malloc(sizeof(struct Produto));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->cod = cod;
    pLista->pUltimo->preco = preco;
    strcpy(pLista->pUltimo->descricao,desc);
    pLista->pUltimo->pProx = NULL;
}
void Troca(ListaProduto *pLista,struct Produto *pProduto){
    int p = pProduto->cod;
    struct Produto *atual,*pX,*pY;
    atual = pLista->pPrimeiro->pProx;
    for(int i = 0;i < p-1; i++){
        atual = atual->pProx;
    }
    pY = atual->pProx->pProx;
    pX = atual->pProx;
    atual->pProx = pY;
    pX->pProx = pY->pProx;
    pY->pProx = pX;

    
}
void inicializaProduto(struct Produto *pProduto,int codigo,float preco,char *descricao){
    pProduto->cod = codigo;
    pProduto->preco = preco;
    strcpy(pProduto->descricao,descricao);
}
void imprimeProduto(struct Produto *pProduto){
    int cod = pProduto->cod;
    float preco = pProduto->preco;
    char *desc = pProduto->descricao;
    printf("\tInformações sobre o produto:\nCódigo: %d\nPreço: R$ %.2f\nDescrição: %s\n",cod,preco,desc);
}
void setCodigo(struct Produto *pProduto,int codigo){
    pProduto->cod = codigo;
}
void setPreco(struct Produto *pProduto,float preco){
    pProduto->preco = preco;
}
void setDescricao(struct Produto *pProduto,char *descricao){
    strcpy(pProduto->descricao,descricao);
}
int getCodigo(struct Produto *pProduto){
    return pProduto->cod;
}
float getPreco(struct Produto *pProduto){
    return pProduto->preco;
}
char* getDescricao(struct Produto *pProduto){
    return pProduto->descricao;
}

int main(){
    
    ListaProduto lista;
    inicializaLista(&lista);
    for (int i = 0; i < 5; i++)
    {
        insereLista(&lista,i,i*0.5,"Teste");    
    }
    imprimeLista(&lista);
    printf("\n\n");
    struct Produto p;
    p.cod = 2;
    Troca(&lista,&p);
    imprimeLista(&lista);   
  
}
