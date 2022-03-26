#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct stack{
    int data;
    struct stack* next;
};

struct stack *top = NULL;

struct stack *push(struct stack *top, int val){
    struct stack *ptr;
    ptr = (struct stack*)malloc(sizeof(struct stack));
    ptr->data = val;
    if(top == NULL){
        ptr->next = NULL;
        top = ptr;
    }else{
        ptr->next = top;
        top = ptr;
    }
    return ptr;
}

struct stack *display(struct stack *top){
    struct stack *ptr;
    ptr = top;
    if(top == NULL){
        printf("\n STACK IS EMPTY");
    }else{
        while(ptr != NULL){
            printf("\n %d", ptr->data);
            ptr = ptr->next;
        }
    }
    return top;
}


struct stack *pop(struct stack *top){
    struct stack *ptr;
    ptr = top;
    if(top == NULL){
        printf("\n STACK IS UNDERFLOW");
    }else{
        top = top->next;
        printf("\n the value being deleted is %d", ptr->data);
        free(ptr);
    }
    return top;
}

int peek(struct stack *top){
    if(top == NULL){
        return -1;
    }else{
        return top->data;
    }
}

int main(){
    int val, option;
    do{
        printf("\n *** LINKED STACK ****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n\n PLEASE ENTER YOUR OPTION : ");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("\n Enter the value that wanna be stored : ");
                scanf("%d", &val);
                top = push(top, val);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                val = peek(top);
                if(val != -1){
                    printf("\n The value that stored at the top of the stack is %d ", val);
                }else{
                    printf("\n STACT IS EMPTY");
                }
                break;
            case 4:
                top = display(top);
                break;
        }
    }while(option != 5);
    return 0;
}


