struct Produto{
    int cod;
    float preco;
    char descricao[20];
    struct Produto *pProx;
};

typedef struct {
    struct Produto *pPrimeiro,*pUltimo;
}ListaProduto;

void inicializaLista(ListaProduto *pLista);
void imprimeLista(ListaProduto *pLista);
void insereLista(ListaProduto *pLista,int cod,float preco,char *desc);
void Troca(ListaProduto *pLista,struct Produto *pProduto);


void inicializaProduto(struct Produto *pProduto,int codigo,float preco,char *descricao);
void imprimeProduto(struct Produto *pProduto);
void setCodigo(struct Produto *pProduto,int codigo);
void setPreco(struct Produto *pProduto,float preco);
void setDescricao(struct Produto *pProduto,char *descricao);
int getCodigo(struct Produto *pProduto);
float getPreco(struct Produto *pProduto);
char* getDescricao(struct Produto *Produto);
