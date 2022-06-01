#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct{
    char nim[10];
    char nama[20];
    float nilai;
}nilaiMatkul;

typedef struct{
    int first;
    int last;
    nilaiMatkul data[MAX];
}Queue;

void createQueue(Queue* Q){
    (*Q).first = -1;
    (*Q).last = -1;
}

int isEmpty(Queue Q){
    int hasil = 0;
    if(Q.first == -1){
        hasil = 1;
    }

    return hasil;
}

int isFull(Queue Q){
    int hasil = 0;
    if(Q.last == MAX-1){
        hasil = 1;
    }
    return hasil;
}

void addData(char nim[], char nama[], float nilai, Queue *Q){
    if(isEmpty(*Q) == 1){
        (*Q).first = 0;
        (*Q).last = 0;
        strcpy((*Q).data[0].nim, nim);
        strcpy((*Q).data[0].nama, nama);
        (*Q).data[10].nilai = nilai;
    }else{
        if(isFull(*Q) != 1){
            (*Q).last += 1;
            strcpy((*Q).data[(*Q).last].nim, nim);
            strcpy((*Q).data[(*Q).last].nama,nama);
            (*Q).data[(*Q).last].nilai = nilai;
        }else{
            printf("Queue overflow\n");
        }
    }
}

void delData(Queue *Q){
    if((*Q).last == 0){
        (*Q).first = -1;
        (*Q).last = -1;
    }else{
        int i;
        for(i = (*Q).first + 1; i<= (*Q).last; i++){
            strcpy((*Q).data[i-1].nim,(*Q).data[i].nim );
            strcpy((*Q).data[i-1].nama,(*Q).data[i].nama );
            (*Q).data[i-1].nilai = (*Q).data[i].nilai;
        }
        (*Q).last -= 1;
    }
}

void printQueue(Queue Q){
    if(Q.first != -1){
        
    }else{
        printf("Queue undeflow\n");
    }
}

int main(){

    return 0;
}