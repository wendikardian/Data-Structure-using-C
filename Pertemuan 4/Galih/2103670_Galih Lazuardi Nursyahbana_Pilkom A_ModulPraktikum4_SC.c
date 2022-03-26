// Galih Lazuardi Nursyahbana 2103670
// Pendidikan Ilmu Komputer
// Program A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element{
	char nama[25], gender[10];
	int id, usia;
	struct Element *next;
}element;

element *createElement(char nama[], char gender[], int usia, int id){
	element *baru = (element*)malloc(sizeof(element));
	strcpy(baru->nama, nama);
	strcpy(baru->gender, gender);
	baru->usia = usia;
	baru->id = id;
	baru->next = NULL; 
	
	return baru;
}

void addAwal(char nama[], char gender[], int usia, int id, element **ptr){
    element *tambah = createElement(nama, gender, usia, id);
    tambah->next = *ptr;
    *ptr = tambah;
}

void addAfter(char nama[], char gender[], int usia, int id, int urut, element *ptr){
	element *baru = createElement(nama, gender, usia, id), *temp = ptr;
    while(temp->next != NULL && temp->id != urut) {
        temp = temp->next;
    }
    baru->next = temp->next;
    temp->next = baru;
    baru = NULL;
}

void addBefore(char nama[], char gender[], int usia, int id, int urut, element *ptr){
    element *baru = createElement(nama, gender, usia, id), *temp = ptr;
    while(temp->next->next != NULL && temp->next->id != urut) {
        temp = temp->next;
    }
    baru->next = temp->next;
    temp->next = baru;
    baru = NULL;
}

void addAkhir(char nama[], char gender[], int usia, int id, element *ptr){
	element *tambah = createElement(nama, gender, usia, id), *help = ptr;
	while(help->next != NULL){ 
		help = help->next;
	}
	help->next = tambah;
	tambah = NULL;
}

void hapus(element **ptr){ 
	if(*ptr == NULL){
        printf("Daftar List Kosong\n");
    } else {
        element *hapus, *temp = *ptr;
        *ptr = temp->next;
        free(temp);
    }
}

void cetakList(element *list){
	element *ptr = list;
	if(list == NULL) {
        printf("Daftar List Kosong\n");
    }
	else{
		while(ptr != NULL) {
			printf("\n%s\n%s\n%d\n", ptr->nama, ptr->gender, ptr->usia);
			ptr = ptr->next;
		}
	}
}

void insert(char nama[], char gender[], int usia, int id, element **ptr) {
    element *temp = *ptr;
    while(temp->next != NULL && temp->usia > usia){
        temp = temp->next;
    }
    if(temp->usia > usia){
		addAkhir(nama, gender, usia, id, *ptr);
	}
    else if(temp->usia < usia){
        if(temp == *ptr){
			addAwal(nama, gender, usia, id, &*ptr);
		}
        else{
			addBefore(nama, gender, usia, id, temp->id, *ptr);
		}
    }
    else{
        if((gender[0] == 'P' || gender[0] == 'p') && (temp->gender[0] == 'L' || temp->gender[0] == 'l')){
            if(temp == *ptr){ 
				addAwal(nama, gender, usia, id, &*ptr);
			} 
        	else{
				addBefore(nama, gender, usia, id, temp->id, *ptr); }
        	}
        else{ 
			addAfter(nama, gender, usia, id, temp->id, *ptr);
		}
    }
}

void menu(int *opsi1, int *opsi2){
	int input1, input2;
	scanf("%d", &input1);
	if(input1==0){
		*opsi1 = 0;
	}
	else if(input1==1){
		*opsi1 = 1;
		scanf("%d", &input2);
		*opsi2 = input2;
	}
	else if(input1==2){
		*opsi1 = 2;
		scanf("%d", &input2);
		*opsi2 = input2;
	}
	else if(input1==3){
		*opsi1 = 3;
	}
}

int main(){
	element *New = NULL;
	int mulai=1, count=0, id=0, opsi1, opsi2, i, urut, usia;
	char nama[15], gender[10];
	
	while(mulai == 1){
		menu(&opsi1, &opsi2);
		
		if(opsi1 == 0){
			mulai=0;
		}
		if(opsi1 == 1){
            for(i=0; i<opsi2; i++){
            	scanf("%s", nama); 
                scanf("%s", gender); 
                scanf("%d", &usia); 
                if(count == 0){
					New = createElement(nama, gender, usia, id);
				}
                else{
					insert(nama, gender, usia, id, &New);
				}
                id++;
                count++;
            }
		}
		if(opsi1 == 2){
			for(i=0; i<opsi2; i++){
				hapus(&New);
				if(count != 0){
					count--; 
				}
			}
		}
		if(opsi1 == 3){
			cetakList(New);
		}
	}
	
	return 0;
}
