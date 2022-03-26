#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 5


struct stack{
    int data[MAX]; //array
    int top; //nyimpen data paling atas
};

struct stack myStack;


void push(struct stack *st, int val){
    if(st->top == MAX-1){
        printf("\n STACT OVERFLOW");
    }else{
        st->top = st->top +1;
        st->data[st->top] = val;
    }
}

int pop(struct stack *st){
    int val;
    if(st->top == -1){
        printf("\n STACK UNDERFLOW");
        return -1;
    }else{
        val = st->data[st->top];
        st->top = st->top - 1;
        return val;
    }
}

void display(struct stack *st){
    int i;
    if(st->top == -1){
        printf("\n STACK IS EMPTY");
    }else{
        for(i = st->top; i>= 0; i--){
            printf("\n %d", st->data[i]);
        }
        printf("\n");
    }
}

int peek(struct stack *st){
    if(st->top == -1){
        printf("\n STACK IS EMPTY");
        return -1;
    }else{
        return st->data[st->top];
    }
}


int main(){
    int val, option;
    myStack.top = -1;
    do{
        printf("\n**** STACK MAIN MENU ****** \n");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\nEnter Your Option :");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("pop : ");
                scanf("%d",&val);
                push(&myStack, val);
                break;
            case 2:
                val = pop(&myStack);
                if(val != -1){
                    printf("The value deleted from stact is : %d", val);
                    break;
                }
                break;
            case 3:
                val = peek(&myStack);
                if(val != -1){
                    printf("Value that stored in top of stact is %d", val);
                }
                break;
            case 4:
                display(&myStack);
                break;
        }
    }while(option!=5);
}

