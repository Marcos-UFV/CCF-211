typedef struct{
    int L;
    int C;
    int **matriz;
}Table;
void CreateTable(Table *T,int N);
void FillsTable(Table *T);
void PrintTable(Table *T);
void PrintTableLine(Table *T,int L);