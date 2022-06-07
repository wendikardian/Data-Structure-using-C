#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
	char nama[50];
	int usia;
	char jenis;
}antrian;

typedef struct E{
	antrian data;
	struct E *next;
}element;

typedef struct{
	element *head;
	element *tail;
}queue;

void createEmpty (queue *Q){
	(*Q).head = NULL;
	(*Q).tail = NULL;
}

bool isEmpty(queue Q){
	return Q.head == NULL;
}

int countElement(queue Q){
	int hasil = 0;
	
	if(isEmpty(Q)==0){
		element *temp;
		temp = Q.head;
		
		while(temp != NULL){
			hasil++;
			temp = temp->next;
		}
		free(temp);
	}
	return hasil;
}

void push(char nama[], int usia, char jenis, queue *Q){
	element *newElement;
	newElement=(element*)malloc(sizeof(element));
	strcpy(newElement->data.nama, nama);
	newElement->data.usia = usia;
    newElement->data.jenis = jenis;
	//newElement->data.jenis = jenis;
	newElement->next = NULL;
	
	if(isEmpty(*Q)){
		(*Q).head = newElement;
	}else{
		(*Q).tail->next = newElement;
	}
	(*Q).tail = newElement;
	
	printf("%s\n",newElement->data.nama);
	printf("%d\n",newElement->data.usia);
	printf("%c\n",newElement->data.jenis);
	newElement = NULL;
}

void pop(queue *Q){
	if(isEmpty(*Q)==0){
		element *temp = (*Q).head;
		
		if(countElement(*Q)==1){
			(*Q).head = NULL;
			(*Q).tail = NULL;
		}else{
			(*Q).head = (*Q).head->next;
			temp->next = NULL;
		}
		
		printf("%s telah dihapus\n", temp->data.nama);
//		printf("%d\n",temp->data.usia);
//		printf("%s\n", temp->data.jenis);
		free(temp);
	}else{
		printf("Kosong! \n\n");
	}
}

void cetak(queue Q){
	if(!isEmpty(Q)){
		element *help = Q.head;
		
		while(help != NULL){
			printf("%s \n %d \n %s\n", help->data.nama, help->data.usia, help->data.jenis);
			help= help->next;
		}
	}else{
		printf("Kosong!\n\n");
	}
}

void sortAge(queue Q){
	if(isEmpty(Q)){
		printf("Queue kosong");
	}else{
		int max = 0;
		element *temp = Q.head;
		int min = temp->data.usia;
		int total = 0;
		int count = 0;
		
		while(temp != NULL){
			if(temp->data.usia > max){
				max = temp->data.usia;
			}
			if(temp->data.usia < min){
				min = temp->data.usia;
			}
			total += temp->data.usia;
			count += 1;
			temp = temp->next;
		}
		printf("Rata-rata usia adalah = %d\n", total/count);
		printf("Usia tertinggi adalah = %d\n", max);
		printf("Usia terendah adalah = %d\n", min);
	}
}

int main(){
	int menu=1, hasil, usia;
	char nama[50];
	char jenis;
	queue Q;
	createEmpty(&Q);
	
	while(menu != 0){
		system("cls");
		printf("[1] Masukan Data Baru\n");
		printf("[2] Panggil antrian\n");
		printf("[3] Lihat antrian dan urutan serta rata-rata usia\n");
		printf("[0] Keluar\n");
		
		printf("Masukan pilihan menu anda : ");scanf("%d",&menu);
		
		switch(menu){
			case 1:
				printf(" Nama : ");fflush(stdin);gets(nama);
                printf("%s \n", nama);
				printf(" Usia : ");scanf("%d", &usia);
				printf(" Jenis Kelamin (l/p) :");
                scanf(" %c", &jenis);
				push(nama, usia, jenis, &Q);
				break;
			case 2:
				pop(&Q);
				break;
			case 3:
				cetak(Q);
				sortAge(Q);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Pilihan menu tidak tersedia\n");
				break;
		}
		printf("\n");
		system("pause");
	}
	return 0;
}