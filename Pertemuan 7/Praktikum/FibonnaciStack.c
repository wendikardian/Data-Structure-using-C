// Wendi Kardian - 2100016 
// Fibonnaci Sequence 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

// struktur untuk stack yang akan menampung deret fibonnaci
struct stack{
    int value[MAX];
    int top;
};

// deklarasi 2 penampung stack untuk menampung data deret fibonnaci
struct stack fibonnaci;
struct stack fibonnaci2;


// prosedur untuk menambah deret fibonnaci di akhir
void push(struct stack* stack){  
    if(stack->top == -1){ //inisialisasi apabila masih kosong maka defaultnya 1 
        stack->top++;
        stack->value[stack->top] = 1; //inisialisasi apabila hanya terdiri 1 data saja maka defaultnya 1 
    }else if(stack->top == 0){
        stack->top++;
        stack->value[stack->top] = 1;
    }else{ // kondisi fibonnaci di mana bilangan tersebut merupakan penjumlahan dari 2 bilangan sebelumnya
        stack->top++;
        stack->value[stack->top] = stack->value[stack->top-2] + stack->value[stack->top -1];
    }
}

int pop(struct stack *stack){ //function untuk mengambil data di paling ujung stack tersebut
    int val;
    if(stack->top == -1){  //di cek apabila stack kosong atau tidak
        printf("Stack empty\n");
        return 0;
    }else{ //kondisi untuk mengembalikan nilai stack paling belakang
        val = stack->value[stack->top];
        stack->top--;
        return val;
    }
}

int main(){
    int value, i;
    fibonnaci.top = -1;  //inisialisasi awal indexing stack
    fibonnaci2.top = -1;
    scanf("%d",&value);
    for(i=0; i<value; i++){ //proses menyisipkan deret fibonnaci dari data yang panjangnya ditentukan user input
        push(&fibonnaci);
    }

    int arr[MAX];
    int length = fibonnaci.top;
    for(i = 0; i<= length; i++){   //proses mengambil data dan di tampung ke variabel fibonnaci 2 untuk sementara
        fibonnaci2.top++;
        fibonnaci2.value[i] = pop(&fibonnaci);
    }

    printf("\nReverse Fibonnaci : ");   //menampilkan deret reverse fibonnaci
    for(i = 0;i<= length; i++){
        printf("%d  ", fibonnaci2.value[i]);
    }

    for(i = 0; i<= length; i++){ //proses mereverse kembali fibonnaci agar kembali tidak tereverese
        fibonnaci.value[i] = pop(&fibonnaci2);
    }

    printf("\nNormal Fibonnaci : "); //proses menampilkan deret fibonnaci ke dalam console
    for(i = 0;i<= length; i++){
        printf("%d  ", fibonnaci.value[i]);
    }


    return 0;
}