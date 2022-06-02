#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct{
    int head;
    int tail;
    int data[MAX];
}Queue;

void createEmpty(Queue* Q){
    (*Q).head = -1;
    (*Q).tail = -1;
}

int isFull(Queue* Q){
    if((*Q).tail == MAX-1){
        return 1;
    }else{
        return 0;
    }
}

void addData(int data, Queue* Q){
    if(isFull(Q) != 1) {
        (*Q).tail+=1;
        (*Q).data[(*Q).tail] = data;
    }else{
        printf("Queue overflow");
    }
}


int main(){
    Queue Q;
    createEmpty(&Q);
    addData(2,&Q);
    addData(3,&Q);
    printf("%d %d",Q.data[0], Q.data[1]);
    return 0;
}