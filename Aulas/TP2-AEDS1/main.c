#include "Expression.h"
//#include "TruthTable.h"
int main(){
   
    Expression E;
    //AsksForNUmberOfClausesAndVariables(&E);
    //AsksForTheFormatOfTheClauses(&E);
    AsksForNumberOfVariables(&E);
    FillsMatrix(&E);
    printMatriz(&E);/**/
    /*CreateTable(&T,5);
    FillsTable(&T);
    PrintTable(&T);*/
    EvalueteExpression(&E);
    
}