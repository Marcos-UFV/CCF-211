#include "InteractiveMode.h"
int main(){
    Expression E;
    AsksForNUmberOfClausesAndVariables(&E);
    AsksForTheFormatOfTheClauses(&E);
    printMatriz(&E);
}