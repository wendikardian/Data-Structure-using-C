#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct element{
    int data;
    struct element *next;
    struct element *prev;
}Element;

Element *createElement(int data){
    Element *new_node = (Element *)malloc(sizeof(Element));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
}

void addAkhir(Element *start, int data){
    Element *new_node = createElement(data);
    Element *ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    new_node->prev = ptr;
    ptr->next = new_node;

}


void displayData(Element *start){
    Element *ptr =start;
    while(ptr!= NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }

}


int main(){
    Element *start;
    start =createElement(1);
    addAkhir(start,2);
    addAkhir(start,3);
    addAkhir(start,4);
    addAkhir(start,5);
    addAkhir(start,6);
    addAkhir(start,7);
    addAkhir(start,8);
    addAkhir(start,9);
    displayData(start);
    printf("\n\n");
    Element *ptr = start;
    int total,i;
    char instruction[10];
    scanf("%d",&total);
    for(i = 0; i<total; i++){
        scanf("%s", instruction);
        if(strcmp(instruction, "Next") == 0){
            ptr = ptr->next;
        }else if(strcmp(instruction, "Prev") == 0){
            ptr = ptr->prev;
        }else{
            printf("Invalid input");
        }
    }
    printf("%d", ptr->data);
    
    return 0;
}