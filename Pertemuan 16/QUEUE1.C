#include<stdio.h>
#include<stdlib.h>
#define MAX 10


typedef struct data{
    int nim;
    char nama;
    int nilai;
}Data;

typedef struct queue{
    int first;
    int last;
    int data[MAX];
}Queue;

int isEmpty(Queue Q){
    if(Q.first == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(Queue Q){
    if(Q.last == MAX -1 ){
        return 1;
    }else{
        return 0;
    }
}

void addData(Queue *Q, int data){
    if(isEmpty(*Q) == 1){
        (*Q).first = 0;
        (*Q).last = 0;
        (*Q).data[0] = data;
    }else{
        if(isFull(*Q) == 0){
            (*Q).last +=1;
            (*Q).data[(*Q).last] = data;
        }else{
            printf("Queue Overflow\n");
        }
    }
}

void delData(Queue *Q){
    int i;
    if((*Q).last ==0){
        (*Q).first = 0;
        (*Q).last = 0;
    }else{
        for(i = ((*Q).first) ; i<=(*Q).last; i++){
            (*Q).data[i] = (*Q).data[i+1];
        }
        (*Q).last -= 1;
    }
}

void printData(Queue Q){
    int i;
    if(isEmpty(Q) != 1){
        for(i = Q.first; i<=Q.last; i++){
            printf("%d ", Q.data[i]);
        }
        printf("\n");
    }else{
        printf("Queue Overflow\n");
    }
}


int main(){
    Queue Q;
    Q.first = -1;
    Q.last = -1;
    addData(&Q,2);
    addData(&Q,4);
    addData(&Q,6);
    addData(&Q,7);
    printf("Antrian : \n");
    printData(Q);
    printf("Antrian setelah dipanggil: \n");
    delData(&Q);
    printData(Q);
    return 0;
}