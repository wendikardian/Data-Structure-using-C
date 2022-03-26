#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Single linked list
typedef struct {
	int nim;
	struct node *next;
}node;

//membuat linked list
node *createList(int NIM) {
	node *baru;
	baru = (node*)malloc(sizeof(node)); //alokasikan memori sebesar node struct
	baru->nim = NIM; //isi atribut nim
	baru->next = NULL; //isi alamat yang menunjukkan node berikutnya
	
	return baru;
}

//tambah linked list di awal
void addfirst (int NIM, node **ptr) {
	node *tambah;
	tambah = createList(NIM);
	tambah->next = *ptr; //isi variabel pointer tambah dengan alamat element yang merupakan lingked list utama
	*ptr = tambah; //ubah nilai element menjadi tambah, sehingga pointer awal tetap pada element
	tambah = NULL; //kosongkan kembali nilai tambah
}

void deleteFirst (node **ptr) { //pointer dlm pointer
	node *hapus; 
	node *help = *ptr; 
	if (help == NULL) {
		printf("Data tidak ada"); 
	}
	else {
		*ptr = help->next;
		hapus->next = NULL;
		free(hapus);
		help = NULL;
	}
}

void deleteMid(int urut, node **ptr){
	int count=1;
	if (*ptr == NULL) {
		printf("Data tidak ada"); 
	} 
	else {
		node *hapus;
		node *prev_hapus = *ptr;
		while(prev_hapus){
			//1 urutan yg mau dihapus 2
			//2 urutan yg mau dihapus 3 -1 2
			if(count==urut-1){ //berhenti di posisi sebelum node yang akan dihapus
				hapus=prev_hapus->next; //hapus menjadi node setelah bantu
				prev_hapus->next=hapus->next; //bantu->next mengarah sama seperti hapus->next
				free(hapus); 
				prev_hapus = NULL;
				break;
			}
			count++; //2++
			prev_hapus=prev_hapus->next;                       
		}	
	}
}

void deleteLast(node **ptr){
	if (*ptr == NULL) {
		printf("Data tidak ada"); 
	} else {
		node *prev_hapus;
		node *hapus = *ptr;
		//node *akhir = *ptr;
		while (hapus->next != NULL) { //periksa dan telusuri nilai variabel pointer suatu list itu kosong
			 prev_hapus = hapus;
			 hapus = hapus->next;
		}
		prev_hapus->next = NULL;
		free(hapus); //delete hapus
		prev_hapus = NULL;
	}
}

void printList (node *list) {
	node *ptr;
	ptr = list;
	while(ptr != NULL) {
		printf("%d\n",ptr->nim);
		ptr = ptr->next;
	}
}

int main() {
	int masukanUrut;
	node *Element; //tipe datanya pointer, var lokal
	
	printf("Nilai node Element Awal\n");
	Element = createList(1903480);
	printList(Element);
	printf("\n");
	
	printf("Tambah Awal\n");
	addfirst(1900454, &Element);
	addfirst(1900111, &Element);
	addfirst(1900400, &Element);
	addfirst(1908989, &Element);
	addfirst(3909092, &Element);
	addfirst(2108989, &Element);
	printList(Element);
	printf("\n");

	printf("Hapus Awal\n");
	deleteFirst(&Element);
	printList(Element);
	printf("\n");
	
	printf("Hapus tengah\n");
	printf("Masukan urutan yang akan ditambah : ");scanf("%d",&masukanUrut);
	deleteMid(masukanUrut, &Element);
	printList(Element);
	printf("\n");
	
	printf("Hapus Akhir\n");
	deleteLast(&Element);
	printList(Element);
	printf("\n");
	return 0;
}