#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element{
    int id;
    char nama[20];
    struct element* next;
    struct element* prev;
}Element;

Element * createElement(int id, char nama[]){
    Element* new_node = (Element*) malloc(sizeof(Element));
    new_node->id = id;
    strcpy(new_node->nama, nama);
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

Element *addAwal(Element *start, int id, char nama[]){
    Element *new_node = createElement(id, nama);
    new_node->next = start;
    start->prev = new_node;
    return new_node;
}

Element *addAkhir(Element *start, int id, char nama[]){
    Element *new_node = createElement(id, nama);
    Element *ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
    return start;
}

void displayData(Element *start){
    Element *ptr = start;
    while(ptr!= NULL){
        printf("%d\n", ptr->id);
        printf("%s\n", ptr->nama);
        ptr = ptr->next;
    }
}

int main(){
    Element *start;
    int id;
    char nama[20];
    scanf("%d", &id);
    scanf("%s", nama);
    start = createElement(id, nama);
    do{
        scanf("%d", &id);
        if(id != 0){
            scanf("%s", nama);
            // start = addAwal(start, id, nama);
            start = addAkhir(start, id, nama);
        }
    }while(id != 0);
    displayData(start);
    return 0;
}