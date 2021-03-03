#include "Cliente.h"
typedef struct{
    int numero;
    float saldo;
    char tipoConta[3];
    int anoAbertura;
    Cliente* cliente;
}Conta;

void Inicializa(Conta*,Cliente*,int,float,char*);
void ImprimeConta(Conta*);
void SetNumero(Conta*,int);
void SetSaldo(Conta*,float);

void SetTipoConta(Conta*,char*);
void SetAnoAbertura(Conta*,int);
int GetNumero();
int GetSaldo();

char* GetTipoConta();
int GetAnoAbertura();
int SaldoPositivo(float,float);
int Saque(Conta*,float);
void Deposito(Conta*,float);