#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Single linked list
typedef struct {
	int nim;
	struct node *next;
}node;

node *Element;		//variabel Global

//membuat linked list
node *createList(int NIM) {
	node *baru;
	baru = (node*)malloc(sizeof(node)); //alokasikan memori sebesar node struct
	baru->nim = NIM; //isi atribut nim
	baru->next = NULL; //isi alamat yang menunjukkan node berikutnya
	
	return baru;
}

void addfirst (int NIM) {
	node *tambah;
	tambah = createList(NIM);
	tambah->next = Element; //isi variabel pointer tambah dengan alamat element yang merupakan lingked list utama
	Element = tambah; //ubah nilai element menjadi tambah, sehingga pointer awal tetap pada element
	tambah = NULL; //kosongkan kembali nilai tambah
}

void addLast (int NIM) {
	node *tambah;
	node *help;
	help = Element; //isi variabel temp help dengan nilai element
	tambah = createList(NIM); // buat list baru
	while (help->next != NULL) { //periksa dan telusuri nilai variabel pointer suatu list itu kosong
		help = help->next;
	}
	help->next= tambah; //isi pointer next dengan list tambah
}

void addmid (int NIM, int urut) {
	node *help;
	int i;
	help = Element; //isi variabel temp help dengan nilai element
	node *tambah = createList(NIM); // buat list baru
	for(i=1;i<urut;i++) { //cari urutan nilai list yang akan di tambahkan
		help = help->next;
	}
	tambah->next = help->next; //isi var pointer list baru dengan var pointer list temp help
	help->next = tambah; //isi var pointer list help dengan node tambah
	tambah = NULL; //kosongkan kembali nilai tambah
	help = NULL; //kosongkan kembali nilai tambah
}

void printList () {
	node * ptr;
	ptr = Element;
	while(ptr != NULL) {
		printf("%d\n",ptr->nim);
		ptr = ptr->next;
	}
}

int main() {
	int masukanUrut;
	
	printf("Nilai node Element Awal\n");
	Element = createList(1903480);
	printList(Element);
	printf("\n");
	
	printf("Tambah Awal\n");
	addfirst(1900454);
	addfirst(1900111);
	printList(Element);
	printf("\n");
	
	printf("Tambah Akhir\n");
	addLast(123123);
	printList(Element);
	printf("\n");
	
	printf("Tambah Tengah\n");
	printf("Masukan urutan yang akan ditambah : ");
	scanf("%d",&masukanUrut);
	addmid(909090,masukanUrut);
	printList(Element);
	printf("\n");
	
	return 0;
}