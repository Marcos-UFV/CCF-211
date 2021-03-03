#include "Pessoa.h"

int main(){
    Pessoa* p;
    preencheDados(&p,"Marcos","14/04/1993",1234567898);
    imprimeEstrutura(&p);
}