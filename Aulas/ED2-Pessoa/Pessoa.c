#include "Pessoa.h"
#include <string.h>
#include <stdio.h>
void preencheDados(Pessoa** pessoa,char* nome,char* nascimento,int cpf){
    strcpy((*pessoa)->nome,nome);
    strcpy((*pessoa)->dataNascimento,nascimento);
    (*pessoa)->cpf = cpf;
}
void imprimeEstrutura(Pessoa** pessoa){

    printf("\tNome: %s\nData de Nascimento: %s\nCPF: %d\n",
        (*pessoa)->nome,(*pessoa)->dataNascimento,(*pessoa)->cpf);
}