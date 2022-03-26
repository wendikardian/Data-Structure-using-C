#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Element{
    int id;
    char nama[15];
    int usia;
    struct Element * next;
}element;


element * createElement(int id, char nama[15], int usia){
    element * New ;
    New = (element *) malloc (sizeof(element));
    New->id = id;
    strcpy (New->nama, nama);
    New->usia = usia;
    New->next = NULL;
    return New;
}

void cetakList(element *MyList){
    element * temp;
    temp=MyList;
    printf("%d %s %d \n",temp->id, temp->nama, temp->usia);
    do{
        temp=temp->next;
        printf("%d %s %d \n",temp->id, temp->nama, temp->usia);
    }while(temp->next!=NULL);
}


void addAkhir(int id, char nama[15], int usia, element *MyList){
    element *New, *temp;
    New = createElement(id, nama, usia);
    temp=MyList;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=New;
    New=NULL;
}

void reverseList(element **myList){
    element *prev = NULL;
    element *current = *myList;
    element *next;
    while(current != NULL){
        next = current->next;
        current->next= prev;
        prev=current;
        current = next;
    }
    *myList = prev;
}

int main(){
    element * New;
    int id, n, i;
    char nama[15];
    int usia;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &id);
        scanf("%s", nama);
        scanf("%d", &usia);
        if(i==0){
            New = createElement(id, nama, usia);
        }else{
            addAkhir(id, nama, usia, New);
        }
    }
    reverseList(&New);
    cetakList(New);
    return 1;
}