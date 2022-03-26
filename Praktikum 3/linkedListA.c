// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h> 


typedef struct Element{
    int data;
    struct Element * next;
}element;//ADT

element * createElement(int a){
    element * New ;
    New = (element *) malloc (sizeof(element));//1012
    New->data=a;
    New->next = NULL;
    return New;
}

void AddAkhir(int a,element *MyList){
    element * New, *temp;
    temp=MyList;
    New = createElement(a);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=New;
    New=NULL;
}

void Delete(int a, element * MyList){
    element * temp, *hapus;
    temp=MyList;
    while(temp->next->data!=a && temp->next->next!=NULL){
        temp=temp->next;
    }
    if(temp->next->data==a){
        hapus=temp->next;
        temp->next=hapus->next;
        free(hapus);
    }
     else{
        printf("Data yang dihapus tidak ditemukan\n"); 
     }   
}

void AddAfter(int a,int b, element *MyList){
    element * New, *temp;
    New = createElement(a);
    temp=MyList;
    while(temp->data!=b && temp->next!=NULL){
        temp=temp->next;
    }
    if(temp->data==b){
        New->next=temp->next;
        temp->next=New;
        New=NULL;
    }else{
        printf("Gagal menambah %d, nilai %d tidak ditemukan",a,b );
    }
    
}

void cetak(element *MyList){
    element * temp;
    temp=MyList;
    printf("%d\n",temp->data);
    do{
        temp=temp->next;
        printf("%d\n",temp->data);
    }while(temp->next!=NULL);
}

int main() {
    element * myList;
    myList=createElement(10);
    AddAkhir(13,myList);
    AddAkhir(15,myList);
    AddAkhir(8,myList);
    cetak(myList);
    printf("Setelah hapus\n");
    Delete(10,myList);
    cetak(myList);
    return 0;
}