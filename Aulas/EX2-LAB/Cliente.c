#include "Cliente.h"
#include <string.h>
void CriaCliente(Cliente* cliente,char* nome,char* endereco){
    strcpy(cliente->nome,nome);
    strcpy(cliente->endereco,endereco);    
}
void SetNome(Cliente* cliente,char* nome){
    strcpy(cliente->nome,nome);
}
void SetEndereco(Cliente* cliente,char* endereco){
    strcpy(cliente->endereco,endereco);
}
char* GetNome(Cliente* cliente){
    return cliente->nome;
}
char* GetEndereco(Cliente* cliente){
    return cliente->endereco;
}