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

int isEmpty(Queue* Q){
    if((*Q).tail == -1){
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

void delData(Queue* Q){
    if(isEmpty(Q) != 1){
        int i;
        for(i = 0; i<(*Q).tail; i++){
            (*Q).data[i] = (*Q).data[i+1];
        }
        (*Q).tail -= 1;
    }else{
        printf("Queue Underflow\n");
    }
}

void printData(Queue* Q){
    int i;
    printf("\n");
    for(i=0; i<=(*Q).tail; i++){
        printf("%d ",(*Q).data[i]);
    }
}

int main(){
    Queue Q;
    createEmpty(&Q);
    isEmpty(&Q);
    delData(&Q);
    addData(2,&Q);
    addData(3,&Q);
    addData(4,&Q);
    addData(5,&Q);
    printData(&Q);
    delData(&Q);
    printData(&Q);
    delData(&Q);
    printData(&Q);
    return 0;
}