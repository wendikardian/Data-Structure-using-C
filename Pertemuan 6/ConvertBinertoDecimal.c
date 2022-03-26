#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 32

struct stack{
    int basis[MAX];
    int top;
};

struct stack biner;


void push(struct stack *st, int val){
    if(st->top == MAX-1){
        printf("\n STACT OVERFLOW");
    }else{
        st->top = st->top +1;
        st->basis[st->top] = val;
    }
}

void display(struct stack *st){
    int i;
    if(st->top == -1){
        printf("\n STACK IS EMPTY");
    }else{
        printf("\n");
        for(i = st->top; i>= 0; i--){
            printf("%d", st->basis[i]);
        }
        printf("\n");
    }
}

int pop(struct stack *st){
    int val;
    if(st->top == -1){
        printf("\n STACK UNDERFLOW");
        return -1;
    }else{
        val = st->basis[st->top]*pow(2, st->top);
        st->top = st->top - 1;
        return val;
    }
}

int main(){
    biner.top = -1;
    int number;
    int i;
    int desimal = 0;
    do{
        printf("Enter 1 or 0 (-1 to exit input) : ");
        scanf("%d", &number);
        if(number == 0 || number == 1){
            push(&biner, number);
        }else if(number == -1){
            printf("\nOKE");
        }else{
            printf("\nPlease Input biner number\n");
            
        }
    }while(number != -1);
    display(&biner);
    int j=biner.top;
    for(i=0; i<=j; i++){
        desimal = desimal + pop(&biner);
    }
    printf("The desimal number from that biner number is %d", desimal);
    
    return 0;
}