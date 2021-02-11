#include <stdio.h>
#include "ContaBancaria.h"

int main(){
    ContaBancaria conta;
    Inicializa(&conta,12345,300.00);
    Imprime(conta);
    Depositar(&conta,50.00);
    Imprime(conta);
    Sacar(&conta,70.00);
    Imprime(conta);
}