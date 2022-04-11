#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Mahasiswa{
	int id;
	char nama[20];
	struct data *next;
	struct data *prev;
	
}data;

data *Mahasiswa = NULL;

data *createList(int id, char nama[]){
	data *new=(data *)malloc(sizeof(data));
	new->id =id;
	strcpy(new->nama,nama);
	new->next =NULL;
	new->prev =NULL;
	
	return new;
}

void addFirst(int id, char nama[]){
	data *new = createList(id,nama);
	new->next = Mahasiswa;
	Mahasiswa->prev = new;
    Mahasiswa = new;
}

void print(){
	data *temp= Mahasiswa;
	while(temp !=NULL){
		printf("%d\n%s", temp->id, temp->nama);
		temp->next;
	}
}

int main(){
	int id;
	do{
		scanf("%d", &id);
		if(id!=0){
			char nama[20];
			scanf("%s", nama);
			if(Mahasiswa==NULL){
				Mahasiswa = createList(id,nama);
			}
			else{
				addFirst(id, nama);
			}
		}
	}while(id!=0);
	return 0;
}