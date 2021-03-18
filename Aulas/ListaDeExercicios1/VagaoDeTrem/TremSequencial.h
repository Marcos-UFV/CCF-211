#define MaxTam 150
#define MaxItem 50
typedef struct{
    char descricao[20];
}Item;
typedef struct{
    int id;
    int qtd;
    Item itens[MaxItem];
}Vagao;
typedef struct{
    Vagao vagoes[MaxTam];
    int topo;
}Trem;
void FTremVazio(Trem *pTrem);
int TremVazio(Trem *pTrem);
void AcoplarVagao(Trem *pTrem,Vagao *vagao);
void DesacoplarVagao(Trem *pTrem,Vagao *rVagao);
int QuantidadeVagoes(Trem *pTrem);
void CriaVagao(Vagao *pVagao);
void AdicionaItem(Vagao *pVagao,Item *pItem);
void RemoverItens(Vagao *pVagao);
void ImprimeTrem(Trem *pTrem);