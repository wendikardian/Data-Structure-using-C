// Galih Lazuardi Nursyahbana 2103670
// Pendidikan Ilmu Komputer
// Program Latihan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char nama[25];
	char nim[10];
	struct Node *next;
}node;

node *Element;

node *createList(char NAMA[], char NIM[]){
	node *baru = (node*)malloc(sizeof(node));
	strcpy(baru->nama, NAMA);
	strcpy(baru->nim, NIM);
	baru->next = NULL; 
	
	return baru;
}

void addFirst(char NAMA[], char NIM[]){
	node *tambah = createList(NAMA, NIM);
	tambah->next = Element; 
	Element = tambah; 
	tambah = NULL; 
}

void addMid(char NAMA[], char NIM[], int urut){
	int i;
	node *help = Element, *tambah = createList(NAMA, NIM); 
	for(i=1; i<urut; i++){ 
		help = help->next;
	}
	tambah->next = help->next;
	help->next = tambah;
	tambah = NULL;
	help = NULL; 
}

void addLast(char NAMA[], char NIM[]){
	node *tambah = createList(NAMA, NIM), *help = Element;
	while(help->next != NULL){ 
		help = help->next;
	}
	help->next = tambah;
	tambah = NULL;
}

void deleteFirst(){ 
	node *help = Element;  
	if (help == NULL){
		printf("Data tidak ada"); 
	}
	else{
		Element = help->next;
		free(help);
	}
}

void deleteMid(int urut){
	int count=1;
	if(Element == NULL){
		printf("Data tidak ada"); 
	} 
	else{
		node *hapus, *prev_hapus = Element; 
		while(prev_hapus){
			if(count==urut-1){ 
				hapus=prev_hapus->next; 
				prev_hapus->next=hapus->next; 
				free(hapus); 
				prev_hapus = NULL;
				break;
			}
			count++; 
			prev_hapus=prev_hapus->next;                       
		}	
	}
}

void deleteLast(){
	if(Element == NULL) {
		printf("Data tidak ada"); 
	} 
	else{
		node *prev_hapus;
		node *hapus = Element;
		while (hapus->next != NULL){ 
			 prev_hapus = hapus;
			 hapus = hapus->next;
		}
		prev_hapus->next = NULL;
		free(hapus);
		prev_hapus = NULL;
	}
}

void printList(){
	node *ptr;
	ptr = Element;
	while(ptr != NULL) {
		printf("%s %s\n",ptr->nim, ptr->nama);
		ptr = ptr->next;
	}
}

int main(){
	int urut;
	
	printf("Nilai Node Element Awal\n");
	Element = createList("Galih", "1903480");
	printList(Element);
	printf("\n");
	
	printf("Tambah Awal\n");
	addFirst("Wendi", "1900555");
	printList(Element);
	printf("\n");
	
	printf("Tambah Tengah\n");
	addMid("Nazwa", "1900666", 1);
	printList(Element);
	printf("\n");
	
	printf("Tambah Akhir\n");
	addLast("Aldi", "1900777");
	addLast("Kardian", "1900999");
	printList(Element);
	printf("\n");
	
	printf("Delete Awal\n");
	deleteFirst();
	printList(Element);
	printf("\n");
	
	printf("Delete Mid\n");
	deleteMid(2);
	printList(Element);
	printf("\n");
	
	printf("Delete Last\n");
	deleteLast();
	printList(Element);
	printf("\n");
	
	return 0;
}
