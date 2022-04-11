#include<stdio.h>
#include<stdlib.h>
#define MAX 30
typedef struct stack{
    char word[MAX];
    int top;
}Stack;	

void push(Stack *myStack, char alpha){
    if(myStack->top > MAX-1){
        printf("\nStack overflow");
    }else{
        myStack->top++;
        myStack->word[myStack->top] = alpha;
    }
}

char pop(Stack *myStack){
    if(myStack->top <= -1){
        printf("\nStack undeflow");
        return ' ';
    }else{
        char word;
        word = myStack->word[myStack->top];
        myStack->top--;
        return word;
    }
}

void reverse(Stack *myStack){
    int i;
    int length = myStack->top;
    for(i = length; i>=0; i--){
        printf("%c", myStack->word[i]);
    }
}

void displayStack(Stack *myStack){
    int i;
    int length = myStack->top;
    for(i=0; i<=length; i++){
        printf("%c", myStack->word[i]);
    }
}

int main(){
    Stack myStack;
    Stack myStack2;
    myStack.top = -1;
    myStack2.top = -1;
    char alpha;
    do{
        scanf("%c", &alpha);
        if(alpha != '@'){
            push(&myStack, alpha);
        }
    }while(alpha != '@');
    int length = myStack.top;
    int i;
    for(i = 0; i<= length; i++){
        myStack2.top++;
        myStack2.word[myStack2.top] = pop(&myStack);
    }
    // reverse(&myStack);
    displayStack(&myStack2);
    return 0;
}