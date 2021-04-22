#include <stdio.h>
#include <stdlib.h>
#define MAX 50
void selectionSort(int *V,int N);
void bubbleSort(int *V,int N);
void insertionSort(int *V,int N);

void printList(int *V,int N);
void FillsList(int *V,int N);

int main(){
    int V[MAX];
    int L[2*MAX];
    FillsList(V,MAX);
    FillsList(L,2*MAX);
    printList(V,MAX);
    insertionSort(V,MAX);  
    printList(V,MAX);
    insertionSort(L,2*MAX);
    printList(L,2*MAX);  
}
void insertionSort(int *V,int N){
    int i,j,aux;
    for (i = 1; i < N; i++)
    {
        aux = V[i];
        j = i - 1;
        while(j >= 0 && aux < V[j]){
            V[j + 1] = V[j];           
            j--;
        }
        V[j + 1] = aux;
    }    
}
void bubbleSort(int *V,int N){
    int i,j,temp,replacement;
    for (i = 0; i < N - 1; i++)
    {
        replacement = 0;
        for (j = 1 ; j < N - i; j++)
        {            
            if(V[j] < V[j - 1]){
                temp = V[j];
                V[j] = V[j - 1];
                V[j - 1] = temp;
                replacement = 1;
            }
        }
        if (!replacement)
            break;                
    }    
}
void selectionSort(int *V,int N){
    int i,j,min_index,temp;
    for (i = 0; i < N - 1; i++)
    {
        min_index = i;
        for (j = i+1; j < N; j++)
        {
            if(V[j] < V[min_index])
                min_index = j;
        }
        if(min_index != i){
            temp = V[i];
            V[i] = V[min_index];
            V[min_index] = temp;
        }        
    }
}
void FillsList(int *V,int N){
    int i;
    for (i = 0; i < N; i++)
    {
        V[i] = rand() % N;
    }
}
void printList(int *V,int N){
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d ",V[i]);
    }
    printf("\n");    
}