// Galih Lazuardi Nursyahbana 2103670
// Pendidikan Ilmu Komputer
// Program Kaget Ga? 

// memanggil library
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// struct linked list
typedef struct element{
    char nama[20];
    int status, antrian;
    struct element* next;
}element;

// variabel global
element *pasien = NULL; // linked list untuk data pasien
int noAntrian = 1; // penghitung untuk antrian

// prosedur judul
void judul(){
    system("cls");
    printf("+++++===================================================================+++++\n");
    printf("+++++                   APLIKASI VAKSINASI KEMAKOM                      +++++\n");
    printf("+++++===================================================================+++++\n");
}

// fungsi untuk membuat element
element *createElement(element *pasien){
    element *baru = (element*) malloc(sizeof(element));
    char nama[20];
    int status;
    judul();
    printf("Masukan Nama: ");
    scanf("%s", nama);
    printf("Pilih Prioritas:\n");
    printf("[1]Normal\n");
    printf("[2]Lansia\n");
    printf("Masukan Pilihan: ");
    scanf("%d", &status);
    strcpy(baru->nama, nama);
    baru->antrian = noAntrian;
    noAntrian++;
    baru->status = status;
    baru->next = NULL;
    pasien = baru;
    
    printf("Tambah antrian sukses!\n");
    printf("Press any key to continue . . . ");
    getch();
    printf("\n");
    system("cls");
    
    return pasien;
}

// prosedur untuk menambah element di awal
void addAwal(char nama[], int status, element **pasien){
    element *baru = (element*)malloc(sizeof(element));
    strcpy(baru->nama,nama);
    baru->status = status;
    baru->antrian = noAntrian;
    noAntrian++;
    baru->next = *pasien;
    *pasien = baru;
    baru = NULL;
    
    printf("Tambah antrian sukses!\n");
    printf("Press any key to continue . . . ");
    getch();
    printf("\n");
    system("cls");
}

// prosedur untuk menambah element di akhir
void addAkhir(char nama[], int status, element *pasien){
    element *baru = (element*) malloc(sizeof(element)), *ptr;
    strcpy(baru->nama, nama);
    baru->antrian = noAntrian;
    noAntrian++;
    baru->status = status;
    ptr = pasien;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = baru;
    baru->next == NULL;
    
    printf("Tambah antrian sukses!\n");
    printf("Press any key to continue . . . ");
    getch();
    printf("\n");
    system("cls");
}

// prosedur untuk menambah element setelah element lain
void addAfter(char nama[], int status, element *pasien){
    element *baru, *ptr = pasien;
    
    // proses penentuan bagaimana data akan ditambahkan
    if(pasien->status == 2 && ptr->next == NULL){
        addAkhir(nama, status, pasien);
    }else{
        while(ptr->next != NULL){
           ptr = ptr->next; 
        }
        if(ptr->status == 2){
            addAkhir(nama, status, pasien);
        }
		else{
            ptr = pasien;
            while(ptr->next->status != 1  && ptr->next != NULL){
                ptr = ptr->next;
            }
            baru = (element*) malloc(sizeof(element));
            strcpy(baru->nama, nama);
            baru->antrian = noAntrian;
            noAntrian++;
            baru->status = status;
            baru->next = ptr->next;
            ptr->next = baru;
            
            printf("Tambah antrian sukses!\n");
            printf("Press any key to continue . . . ");
            getch();
            printf("\n");
            system("cls");
        }
    }
}

// prosedur untuk mengecek data inputan
void addData(element **pasien){
	element *temp = *pasien;
    char nama[20];
    int status;
    
    judul();
    printf("Masukan Nama: ");
    scanf("%s", nama);
    printf("Pilih Prioritas:\n");
    printf("[1]Normal\n");
    printf("[2]Lansia\n");
    printf("Masukan Pilihan: ");
    scanf("%d", &status);
    // proses penentuan bagaimana data akan ditambahkan
    if(status == 1){
        addAkhir(nama, status, *pasien);
    }else{
        if(temp->status == 1){
            addAwal(nama, status, &*pasien);
        }
		else{
            addAfter(nama, status, *pasien);
        }
    }
}

// prosedur untuk menghapus elemen di awal
void hapusAwal(element **pasien){
    judul();
    element *temp = *pasien;
    if(temp == NULL){ // proses untuk mengecek apakah antrian kosong
        printf("Antrian Kosong !\n");
	}else{
		printf("%s dengan nomor antrian %d, silahkan menuju ke ruangan vaksinasi\n", temp->nama, temp->antrian);
		*pasien = temp->next;
		free(temp);	
	}
	printf("Press any key to continue . . . ");
	getch();
    printf("\n");
    system("cls");
}

// prosedur untuk menampilkan linked list
void cetakList(element *pasien){
    element *ptr = pasien;
	judul();
	if(ptr == NULL){ // proses untuk mengecek apakah antrian kosong
		printf("Antrian Kosong !\n");
	}
	else{
	
		while(ptr != NULL){
	    	printf("Nama : %s\n", ptr->nama);
	    	printf("Nomor Antrian: %d\n", ptr->antrian);
    	if(ptr->status == 1){
        	printf("Prioritas: Normal\n\n");
   		}
		else{
        	printf("Prioritas: Lansia\n\n");
    	}
    	ptr = ptr->next;
 		}
	}
	printf("Press any key to continue . . . ");
	getch();
	printf("\n");
	system("cls");
	
}

// fungsi utama
int main(){
	// proses pemilihan menu oleh user
    int opsi, mulai=1;
    while(mulai==1){
    	judul(); 
        printf("\nSilahkan pilih menu:\n");
        printf("[1]Tambah antrian\n");
        printf("[2]Panggil Antrian Berikutnya\n");
        printf("[3]Lihat Antrian\n\n");
        printf("Masukan Pilihan:");
        scanf("%d",&opsi);
        
        if(opsi==0){ // jika user menginput 0
		// proses untuk mengakhiri program
			mulai=0;
		}
        else if(opsi==1){ // jika user menginput 1
        	if(pasien == NULL){ // apabila ll masih kosong maka akan membuat list baru
                pasien = createElement(pasien);
            }
			else{ //apabila ll sudah ada maka akan menambahkan data
                addData(&pasien); 
            }
		}
		else if(opsi==2){ // jika user menginput 2
		// memanggil prosedur hapus awal
	    	hapusAwal(&pasien);
		}
		else if(opsi==3){ // jika user menginput 3
		// memanggil prosedur cetak list
		    cetakList(pasien);
		}
	}
    
    return 0;
}
