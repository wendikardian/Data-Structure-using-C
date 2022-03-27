// WENDI KARDIAN - 2100016
// PENDIDIKAN ILMU KOMPUTER - A

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10


// STRUCTURE FOR STACK
struct stack{
    int stk[MAX];
    int top;
};

// DEKLARASI STACK
struct stack stk;


// PROSEDUR UNTUK MENAMBAHKAN DATA DI AKHIR
void push(char c, struct stack *stk){
    if(stk->top == (MAX - 1)){
        printf("STACK OVERFLOW\n");
    }else{
        stk->top+=1;
        stk->stk[stk->top] = c;
    }
}

// PROSEDUR UNTUK MENGHAPUS DATA DAN RETURN DATA DALAM BENTUK CHARACTER
char pop(struct stack *stk){
    if(stk->top == -1){
        printf("STACK UNDER FLOW\n");
    }else{
        return stk->stk[stk->top--];
    }
}

void main(){
    // DEKLARASI STACK DAN VARIABEL LAINNYA 
    stk.top = -1;
    char exp[MAX];
    char temp;
    int i, flag = 1; //DEFAULT FLAG BERNILAI 1 (TRUE) ATAU EKSPRESSION VALID
    printf("Print the Expression : ");
    scanf("%s", exp);
    for(i = 0; i<strlen(exp); i++){ //ITERASI UNTUK MELAKUKAN PENGECEKAN DARI EKSPRESSION TERSEBUT
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){ // APABILA SIMBOL PEMBUKA MAKA DATA AKAN DI MASUKAN KEDALAM STACK 
            push(exp[i], &stk);     //CONTOH SIMBOL PEMBUKA '( // [ // {'
        }
        if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){   // APABILA SIMBOL YANG DICEK ITU PENUTUP
            if(stk.top == -1){ //ARTINYA JIKA SIMBOL PENUTUP DILETAKAN DI INDEX PERTAMA (TIDAK ADA PEMBUKANYA)
                flag = 0; // FLAG = 0 ARTINYA EXSPRESSION INVALID
            }else{
                temp= pop(&stk); //MELAKUKAN PENGECEKAN EKSPRESSION 
                if(exp[i] == ')' && (temp == '{' || temp == '[')){    // DILAKUKAN PENGECEKAN APAKAH ANTARA KURUNG PEMBUKA DAN PENUTUP
                    flag = 0;                                         // KONSISTEN ATAU TIDAK
                }                                                     // JIKA TIDAK KONSISTEM FLAG = 0 (EXPRESSION INVALID)
                if(exp[i] == '}' && (temp == '(' || temp == '[')){
                    flag = 0;
                }
                if(exp[i] == ']' && (temp == '(' || temp == '{')){
                    flag = 0;
                }
            }
        }
        
    } 
    if(stk.top >= 0){ // PROSES PENGECEKAN APAKAH MASIH ADA EXPRESSION YANG TERSISA, JIKA YA BERARTI EXPRESSION INVALID
        flag = 0;
    }
    if(flag ==1){ //PROSES PENYETAKAN EXPRESSION ITU VALID (APABILA FLAG = 1) JIKA FLAG = 0 MAKA EXPRESSION INVALID
        printf("\nValid expression");
    }else{
        printf("\nInvalid expression");
    }
}