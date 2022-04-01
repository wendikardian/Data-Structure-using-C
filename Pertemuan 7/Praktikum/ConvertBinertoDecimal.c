// Nama  : Wendi kardian
// NIM   : 2100016
// Kekas : Pendidikan Ilmu Komputer - A


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 32

// struct untuk menampung stack bilangan biner
struct stack{
    char basis[MAX];
    int top;
};

// deklarasi variabel dengan tipe struct yang sudah di buat 
struct stack biner;

// function push untuk memasukan nilai biner kedalam struct tersebut
void push(struct stack *st, char val){
    if(st->top == MAX-1){
        printf("\n STACT OVERFLOW");
    }else{
        st->top = st->top +1;
        st->basis[st->top] = val;
    }
}


// function pop untuk menghapus 1 data di akhir tumpuk yang setiap basisnya akan mengembalikan nilai desimalnya yang akan dijumlahkan
int pop(struct stack *st){
    int val;
    if(st->top == -1){
        printf("\n STACK UNDERFLOW");
        return -1;
    }else{
    	if(st->basis[st->top] == '1'){
    		val = 1*pow(2, st->top);
        	st->top = st->top - 1;
        	return val;	
		}else{
			st->top = st->top - 1;
			return 0;
		}
    }
}

// fungsi utama
int main(){
    biner.top = -1; //deklarasi awal nilai top stack tersebut
    int i, arrayLength;
    int desimal = 0;
    char word[MAX]; // variabel untuk menampung bilangan biner
    scanf("%s", word);
    arrayLength = strlen(word);
    for(i = arrayLength-1; i>=0; i--){   //iterasi untuk melakukan push nilai biner kedalam stack
    	push(&biner, word[i]);
	};
    int j=biner.top;
    for(i=j; i>=0; i--){ // iterasi untuk melakukan proses pop serta menkalkulasi nilai desimal dari bilangan biner tersebut
        desimal = desimal + pop(&biner);
    }
    printf("\n%d", desimal);
    return 0;
}
