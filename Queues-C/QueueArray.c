#include <stdio.h>
#define N 101
int A[N];
int front = -1;
int rear = -1;
int IsEmpty(){
    return (front == -1 && rear == -1);
}
int IsFull(){
    return (rear + 1) % N == front;
}
int Front(){
    if(front == -1) return -1;
    return A[front];
}
void Print(){
    //Frinding number of elements in queue
    int count = (rear + N - front) % N + 1;
    for(int i = 0; i < count;i++){
        int index = (front + i) % N; // Index of element while travesing circularly from front
        printf(" %d",A[index]);
    }
    printf("\n");
}
void Enqueue(int x){
    if((rear + 1) % N == front) return;
    else if(IsEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % N;
    A[rear] = x;
}
void Dequeue(){
    if(IsEmpty()) return;
    else if( front == rear)
        front = rear = -1;
    else
        front = (front + 1) % N;

}
int main(){
    Enqueue(2);Print();
    Enqueue(4);Print();
    Enqueue(6);Print();
    Dequeue();Print();
    Enqueue(8);Print();
    Dequeue();Print();


}