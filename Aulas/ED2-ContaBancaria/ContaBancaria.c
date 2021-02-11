#include <stdio.h>
#include "ContaBancaria.h"

void Inicializa(ContaBancaria* conta,int numero,float saldo){
    conta->numero = numero;
    conta->saldo = saldo;
}

void Depositar(ContaBancaria* conta,float valor){
    conta->saldo += valor;
}
void Sacar(ContaBancaria* conta,float valor){
    conta->saldo -= valor;
}

void Imprime(ContaBancaria conta){
    printf("O saldo da conta de número %d é: %.2f\n",conta.numero,conta.saldo);
}