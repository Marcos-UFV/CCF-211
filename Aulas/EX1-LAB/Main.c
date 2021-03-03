#include "ContaBancaria.h"

int main(){
    Conta conta;
    Inicializa(&conta,1234,20.00,"Marcos","CC");
    ImprimeConta(&conta);
}