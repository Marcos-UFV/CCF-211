#define MaxTam 1000

typedef int Apontador;
typedef int TChave;
typedef struct{

}TItem;
typedef struct{
    TItem vItem[MaxTam];
    Apontador iTopo;
}TPilha;
void FPVazia(TPilha* pPilha){
    pPilha->iTopo = 0;
}

int PEhVazia(TPilha* pPilha){
    return (pPilha->iTopo == 0);
}

int PEmpilha(TPilha *pPilha,TItem* pItem){
    if(pPilha->iTopo == MaxTam)
        return 0;
    pPilha->vItem[pPilha->iTopo] = *pItem;
    pPilha->iTopo++;
    return 1;
}
int PDesempilha(TPilha* pPilha,TItem* pItem){
    if(PEhVazia(pPilha))
        return 0;
    pPilha->iTopo--;
    *pItem = pPilha->vItem[pPilha->iTopo];
    return 1;
}