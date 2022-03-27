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

void addAwal(struct node **start){
    struct node *new_node = createElement();
    if(*start == NULL){
        *start = new_node;
    }else{
        new_node->prev = NULL;
        new_node->next= *start;
        *start= new_node;
    }
}

void addAkhir(struct node *start){
    struct node *new_node = createElement();
    struct node *ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;
}

void addAfter(struct node *start){
    int data;
    printf("\nMasukan data mana yang mau di add after : ");
    scanf("%d", &data);
    printf("\nMasukan data : ");
    struct node *new_node = createElement();
    struct node *ptr = start;
    while(ptr->data != data){
        ptr = ptr->next;
    }
    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;

}


void addBefore(struct node *start){
    int data;
    printf("\nMasukan data mana yang mau di add before : ");
    scanf("%d", &data);
    printf("\nMasukan data : ");
    struct node *new_node = createElement();
    struct node *ptr = start;
    while(ptr->data != data){
        ptr = ptr->next;
    }
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;
}

void delAkhir(struct node *start){
    struct node *ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
}

void delAwal(struct node **start){
    struct node *ptr = *start;
    ptr->next->prev = NULL;
    *start = ptr->next;
    free(ptr);
}

void delMiddle(struct node *start){
    int data;
    printf("\nMasukan data mana yang akan di hapus : ");
    scanf("%d", &data);
    struct node *ptr = start;
    while(ptr->data != data){
        ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
}

void display(struct node *start){
    struct node *ptr;
    ptr = start;
    while(ptr!= NULL){
        printf("%d\t", ptr->data);
        ptr= ptr->next;
    }
}



int main(){
    start = createElement();
    addAwal(&start);
    addAkhir(start);
    addAkhir(start);
    display(start);
    addAfter(start);
    display(start);
    addBefore(start);
    display(start);
    printf("\nSetelah delete akhir\n");
    delAkhir(start);
    display(start);
    printf("\nSetelah delete awal\n");
    delAwal(&start);
    display(start);
    delMiddle(start);
    display(start);
    return 0;
}
