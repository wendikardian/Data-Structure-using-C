#include <stdio.h>
#include <malloc.h>
#include <string.h>


typedef struct Element{
    char gender[10];
    char nama[15];
    int usia;
    struct Element *next;
}element;

element *createElement( char nama[15],char gender[10], int usia){
    element *New;
    New =(element *)malloc(sizeof(element));
    strcpy(New->gender, gender);
    strcpy(New->nama, nama);
    New->usia = usia;
    New->next =NULL;
    return New;
}

void cetakList(element *MyList){
    element * temp;
    temp=MyList;
    printf("%s\n%s\n%d\n",temp->nama, temp->gender, temp->usia);
    do{
        temp=temp->next;
        printf("%s\n%s\n%d\n",temp->nama, temp->gender, temp->usia);
    }while(temp->next!=NULL);
}

void addAkhir(char nama[], char gender[], int usia, element *myList){
    element *New, *temp;
    New = createElement(nama, gender, usia);
    myList->next=New;
    New=NULL;
}

void addAwal(char nama[],char gender[], int usia, element *myList) {
    // printf("%d --------- ", myList->usia);
	element *New;
    New = createElement(nama, gender, usia);
    New->next = myList;
    myList = New;
    New = NULL;
}

void addData(char nama[], char gender[], int usia, element *myList){
    element *temp, *New;
    temp=myList;
    if(temp->next == NULL){
        if(temp->usia >usia){
            addAkhir(nama, gender, usia, myList);
        }else{
            New = createElement(nama, gender, usia);
            New->next = myList;
            myList = New;
            New = NULL;
        }
        
    }else{
        // temp->next = NULL;
        
    }
    // while(temp->next != NULL){
    //     temp = temp->next;

    // }
    // if(usia == temp->usia){
    //     if(strcmp(gender, "Laki-Laki") == 0){
    //     New->next = temp->next;
    //     temp->next = New;
    // }else if(strcmp(gender, "Perempuan") == 0 && strcmp(temp->gender, "Perempuan") == 0){
    //     New->next = temp->next;
    //     temp->next = New;
    // }
    // }
    

}

int main(){
    element *New = NULL;
    int usia;
    char gender[10], nama[15];
    int option, total,i;
    // if(strcmp("Wendi", "Wendi") == 1){
    //     printf("\nYes\n");
    // }else{
    //     printf("No\n");
    // }
    strcpy(gender, "Perempuan");
    strcpy(nama, "Wendi");
    usia =70;
    New  = createElement(nama, gender,usia);
    strcpy(gender, "Perempuan");
    strcpy(nama, "Hanny");
    usia =80;
    addData(nama, gender,usia, New);
    cetakList(New);
    
    // scanf("%d",&option);
    // do{
    //     if(option == 1){
    //         scanf("%d",&total);
    //         for(i = 0; i< total; i++){
    //             if(New == NULL){
    //                 // scanf(" %s",nama);
    //                 // scanf("%s",gender);
    //                 scanf("%d",&usia);
    //                 // New = createElement(gender, nama, usia);
    //             }else{

    //             }
    //         }
    //     }else if(option == 2){

    //     }else if(option == 3){

    //     }
    // }while(option != 0);
    
    return 0;
}

