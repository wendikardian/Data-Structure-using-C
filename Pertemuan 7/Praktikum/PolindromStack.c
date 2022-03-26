// Nama : Wendi Kardian
// NIM  : 2100016
// Kelas: Pendidikan Ilmu Komputer - A


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

// deklarasi stack yang memiliki 2 data yaitu data stringnya dan index paling atasnya (top)
struct stack {
    char word[MAX];
    int top;
};

struct stack myStack;  //deklarasi stack dengan nama myStack

// prosedur untuk menambahkan data di akhir tumpukan 
void push(struct stack *stack, char val[]){
    int length;
    if(stack->top == MAX-1){ // pengecekan apabila data penuh
        printf("Full\n");
    }else{ // proses untuk menambahkan data kedalam stack
        length = strlen(val);
        stack->top+= length;
        strcpy(stack->word, val);
    }
}


// Fungsi untuk menghapus data di akhir stack tersebut
char pop(struct stack *st){
    int val;
    if(st->top == -1){
        printf("\n STACK UNDERFLOW");
        return -1;
    }else{ //kondisi untuk mengembalikan char untuk mengembalikan nilai ujung char array of string tersebut
        val = st->word[st->top];
        st->top = st->top - 1;
        return val;
    }
}


// fungsi utama
int main(){
    char polindrom[20]; //variabel untuk menampung data kata yang di reverse (untuk di cek apakah polindrom atau bukan)
    char polindrom1[20];
    int arrayLength,i;
    myStack.top = -1; //start stack
    scanf("%s", polindrom1); //proses input data kedalam variabel array polindrom
    push(&myStack, polindrom1);
    arrayLength = strlen(myStack.word); //menghitung panjang array of string
    for(i = 0; i<arrayLength; i++){ // looping untuk proses pop stack yang ditampung kedalam polindrom
    	polindrom[i] = pop(&myStack);
	}
	
	// proses mengecek apakah dia polindrom atau bukan menggunakan strcmp
	if(strcmp(polindrom, myStack.word) == 0){
		printf("\nPolindrom");
	}else{
		printf("\nBukan Polindrom");
	}

}