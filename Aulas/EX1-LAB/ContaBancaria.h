typedef struct{
    int numero;
    float saldo;
    char nomeCliente[30];
    char tipoConta[3];
    int anoAbertura;
}Conta;

void Inicializa(Conta*,int,float,char*,char*);
void ImprimeConta(Conta*);
void SetNumero(Conta*,int);
void SetSaldo(Conta*,float);
void SetNomeCliente(Conta*,char*);
void SetTipoConta(Conta*,char*);
void SetAnoAbertura(Conta*,int);
int GetNumero();
int GetSaldo();
char* GetNomeCliente();
char* GetTipoConta();
int GetAnoAbertura();
int SaldoPositivo(float,float);
int Saque(Conta*,float);
void Deposito(Conta*,float);