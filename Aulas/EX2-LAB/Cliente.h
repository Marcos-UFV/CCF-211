typedef struct{
    char nome[30];
    char endereco[100];
}Cliente;
void CriaCliente(Cliente*,char*,char*);
void SetNome(Cliente*,char*);
void SetEndereco(Cliente*,char*);
char* GetNome(Cliente*);
char* GetEndereco(Cliente*);