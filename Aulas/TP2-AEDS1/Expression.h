typedef struct{
    int C;
    int N;
    int **matriz;
}Expression;
int IsNumericDigit(char c);

//Modo Interativo
void AsksForNUmberOfClausesAndVariables(Expression *E);
void CreateMatrix(Expression *E);
void AsksForTheFormatOfTheClauses(Expression *E);
void FillsClauses(Expression *E,char *C,int L);
void printMatriz(Expression *E);

//Modo Automático