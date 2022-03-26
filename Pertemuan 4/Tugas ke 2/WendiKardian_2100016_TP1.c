// Wendi Kardian (2100016) - KEMAKOM VAKSIN
// Pendidikan Ilmu Komputer - A

// Library yang diperlukan
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// stucture untuk linked listnya
struct node{
    char nama[25];
    int status;
    int antrian;
    struct node* next;
};

struct node* start = NULL; //linked list untuk data pasien
int count = 1;  //counter untuk antrian

// Prosedur untuk menampilkan header aplikasi
void header(){
    system("cls");
    printf("+++++===================================================================+++++\n");
    printf("+++++                   APLIKASI VAKSINASI KEMAKOM                      +++++\n");
    printf("+++++===================================================================+++++\n");
}


// Function untuk menampilkan data pasien yang ada dalam linked list
struct node* display(struct node*start){
    struct node *ptr;
    ptr = start;
    header();
    while(ptr != NULL){
        printf("Nama : %s\n", ptr->nama);
        printf("Nomor Antrian: %d\n", ptr->antrian);
        if(ptr->status == 1){
            printf("Prioritas: Normal\n\n");
        }else{
            printf("Prioritas: Lansia\n\n");
        }
        ptr = ptr->next;
    }
    printf("Press any key to continue . . . ");
    getch();
    printf("\n");
    system("cls");
    return start;
}


// Function untuk membuat head linked list apabila depannya masih kosong
struct node *createList(struct node *start){
    char nama[25];
    int status;
    header();
    printf("Masukan Nama: ");
    scanf(" %[^\n]s",&nama);
    printf("Pilih Prioritas:\n");
    printf("[1]Normal\n");
    printf("[2]Lansia\n");
    printf("Masukan Pilihan: ");
    scanf("%d", &status);
    if(status == 1 || status == 2){
        struct node *new_node;
        new_node = (struct node *) malloc(sizeof(struct node));
        strcpy(new_node->nama, nama);
        new_node->antrian = count;
        count++;
        new_node->status = status;
        new_node->next = NULL;
        start = new_node;
        printf("Tambah antrian sukses!\n");
        printf("Press any key to continue . . . ");
        getch();
        system("cls");
    }else{
        printf("Pilihan tidak valid!!\n");
        printf("Press any key to continue . . . ");
        getch();
        system("cls");
    }
    return start; 
    
    
}

// Function untuk menambahkan linked list di belakang linked list
struct node *insert_end(char nama[], int status, struct node *start){
    struct node *new_node, *ptr;
    new_node = (struct node *) malloc(sizeof(struct node));
    strcpy(new_node->nama, nama);
    new_node->antrian = count;
    count++;
    new_node->status = status;
    ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = NULL;
    printf("Tambah antrian sukses!\n");
    printf("Press any key to continue . . . ");
    getch();
    system("cls");
    return start;
}


// Function untuk menambahkkan data setelah element tertentu dalam linked list
struct node *insert_after(char nama[], int status,struct node *start){
    struct node *new_node, *ptr;
    ptr = start;
    if(start->status == 2 && ptr->next == NULL){
       start =  insert_end(nama, status, start);
    }else{
        while(ptr->next != NULL){
           ptr = ptr->next; 
        }
        if(ptr->status == 2){
            start = insert_end(nama, status, start);
        }else{
            ptr =start;
            while(ptr->next->status != 1  && ptr->next != NULL){
                ptr = ptr->next;
            }
            new_node = (struct node *) malloc(sizeof(struct node));
            strcpy(new_node->nama, nama);
            new_node->antrian = count;
            count++;
            new_node->status = status;
            new_node->next = ptr->next;
            ptr->next = new_node;
            printf("Tambah antrian sukses!\n");
            printf("Press any key to continue . . . ");
            getch();
            system("cls");
            
        }
    }
    return start;
    
}


// Function untuk menambahkan data di depan linked-list tersebut
struct node *insert_beg(char nama[], int status,struct node *start){
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->nama,nama);
    new_node->status = status;
    new_node->antrian = count;
    count++;
    new_node->next = start;
    start = new_node;
    printf("Tambah antrian sukses!\n");
    printf("Press any key to continue . . . ");
    getch();
    system("cls");
    return start;
    
}

// Function untuk menambahkan data kedalam linked list tersebut, dan mengecek posisi mana nanti data akan dimasukan
struct node *addData(struct node *start){
    char nama[25];
    int status;
    header();
    printf("Masukan Nama: ");
    scanf(" %[^\n]s",&nama);
    // scanf(" %s",nama);
    printf("Pilih Prioritas:\n");
    printf("[1]Normal\n");
    printf("[2]Lansia\n");
    printf("Masukan Pilihan: ");
    scanf("%d", &status);
    if(status == 1){
        start = insert_end(nama, status, start);
    }else if(status == 2){
        if(start->status == 1){
            start = insert_beg(nama, status, start);
        }else{
            start = insert_after(nama, status, start);
        }
    }else{
        printf("Pilihan tidak valid!!\n");
        printf("Press any key to continue . . . ");
        getch();
        system("cls");
        start= start;
    }
    return start;   
}

// Function untuk menghapus data di depan element tersebut 
// Function ini akan dipanggil apabila ingin memanggil seorang pasien
struct node *delete_beg(struct node *start){
    header();
    printf("%s dengan nomor antrian %d, silahkan menuju ke ruangan vaksinasi\n", start->nama, start->antrian);
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    printf("Press any key to continue . . . ");
    getch();
    system("cls");
    return start;
}

int main(){
    // Proses pemilihan menu yang akan dilakukan oleh user
    int option = 10;
    do{
        header(); // Memanggil header untuk judul aplikasi
        printf("\nSilahkan pilih menu:\n");
        printf("[1]Tambah antrian\n");
        printf("[2]Panggil Antrian Berikutnya\n");
        printf("[3]Lihat Antrian\n");
        printf("[0]Keluar\n\n");
        printf("Masukan Pilihan:");
        scanf("%d",&option);
        switch(option){
            case 1: //Opsion 1 untuk menambahkan antrian
            if(start == NULL){ // apabila ll masih kosong dia akan membuat list baru
                start = createList(start);
            }else{
                start= addData(start); //apabila ll sudah ada, maka akan ditambahkan datanya
            }
                break;
            case 2: // opsion 2 untuk menghapus data di depan dan memanggil pasien
                if(start == NULL){ //dicek apakah ll kosong atau tidak
                    header();
                    printf("Antrian Kosong !\n");
                    printf("Press any key to continue . . . ");
                    getch();
                    system("cls");
                }else{
                    start = delete_beg(start);
                }
                break;
            case 3: // opsion 3 untuk menampilkan data pasien yang ada di ll
                if(start == NULL){ //dicek apakah data itu kosong atau tidak
                    header();
                    printf("Antrian Kosong !\n");
                    printf("Press any key to continue . . . ");
                    getch();
                    system("cls");
                }else{
                    start = display(start);
                }
                break;
            case 0: //0 untuk keluar dari system
                system("cls");
                break;
            default: //jika input tidak sesuai
                header();
                printf("Pilihan tidak valid!!\n");
                printf("Press any key to continue . . . ");
                getch();
                system("cls");
                break;
        }
    }while(option != 0);
    return 0;
}
