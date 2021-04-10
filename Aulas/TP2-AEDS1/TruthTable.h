#include "Expression.h"
typedef struct{
    int L;
    int C;
    int **matriz;
}Table;
void CreateTable(Table *T,int N);
void EvaluatesExpression(Table *T,Expression *E);
void FillsTable(Table *T);
void PrintTable(Table *T);