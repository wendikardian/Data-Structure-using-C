#include<stdio.h>
#include<stdlib.h>
#define MAX 10


int queue[MAX];
int front = -1; 
int rear =-1;

void insert(){
    int num;
    printf("Please enter the number ");
    scanf("%d", &num);
    if(rear == MAX -1){
        printf("\nQUEUE OVERFLOW");
    }else if(front == -1 && rear== -1){
        front = 0;
        rear = 0;
        queue[rear] = num;
    }else{
        rear++;
        queue[rear] = num;
    }
}


int delete_element(){
    int val;
    if(front == -1|| front>rear){
        printf("\nQUEUE UNDERFLOW");
        return -1;
    }else{
        val = queue[front];
        front++;
        if(front > rear ){
            front = -1;
            rear = -1;
        }
        return val;
    }
}


int peek(){
    if(front == -1 || front>rear){
        printf("\nQUEUE IS EMPTY");
        return -1;
    }else{
        return queue[front];
    }
}


void display(){
    int i;
    printf("\n");
    if(front == -1 || front>rear){
        printf("\nQUEUE IS EMPTY");
    }else{
        for(i = front; i <= rear; i++){
            printf("%d\t", queue[i]);
        }
    }
}


int main(){
    int option, val;
    do{
        printf("\n\n**MAIN MENU**\n");
        printf("\n1. Insert an Element");
        printf("\n2. Delete an Element");
        printf("\n3. Peek");
        printf("\n4. Display the queue");
        printf("\n5. Exit");
        printf("\n\nPlease enter your option");
        scanf("%d", &option);
        switch(option){
            case 1: 
                insert();
                break;
            case 2: 
                val = delete_element();
                if(val != -1){
                    printf("\nThe number of the queue that has been deleted is %d", val);
                }
                break;
            case 3: 
                val = peek();
                if(val != -1){
                    printf("The peek of the queue is %d", val);
                }
                break;
            case 4: 
                display();
                break;
            case 5: 
                printf("\nBye-bye");
                break;
            default:
                printf("\nEnter the right number");
                break;
        }
    }while(option != 5);
    return 0;
}