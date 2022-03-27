#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 20

struct stack{
    int data[MAX];
    int top;
};


void push(struct stack *myStack, int val){
    if(myStack->top < MAX-1){
        myStack->top++;
        myStack->data[myStack->top] = val;
    }else{
        printf("\nStack overflow");
    }
}

int pop(struct stack *myStack){
    if(myStack->top > -1){
        printf("\nData that has been deleted : %d", myStack->data[myStack->top]);
        myStack->top--;
    }else{
        printf("\nStack undeflow");
    }
}

struct stack createStack(){
    struct stack newStack;
    newStack.top = -1;
    return newStack;
}

bool isEmpty(struct stack myStack){
    if(myStack.top == -1){
        return true;
    }else{
        return false;
    }
}

bool isFull(struct stack myStack){
    if(myStack.top == MAX-1){
        return true;
    }else{
        return false;
    }
}

int main(){
    struct stack myStack;
    myStack = createStack();
    push(&myStack, 1);
    push(&myStack, 2);
    push(&myStack, 3);
    push(&myStack, 4);
    pop(&myStack);
    pop(&myStack);
    pop(&myStack);
    pop(&myStack);
    return 0;
}