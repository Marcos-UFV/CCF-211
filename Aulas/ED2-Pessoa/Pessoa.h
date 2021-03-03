typedef struct{
    char nome[30];
    char dataNascimento[11];
    int cpf;
}Pessoa;
void preencheDados(Pessoa**,char*,char*,int);
void imprimeEstrutura(Pessoa**);
