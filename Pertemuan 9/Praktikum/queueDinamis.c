#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// bikin struk data
typedef struct{
	char nama[50];
	int usia;
}Data;

//buat tipe data baru elemen
typedef struct E{
	Data data;
	struct E *next;
}Element;

//buat tipe data queue
typedef struct{
	Element *head;
	Element*tail;
}queue;

//ini untuk mengosongkan queue
void createEmpty(queue *Q){
	(*Q).head = NULL;
	(*Q).tail = NULL;
}

//periksa queue kosong atau engga
bool isEmpty(queue Q){
	return Q.head == NULL;
}

//menghitung element yang ada dalam queue
int countElement(queue Q) {
	int hasil = 0;
	if(isEmpty(Q) == 0) {
		Element *temp;
		temp = Q.head;
		
		while(temp != NULL) {
			hasil++;
			temp = temp->next;
		}
		free(temp);
	}
	return hasil;
}

//masukan data baru dalam queue
void push(char xnama[], int xusia, queue *Q) {
	Element *baru;
	baru = (Element*)malloc(sizeof(Element));
	strcpy(baru->data.nama, xnama);
	baru->data.usia = xusia;
	baru->next = NULL;
	
	if (isEmpty(*Q)){
		(*Q).head = baru;
	}
	else{
		(*Q).tail->next = baru;
	}
	(*Q).tail = baru;
	
	printf("\n[enqueue: %s, %d]\n",baru->data.nama, baru->data.usia);
	
	baru = NULL;
}

//hapus data dalam queue
void pop(queue *Q){
	if(!isEmpty(*Q)){
		Element *temp = (*Q).head;
		
		if(countElement(*Q) == 1){
			(*Q).head = NULL;
			(*Q).tail = NULL;
		}
		else{
			(*Q).head = (*Q).head->next;
			temp->next = NULL;
		}
		
		printf("\n[dequeue: %s, %d]\n",temp->data.nama, temp->data.usia);
		
		free(temp);
	}
	else{
		printf("Kosong! \n\n");
	}
}


//print data queue
void print(queue Q){
	if(!isEmpty(Q)){
		Element *bantu = Q.head;
		int i = 1;
		
		printf("\n[print] ___________________________________\n\n");
		
		while(bantu != NULL){
			printf("%d, (nama: %s, usia: %d) \n",i, bantu->data.nama, bantu->data.usia);
			bantu = bantu->next;
			i++;
		}
	}
	else{
		printf("Kosong!\n\n");
	}
}


void minMaxAge(queue Q){
	if(isEmpty(Q))	{
		printf("Queue is Empty");
	}else{
		int max = 0;
		Element *ptr = Q.head;
		int min = ptr->data.usia;
		int total = 0;
		int count = 0;
		while(ptr != NULL){
			if(ptr->data.usia > max){
				max = ptr->data.usia;
			}
			if(ptr->data.usia < min){
				min = ptr->data.usia;
			}
			total += ptr->data.usia;
			count += 1;
			ptr = ptr->next;
		}
		printf("The Maximum age is : %d \n", max);
		printf("The Minimum age is : %d \n", min);
		printf("The average age is : %d \n", total/count);
	}
}

void changeData(queue Q){
	if(isEmpty(Q)){
		printf("Queue us Empty\n");
	}else{
		char name[50];
		printf("Enter the name of person that u want modify their name : ");
		fflush(stdin);gets(name);
		Element *ptr = Q.head;
		while((strcmp(ptr->data.nama, name) != 0)){
			ptr =  ptr->next;
		}
		if(ptr != NULL){
			char editName[50];
			int editAge;
			printf("Enter the new name : ");
			fflush(stdin);gets(editName);
			printf("Enter the new age : ");
			scanf("%d", &editAge);
			strcpy(ptr->data.nama, editName);
			ptr->data.usia = editAge;
		}else{
			printf("The name out of the queue");
		}
	}
}

int main(){
	int option = 1,usia, hasil;
	char nama[50];
	queue Q;
	createEmpty(&Q);
	
	while (option != 0) {
		system("cls");
		printf("***************************************************************\n");
		printf("**                     QUEUE APPLICATION                     **\n");
		printf("***************************************************************\n\n");
		printf("1. Enter new data\n");
		printf("2. Pop data \n");
		printf("3. Display the data\n");
		printf("4. View max age, min age, and average age\n");
		printf("5. Edit the data\n");
		printf("0. Exitr\n");
		
		printf("Your option : ");scanf("%d",&option);
		
		switch(option){
			case 1:
				printf("\n----------------------------------------------------------------\n\n");
				printf(" Name : ");fflush(stdin);gets(nama);
				printf(" Age : ");scanf("%d",&usia);
				
				push(nama,usia,&Q);
				break;
			case 2:
				pop(&Q);
				break;
			case 3:
				print(Q);
				break;
			case 4:
				minMaxAge(Q);
				break;
			case 5:
				changeData(Q);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Invalid input\n");
				break;
		}
		printf("\n");
		system("pause");
	}
	
	return 0;
}