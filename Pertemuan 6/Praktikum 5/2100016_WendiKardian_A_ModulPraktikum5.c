#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Nama : Wendi Kardian
// NIM : 2100016
// Kelas : Pendidikan Ilmu Komputer - A
// Double linked list (Praktikum 5)


// inisialisasi double linked list menggunakan struct
struct node{
    int id;
    char nama[20];
    char gender[20];
    int usia;
    struct node *next;
    struct node *prev;
};

// deklarasi variabel untuk linked list dengan initial value NULL
struct node* start = NULL;

//function untuk membuat linkedlist yang baru
struct node* createElement(){
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    int id, usia;
    char nama[20], gender[20];
    scanf("%d",&id);
    scanf("%s", nama);
    scanf("%s", gender);
    scanf("%d",&usia);
    new_node->id = id;
    new_node->usia = usia;
    strcpy(new_node->nama,nama);
    strcpy(new_node->gender,gender);
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}


// menambahkan nodes baru di awal linked list
struct node* addawal(struct node *start){
    struct node *new_node;
    if(start == NULL){
        new_node = createElement();
        start = new_node;
    }else{
        new_node = createElement();
        new_node->prev = NULL;
        new_node->next = start;
        start->prev = new_node;
        start = new_node;
    }
    return start;
}

2
// function untuk menampilkan seluruh data di seluruh linked list
struct node* display(struct node *start){
    struct node *ptr;
    ptr = start;
    while(ptr != NULL){
        printf("%d\n%s\n%s\n%d\n\n",ptr->id, ptr->nama, ptr->gender, ptr->usia);
        ptr = ptr->next;
    }
    return start;
}

//function untuk menambahkan data nodes setelah id tertentu
struct node *addAfter(struct node *start){
    struct node *new_node, *ptr;
    int askedId;
    scanf("%d", &askedId);
    ptr = start;
    while(ptr->id != askedId){
        ptr= ptr->next;
    }
    new_node = createElement();
    if(ptr->next == NULL){
        ptr->next = new_node;
        new_node->prev = ptr;
        new_node->next = NULL;
    }else{
        new_node->prev = ptr;
        new_node->next = ptr->next;
        ptr->next->prev = new_node;
        ptr->next = new_node;
    }
    
    return start;
}

// menambahkan nodes baru sebelum id tertentu
struct node *addBefore(struct node *start){
    struct node *new_node, *ptr;
    int askedId;
    scanf("%d", &askedId);
    ptr = start;
    while(ptr->id !=askedId){
        ptr = ptr->next;
    }
    new_node = createElement();
    if(ptr == start){
        new_node->prev = NULL;
        new_node->next = start;
        start->prev = new_node;
        start = new_node;
    }else{
        new_node->next = ptr;
        new_node->prev = ptr->prev;
        ptr->prev->next = new_node;
        ptr->prev = new_node;
    }
    return start;
}

// menambahkan nodes baru di akhir linked list tersebut
struct node *addAkhir(struct node *start){
    struct node *new_node, *ptr;
    ptr = start;
    while(ptr->next != NULL){
        ptr= ptr->next;
    }
    new_node = createElement();
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;
    return start;
}

// menghapus data di linked list tersebut berdasarkan id yang dimasukan oleh user
struct node *delete(struct node *start){
    struct node *ptr;
    ptr = start;
    int askedId;
    scanf("%d", &askedId);
    while(ptr->id != askedId){
        ptr = ptr->next;
    }
    if(ptr == start){
        start = start->next;
        start->prev = NULL;
        free(ptr);
    }else if(ptr->next == NULL){
        ptr->prev->next = NULL;
        free(ptr);
    }
    else{
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }
    return start;
}

// menampilkan data berdasarkan id dari nodes yang di inputkan
struct node *displayDataId(struct node *start){
    struct node *ptr;
    ptr = start;
    int askedId;
    scanf("%d", &askedId);
    while(ptr->id != askedId){
        ptr = ptr->next;
    }
    printf("\n%d\n%s\n%s\n%d\n",ptr->id, ptr->nama, ptr->gender, ptr->usia);
    return start;

}

// function utama
int main(){
    int option; //variabel untuk opsi user
    do{
        scanf("%d",&option); //
        switch(option){
            //addawal
            case 1: //menambah data di awal
                start = addawal(start);
                break;
            case 2: //menampilkan data berdasarkan id tertentu
                start = displayDataId(start);
                break;
            case 3: //menambahkan data setelah id tertentu
                start = addAfter(start);
                break;
            case 4: //menambahkan data sebelum id tertentu
                start = addBefore(start);
                break;
            case 5: //menambahkan data di akhir linked list
                start = addAkhir(start);
                break;
            case 6: //menghapus data berdasarkan id tertentu
                start = delete(start);
                break;
            case 7: //menampilkan seluruh data yang ada di dalam linked list
                if(start == NULL){
                    printf("Tidak ada\n");
                }else{
                    start = display(start);
                }
                break;
            case 0: // menampilkan data (di cek terlebih dahulu)
                if(start == NULL){
                    printf("Tidak ada");
                }else{
                    start = display(start);
                }
                break;
        }
    }while(option != 0); //apabila input  == 0 maka akan outdari looping dan program selesai

    return 1;
}
