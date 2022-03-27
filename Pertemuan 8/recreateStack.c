#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 30

typedef struct stack{
    int data[MAX];
    int top;
}Stack;

Stack createStack(){
    Stack newStack;
    newStack.top = -1;
    return newStack;
}

void push(Stack *myStack, int val){
    if(myStack->top < MAX-1){
        myStack->top ++;
        myStack->data[myStack->top] = val;
    }else{
        printf("\nStack overflow");
    }
}

void pop(Stack *myStack){
    if(myStack->top > -1){
        printf("\nThe stack has been poped : %d", myStack->data[myStack->top]);
        myStack->top--;
    }else{
        printf("\nStack Underflow");
    }
}

bool isEmpty(Stack *myStack){
    if(myStack->top <=> -1){
        return true;
    }else{
        return false;
    }
}

bool isFull(Stack *myStack){
    if(myStack->top == MAX-1){
        return true;
    }else{
        return false;
    }
}

int main(){
    Stack myStack;
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