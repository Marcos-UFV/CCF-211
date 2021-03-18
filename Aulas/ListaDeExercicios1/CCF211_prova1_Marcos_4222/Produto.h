typedef struct {
    int cod;
    float preco;
    char descricao[20];
}Produto;
void inicializa(Produto *pProduto,int codigo,float preco,char *descricao);
void imprime(Produto *pProduto);
void setCodigo(Produto *pProduto,int codigo);
void setPreco(Produto *pProduto,float preco);
void setDescricao(Produto *pProduto,char *descricao);
int getCodigo(Produto *pProduto);
float getPreco(Produto *pProduto);
char* getDescricao(Produto *Produto);
