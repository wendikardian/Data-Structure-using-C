#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

typedef struct stack{
    char word[MAX];
    int top;
}Stack;

/// data structure
Stack myStack;
Stack temp;

Stack createStack(){
    Stack newStack;
    newStack.top = -1;
    return newStack;
}

void push(Stack *myStack, char new){
    if(myStack->top > MAX-1){
        printf("\nStack Overflow");
    }else{
        myStack->top++;
        myStack->word[myStack->top] = new;
    }
}

char pop(Stack *myStack){
    char value;
    if(myStack->top <= -1){
        printf("\nStack Underflow");
        return '0';
    }else{
        value = myStack->word[myStack->top];
        myStack->top--;
        return value;
    }
}

void displayStack(Stack myStack){
    int i;
    for(i = myStack.top; i>=0; i--){
        printf("\n %c", myStack.word[i]);
    }
}

void reverseStack(Stack *myStack, Stack *temp){
    int i;
    int length = myStack->top;
    for(i=0; i<=length; i++){
        temp->top++;
        temp->word[temp->top] = pop(myStack);
    }
    for(i = 0; i<=length;i++){
        myStack->top++;
        myStack->word[i] = temp->word[i];
    }
}

int main(){
    myStack = createStack();
    temp = createStack();
    int total;
    scanf("%d",&total);
    int j;
    char input[10];
    for(j = 0; j<total; j++){
        scanf("%s", input);
        if(input[0] == '+'){
            push(&myStack, input[1]);
        }else if(input[0] == '^'){
            reverseStack(&myStack, &temp);
        }
    }
    displayStack(myStack);
    return 0;
}