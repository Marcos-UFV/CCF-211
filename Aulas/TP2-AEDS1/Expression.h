#include "TruthTable.h"
typedef struct{
    int C;
    int N;
    int **matriz;
}Expression;
int IsNumericDigit(char c);
void EvalueteExpression(Expression *E);
//Modo Interativo
void AsksForNUmberOfClausesAndVariables(Expression *E);
void CreateMatrix(Expression *E);
void AsksForTheFormatOfTheClauses(Expression *E);
void FillsClauses(Expression *E,char *C,int L);
void printMatriz(Expression *E);

//Modo Automático
void FillsMatrix(Expression *E);
void AsksForNumberOfVariables(Expression *E);
