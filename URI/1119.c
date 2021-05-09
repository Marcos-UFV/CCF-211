#include <stdio.h>
#include <math.h>
//10 4 3
int getUnemployeeRight(int* v,int p,int N);
int getUnemployeeLeft(int* v,int p,int N);
int main(){
    int input[3];
    int queue[20];
    int i,m,k,N,e1,e2;

    for (i = 0; i < 3; i++)
    {
        scanf(" %d",&input[i]);
    }
    N = input[0];
    k = input[1];
    m = input[2];
    for (i = 0; i < N; i++)
    {
        queue[i] = i+1;
    }
    
    
    for (i = 0; i < N/2; i++)
    {
        e1 = getUnemployeeRight(queue,(k - 1)%N,N);
        e2 = getUnemployeeLeft(queue,abs(N - m)%N,N);
        printf("%d  %d\n",e1,e2);
        
        
        //printf("%d ",queue[(k - 1)%N]);
        //printf("%d ",(abs(N - m))%N);
        m += m;
        k += k;
    }
    printf("\n");
      
    
}
int getUnemployeeRight(int* v,int p,int N){
    int aux;
    while(!v[p] && p < N){
        p += (++p%N);
    }
    printf("%d \n",p);
    aux = v[p];
    v[p] = 0;
    return aux;
}
int getUnemployeeLeft(int* v,int p,int N){
    int aux;
    while(!v[p] && p < N){
        p++;
        p = (abs(N - p))%N;
    }
    printf("%d \n",p);
    aux = v[p];
    v[p] = 0;
    return aux;
}