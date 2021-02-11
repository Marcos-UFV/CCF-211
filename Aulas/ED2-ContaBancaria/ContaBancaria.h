typedef struct {
    int numero;
    float saldo;
}ContaBancaria;

void Inicializa(ContaBancaria* conta,int numero,float saldo);

void Depositar(ContaBancaria* conta, float valor);

void Sacar(ContaBancaria* conta,float valor);

void Imprime(ContaBancaria conta);