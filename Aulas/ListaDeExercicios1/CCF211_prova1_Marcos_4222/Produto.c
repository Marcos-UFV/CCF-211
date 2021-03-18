#include "Produto.h"
#include <stdio.h>
#include <string.h>
void inicializa(Produto *pProduto,int codigo,float preco,char *descricao){
    pProduto->cod = codigo;
    pProduto->preco = preco;
    strcpy(pProduto->descricao,descricao);
}
void imprime(Produto *pProduto){
    int cod = pProduto->cod;
    float preco = pProduto->preco;
    char *desc = pProduto->descricao;
    printf("\tInformações sobre o produto:\nCódigo: %d\nPreço: R$ %.2f\nDescrição: %s\n",cod,preco,desc);
}
void setCodigo(Produto *pProduto,int codigo){
    pProduto->cod = codigo;
}
void setPreco(Produto *pProduto,float preco){
    pProduto->preco = preco;
}
void setDescricao(Produto *pProduto,char *descricao){
    strcpy(pProduto->descricao,descricao);
}
int getCodigo(Produto *pProduto){
    return pProduto->cod;
}
float getPreco(Produto *pProduto){
    return pProduto->preco;
}
char* getDescricao(Produto *pProduto){
    return pProduto->descricao;
}

int main(){
    Produto teste;
    inicializa(&teste,123,12.3,"Teste de Descrição");
    imprime(&teste);
    setCodigo(&teste,321);
    setPreco(&teste,24.6);
    setDescricao(&teste,"Nova descrição");
    imprime(&teste);
    int cod;
    cod = getCodigo(&teste);
    float preco;
    preco = getPreco(&teste);
    char* desc;
    desc = getDescricao(&teste);
    printf("Cod: %d\nPreco%.2f\nDesc %s\n",cod,preco,desc);
}
