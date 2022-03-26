#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct stack{
    int data[10];
    int topA;
    int topB;
};

struct stack myStack;

void pushA(struct stack *myStack, int val){
    if(myStack->topA == myStack->topB-1){
        printf("STACT OVERFLOW");
    }else{
        myStack->topA += 1;
        myStack->data[myStack->topA] = val;
    }
}

int popA(struct stack *myStack){
    int val;
    if(myStack->topA == -1){
        printf("\nSTACK UNDERFLOW");
        val == -99;
    }else{
        val = myStack->data[myStack->topA];
        myStack->topA-= 1;
    }
    return val;
}

void display_stackA(struct stack *myStack){
    int i;
    if(myStack->topA == -1){
        printf("STACT IS EMPTY");
    }else{
        for(i = myStack->topA; i>=0; i--){
            printf("%d\t", myStack->data[i]);
        }
    }
}

void pushB(struct stack *myStack, int val){
    if(myStack->topB-1 == myStack->topA){
        printf("\nSTACK OVERFLOW");
    }else{
        myStack->topB-=1;
        myStack->data[myStack->topB] = val;
    }
}

void display_stackB(struct stack *myStack){
    int i;
    if(myStack->topB == MAX){
        printf("\nSTACK IS EMPTY");
    }else{
        for(i = myStack->topB; i<MAX; i++){
            printf("%d\t", myStack->data[i]);
        }
    }
}

int popB(struct stack *myStack){
    int val;
    if(myStack->topB == MAX){
        printf("\nSTACK IS EMPTY");
        val == -99;
    }else{
        val = myStack->data[myStack->topB];
        myStack->topB+=1;
    }
}

int main(){
    myStack.topA = -1;
    myStack.topB = MAX;
    pushA(&myStack, 8);
    pushA(&myStack, 10);
    pushA(&myStack, 12);
    popA(&myStack);
    display_stackA(&myStack);
    printf("\n\nstack B\n");
    pushB(&myStack, 90);
    pushB(&myStack, 78);
    pushB(&myStack, 98);
    popB(&myStack);
    display_stackB(&myStack);
}