#include "ContaBancaria.h"
#include <string.h>
#include <stdio.h>
void Inicializa(Conta* conta,Cliente* cliente,int numero,float saldo,char* tipo){
    conta->numero = numero;
    conta->saldo = saldo;
    strcpy(conta->tipoConta,tipo);
    conta->anoAbertura = 2021;
    conta->cliente = cliente;
}
void ImprimeConta(Conta* conta){
    printf("\tConta Número: %d\nTipo de Conta: %s\nTitular: %s\nSaldo: %.2f\nAno de Abertura: %d\n",
    conta->numero,conta->tipoConta,conta->cliente->nome,conta->saldo,conta->anoAbertura);
}
void SetNumero(Conta* conta,int numero){
    conta->numero = numero;
}

int SaldoPositivo(float saldo,float valor){
    return saldo >= valor;
}
int Saque(Conta* conta,float valor){
    if(SaldoPositivo(conta->saldo,valor)){
        conta->saldo -= valor;
        return 1;
    }else{
        return 0;
    }
}
void Deposito(Conta* conta,float valor){
    conta->saldo += valor;
}
void SetTipoConta(Conta* conta,char* tipo){
    strcpy(conta->tipoConta,tipo);
}
void SetAnoAbertura(Conta* conta,int ano){
    conta->anoAbertura = ano;
}
int GetNumero(Conta* conta){
    return conta->numero;
}
char* GetTipoConta(Conta* conta){
    return conta->tipoConta;
}
int GetAnoAbertura(Conta* conta){
    return conta->anoAbertura;
}