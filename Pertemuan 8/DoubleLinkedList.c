#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
    struct node * prev;
};

struct node* start;

struct node* createElement(){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    int data;
    scanf("%d", &data);
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}



int main(){
    start = createElement();
    printf("%d", start->data);    
    return 0;
}
