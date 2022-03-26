#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Element{
    int id;
    char nama[15];
    int usia;
    struct Element * next;
}element;

element *New = NULL; 

element * createElement(int id, char nama[15], int usia){
    element * New ;
    New = (element *) malloc (sizeof(element));
    New->id = id;
    strcpy (New->nama, nama);
    New->usia = usia;
    New->next = NULL;
    return New;
}

void addAwal(int id, char nama[15], int usia, element **myList) {
	element * New;
    New = createElement(id, nama, usia);
    New->next = *myList;
    *myList = New;
    New = NULL;
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


void addAfter (int id, char nama[15], int usia,int id2, element *myList) {
    element *temp, *New;
    New = createElement(id, nama, usia);
    temp=myList;
    while(temp->id!=id2 && temp->next!=NULL){
        temp=temp->next;
    }
    if(temp->id==id2){
        New->next=temp->next;
        temp->next=New;
        New=NULL;
    }else{
        printf("Data %d tidak ditemukan\n",id2 );
    }

}


void addBefore(int id, char nama[15], int usia,int id2, element *myList){
    element *New, *temp;
    New = createElement(id, nama, usia);
    temp = myList;
    while(temp->next->id!=id2 && temp->next->next != NULL){
        temp = temp->next;
    }
    if(temp->next->id == id2){
        New->next = temp->next;
        temp->next = New;
        New = NULL;
    }else{
        printf("Data %d tidak ditemukan \n", id2);
    }
}

void hapus(int id, element **myList){
    element *temp, *toDelete;
    temp = *myList;
    if(temp->id == id){
        *myList = temp->next;
        free(temp);
    }else{
        while(temp->next->id != id && temp->next->next != NULL){
        temp = temp->next;
        }
        if(temp->next->id == id){
            toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete);
        }else{
            printf("Data tidak %d tidak di temukan", id);
        }
    }
}

int main(){
    element *New;
    int id, id2;
    char nama[15];
    int usia;
    scanf("%d", &id);
    scanf("%s", nama);
    scanf("%d", &usia);
    New = createElement(id, nama, usia);
    scanf("%d", &id);
    scanf("%s", nama);
    scanf("%d", &usia);
    addAwal(id, nama, usia, &New);
    scanf("%d", &id);
    scanf("%s", nama);
    scanf("%d", &usia);
    addAkhir(id, nama, usia, New);
    scanf("%d", &id);
    scanf("%s", nama);
    scanf("%d", &usia);
    scanf("%d", &id2);
    addAfter(id, nama, usia, id2, New);
    scanf("%d", &id);
    scanf("%s", nama);
    scanf("%d", &usia);
    scanf("%d", &id2);
    addBefore(id, nama, usia, id2, New);
    scanf("%d", &id);
    hapus(id, &New);
    scanf("%d", &id);
    scanf("%s", nama);
    scanf("%d", &usia);
    addAkhir(id, nama, usia, New);
    scanf("%d", &id);
    hapus(id, &New);
    scanf("%d", &id);
    hapus(id, &New);
    cetakList(New);
    return 1;
}