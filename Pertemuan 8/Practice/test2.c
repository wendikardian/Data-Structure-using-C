#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element{
    int nim;
    char nama[20];
    int nilai;
    struct element *next;
    struct element *prev;
}element;

element *list = NULL;

element *createElement(){
    element *baru = (element *) malloc(sizeof(element));
    int nim;
    char nama[20];
    int nilai;

    scanf("%d", &nim);
    scanf("%s", &nama);
    scanf("%d", &nilai);

    baru->nim = nim;
    strcpy(baru->nama, nama);
    baru->nilai = nilai;

    baru->next = NULL;
    baru->prev = NULL;
}

void addAwal(){
    element *baru = createElement();
    baru->next = list;
    if(list != NULL){
        list->prev = baru;
    }
    list = baru;
    baru = NULL;
}

void cetak(){
    element *temp = list;
    int count = 0, total = 0;
    while(temp != NULL){
        printf("%d\n", temp->nim);
        printf("%s\n", temp->nama);
        printf("%d\n", temp->nilai);
        total += temp->nilai;
        count++;
        temp = temp->next;
    }
    printf("rata2 nilai : %d", total/count);
}

int main(){
    int i, j;
    scanf("%d", &j);
    for(i = 0; i < j; i++){
        addAwal();
    }

    cetak();

    return 0;
}