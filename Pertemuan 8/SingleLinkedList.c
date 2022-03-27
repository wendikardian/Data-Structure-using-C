#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *start;

struct node* createElement(){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    int number;
    scanf("%d", &number);
    new_node->next = NULL;
    new_node->data = number;
    return new_node;
}

void addAwal(struct node** start){
    if(start == NULL){
        struct node *new_node = createElement();
        *start = new_node;
    }else{
        struct node *new_node = createElement();
        new_node->next = *start;
        *start = new_node;       
    }
}

void addAkhir(struct node* start){
    struct node *new_node = createElement();
    struct node *ptr;
    ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node;
}


void addAfter(struct node* start){
    printf("\nMasukan data yang mana mau di add after : ");
    int data;
    scanf("%d", &data);
    printf("Masukan data : ");
    struct node *new_node = createElement();
    struct node *ptr = start;
    while(ptr->data != data){
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
}

void addBefore(struct node *start){
    int data;
    printf("\nMasukan data yang mau di add before  : ");
    scanf("%d", &data);
    printf("Masukan data : ");
    struct node *new_node = createElement();
    struct node *ptr = start;

    while(ptr->next->data != data){
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
}

void delAwal(struct node **start){
    if(&start == NULL){
        printf("\nthis is empty linked list");
    }else{
        struct node *ptr;
        ptr = *start;
        *start = ptr->next;
        free(ptr);
    }
}

void delAkhir(struct node *start){
    struct node *ptr;
    ptr = start;
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    struct node *ptr2 = ptr->next;
    ptr->next = NULL;
    free(ptr2);
}

void delTengah(struct node *start){
    struct node *ptr;
    ptr = start;
    int data;
    printf("\nMasukan data mana yang mau dihapus : ");
    scanf("%d", &data);
    while(ptr->next->data != data){
        ptr = ptr->next;
    }
    struct node *ptr2;
    ptr2 = ptr->next;
    ptr->next = ptr->next->next;
    free(ptr2);

}

void display(struct node *start){
    struct node *ptr;
    ptr = start;
    while(ptr != NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
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
    printf("\nSetelah delete awal\n");
    delAwal(&start);
    printf("\nSetelah delete akhir\n");
    delAkhir(start);
    display(start);
    printf("\nSetelah delete tengah\n");
    delTengah(start);
    display(start);
    return 0;
}