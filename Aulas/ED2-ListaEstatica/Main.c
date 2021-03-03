#include <string.h>
#include "ListaSequencial.h"
#include <stdio.h>
int main(){
    Lista* li;
    li = cria_lista();
    Aluno dados;
    strcpy(dados.nome,"Marcos");
    dados.matricula = 123;
    dados.n1 = 10;
    dados.n2 = 20;
    dados.n3 = 30;
    int x = lista_vazia(li);
    printf("Resultado primeira inserção: %d\n",x);
    if(lista_vazia(li))  
        x = insere_lista_inicio(li,dados);
    printf("Resultado segunda inserção: %d\n",x);
    Aluno novo;
    strcpy(novo.nome,"André");
    novo.matricula = 4321;
    novo.n1 = 20;
    novo.n2 = 30;
    novo.n3 = 40;
    x = insere_lista_final(li,novo);
    printf("Resultado da inserção: %d\n",x);

    Aluno dados_aluno;
    int posicao = 1;
    x = consulta_lista_pos(li,posicao,&dados_aluno);
    printf("Resultado da consulta pela posição: %d\n",x);
    int  matricula = 1234;
    x = consulta_lista_pos(li,matricula,&dados_aluno);
    printf("Resultado por matrícula: %d\n",x);
    
    x = tamanho_lista(li);
    printf("Resultado da consulta pelo tamanho da lista: %d\n",x);
    x = remove_lista_final(li);
    printf("Resultado da remoção no final: %d\n",x);
    x = remove_lista_inicio(li);
    printf("Resultado da remoção no início: %d\n",x);
    int matricula_aluno = 001;
    x = remove_lista(li,matricula_aluno);
    printf("Resultado da exclusão pela matrícula: %d\n",x);

    x = lista_cheia(li);
    printf("Resultado da verificação se a lista está cheia: %d\n",x);
    if(lista_cheia(li))
        libera_lista(li);


}