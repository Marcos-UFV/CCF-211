#include "ContaBancaria.h"
#include <stdio.h>
int main(){
    Conta conta;
    Cliente marcos;
    CriaCliente(&marcos,"Marcos","Califórnia, 123");
    Inicializa(&conta,&marcos,1234,20.00,"CC");
    SetNome(&marcos,"Outro cliente");
    
    ImprimeConta(&conta);
    printf("Nome do cliente: %s\n",GetNome(&marcos));
}