// Wendi Kardian (2100016) - Pendidikan Ilmu Komputer A
// Dynamic Queue Practice


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>


// Struct buat data identitas queue
typedef struct data{
    char name[50];
    int age;
}Data;


// element dari queue yang berisikan next antrian sama datanya
typedef struct element{
    Data data;
    struct element * next;
}Element;


// adt untuk queue yang berisikan head sama tailnya
typedef struct queue{
    Element * head;
    Element * tail;
}Queue;


// inisialisiasi queue yang kosong
void createEmpty(Queue *Q){
    (*Q).head = NULL;
    (*Q).tail = NULL;
}

// function untuk mengecek apakah queue kosong atau tidak yang mengembalikan nilai boolean
bool isEmpty(Queue Q){
    return Q.head == NULL;
}


// function untuk menghitung banyaknya data dalam queue
int countElement(Queue Q) {
	int result = 0;
	if(isEmpty(Q) == 0) {
		Element *temp;
		temp = Q.head;
		
		while(temp != NULL) {
			result++;
			temp = temp->next;
		}
		free(temp);
	}
	return result;
}

// function untuk menambahkan data setelah tail dari queue tersebut
void addData(char newName[], int xusia, Queue *Q) {
	Element *ptr;
	ptr = (Element*)malloc(sizeof(Element));
	strcpy(ptr->data.name, newName);
	ptr->data.age = xusia;
	ptr->next = NULL;
	
	if (isEmpty(*Q)){ //apabila queue masih kosong
		(*Q).head = ptr;
	} 
	else{ //menambahkan data diakhir queue setelah tail
		(*Q).tail->next = ptr;
	}
	(*Q).tail = ptr;
	printf("\nData that has been added: %s, %d\n",ptr->data.name, ptr->data.age);
	ptr = NULL;
}


// function untuk menghapus data dari queue atau memanggil antrian
void delete(Queue *Q){
	if(!isEmpty(*Q)){ 
		Element *temp = (*Q).head;
		
		if(countElement(*Q) == 1){ // apabila banyaknya data dalam queue hanya 1
			(*Q).head = NULL;
			(*Q).tail = NULL;
		}
		else{  // kondisi untuk mengubah posisi head kealamat next nya
			(*Q).head = (*Q).head->next;
			temp->next = NULL;
		}
		
		printf("\nData that has been deleted : %s, %d\n",temp->data.name, temp->data.age);
		
		free(temp);
	}
	else{ // apabila queue kosong
		printf("Queue Empthy! \n\n");
	}
}


// prosedur untuk menampilkan semua data dalam queue
void display(Queue Q){
	if(!isEmpty(Q)){
		Element *ptr = Q.head;
		int i = 1;
		
		printf("\n-------- Queue Data ---------------- \n\n");
		
		while(ptr != NULL){
			printf("%d, (nama: %s, usia: %d) \n",i, ptr->data.name, ptr->data.age);
			ptr = ptr->next;
			i++;
		}
	}
	else{
		printf("Queue empty!\n\n");
	}
}

// prosedur untuk menentukan data maksimum minimum serta rata rata dari data age dalam queue
void minMaxAge(Queue Q){
	if(isEmpty(Q))	{
		printf("Queue is Empty");
	}else{
		int max = 0;
		Element *ptr = Q.head;
		int min = ptr->data.age;
		int total = 0;
		int count = countElement(Q);
		while(ptr != NULL){
			if(ptr->data.age > max){
				max = ptr->data.age;
			}
			if(ptr->data.age < min){
				min = ptr->data.age;
			}
			total += ptr->data.age;
			ptr = ptr->next;
		}
		printf("The Maximum age is : %d \n", max);
		printf("The Minimum age is : %d \n", min);
		printf("The average age is : %d \n", total/count);
	}
}

// prosedur untuk mengubah data dalam queue
void changeData(Queue Q){
	int dataDidntFound = 0;
	if(isEmpty(Q)){ //  apabila queue kosong
		printf("Queue us Empty\n");
	}else{
		char name[50];
		printf("Enter the name of person that u want modify their name : ");
		fflush(stdin);gets(name);
		Element *ptr = Q.head;
		while((strcmp(ptr->data.name, name) != 0)){ //mencari data berdasarkan nama
			if(ptr->next == NULL && (strcmp(ptr->data.name, name) != 0) ){
				printf("Data did'nt exist");
				dataDidntFound = 1;
				break;
			}
			ptr =  ptr->next;
		}
		if(dataDidntFound != 1){ // apabila data ditemukan
            char editName[50];
            int editAge;
            printf("Enter the new name : ");
            fflush(stdin);gets(editName);
            printf("Enter the new age : ");
            scanf("%d", &editAge);
            strcpy(ptr->data.name, editName);
            ptr->data.age = editAge;
		}
		
	}
}

int main(){
	int option = 1,age;
	char name[50];
	Queue Q;
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
		printf("0. Exit\n");
		printf("Your option : ");scanf("%d",&option);
		
		switch(option){
			case 1:
				printf("\n === Please input the data ==== \n\n");
				printf(" Name : ");
                fflush(stdin);
                gets(name);
				printf(" Age : ");
                scanf("%d",&age);
				addData(name,age,&Q);
				break;
			case 2:
				delete(&Q);
				break;
			case 3:
				display(Q);
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