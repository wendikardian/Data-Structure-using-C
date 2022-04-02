#include<stdio.h>
#include<stdlib.h>

typedef struct element{
    int data;
    struct element *next;
}Element;

Element* createElement(){
    Element *new_node = (Element *)malloc(sizeof(Element));
    int data;
    printf("Masukan data : ");
    scanf("%d", &data);
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void addAwal(Element **start){
    Element *new_node = createElement();
    new_node->next = *start;
    *start = new_node;
}

void addAkhir(Element *start){
    Element *new_node = createElement();
    Element *ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node;
}

void addAfter(Element *start){
    int data;
    printf("\nMasukan data yang bakal dijadiin acuan add After : ");
    scanf("%d", &data);
    Element *new_node = createElement();
    Element *ptr = start;
    while(ptr->data != data){
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
}

void addBefore(Element *start){
    int data;
    printf("\nMasukan data yang bakal dijadiin acuan add Before : ");
    scanf("%d", &data);
    Element *new_node = createElement();
    Element *ptr = start;
    while(ptr->next->data != data){
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
}

void displayData(Element *start){
    Element *ptr = start;
    printf("\n\n Data : ");
    while(ptr != NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

void delAwal(Element **start){
    Element *ptr = *start;
    *start = ptr->next;
    free(ptr);
}

void delAkhir(Element *start){
    Element *ptr = start;
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    Element *ptr2 = ptr->next;
    ptr->next = NULL;
    free(ptr2);
}

void delData(Element *start){
    Element *ptr = start;
    int data;
    printf("\nMasukan data mana yang mau di hapus : ");
    scanf("%d", &data);
    while(ptr->next->data != data){
        ptr = ptr->next;
    }
    Element *ptr2= ptr->next;
    ptr->next = ptr2->next;
    free(ptr2);
}

int main(){
    Element *start;
    start = createElement();
    addAwal(&start);
    addAwal(&start);
    addAkhir(start);
    displayData(start);
    addAfter(start);
    displayData(start);
    addBefore(start);
    displayData(start);
    delAwal(&start);
    displayData(start);
    delAkhir(start);
    displayData(start);
    delData(start);
    displayData(start);
    
    return 0;
}