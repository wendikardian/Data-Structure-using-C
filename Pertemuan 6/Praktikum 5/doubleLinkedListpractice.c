#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

// Double Linked List Practice
// Wendi kardian
// 2100016
// Pendidikan Ilmu Komputer - A

// struct data mahasiswa
struct node{
    struct node *prev;
    char nama[20];
    int nim;
    int no_urut;
    struct node *next;
};


// deklarasi function secara implisit
int no_urut = 0;
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_at(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);


int main(){
    int option;
    // menampilkan menu
    do{
        printf("\n **** DOUBLE LINKED DATA MAHASISWA LIST MENU **** \n");
        printf("\n\n 1: Tambah data Mahasiswa ");
        printf("\n 2: Display data mahasiswa");
        printf("\n 3: Tambah mahasiswa di depan");
        printf("\n 4: Tambah mahasiswa di akhir");
        printf("\n 5: Add Before");
        printf("\n 6: Add After");
        printf("\n 7: Delete beginning");
        printf("\n 8: Delete end");
        printf("\n 9: Delete at (berdasarkan no urut)");
        printf("\n 10: Delete after");
        printf("\n 11: EXIT");
        printf("\n\nEnter your option : ");
        scanf("%d", &option);
        // switc case berdasarkan user input
        switch (option){
            case 1:
                start = create_ll(start);
                printf("\n Double linked list has been created");
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                start = insert_beg(start);
                break;
            case 4:
                start = insert_end(start);
                break;
            case 5:
                start = insert_before(start);
                break;
            case 6:
                start = insert_after(start);
                break;
            case 7:
                start = delete_beg(start);
                break;
            case 8:
                start = delete_end(start);
                break;
            case 9:
                start = delete_at(start);
                break;
            case 10:
                start = delete_after(start);
                break;

        }
    }while(option != 11);
    return 0;
}

//function untuk menambahkan data
struct node *create_ll(struct node *start){
    struct node *new_node, *ptr;
    int nim;
    char nama[20];
    printf("\nEnter -1 to end");
    printf("\nMasukan NIM : ");
    scanf("%d",&nim);
    printf("Masukan NAMA : ");
    scanf("%s",nama );
    while(nim != -1){
        if(start == NULL){
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->prev = NULL;
            new_node->nim = nim;
            new_node->no_urut = no_urut;
            no_urut++;
            strcpy(new_node->nama, nama);
            new_node->next = NULL;
            start = new_node;
        }else{
            ptr=start;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->nim = nim;
            new_node->no_urut = no_urut;
            no_urut++;
            strcpy(new_node->nama, nama);
            while(ptr->next != NULL){
                ptr=ptr->next;
            }
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }
        printf("\nEnter -1 to end");
	    printf("\nMasukan NIM : ");
	    scanf("%d",&nim);
	    printf("Masukan NAMA : ");
	    scanf("%s",nama );
    }
    return start;
}
// fungsi untuk menampilkan data
struct node *display(struct node *start){
    printf("Display the data\n");
    struct node *ptr;
    ptr = start;
    while(ptr != NULL){
        printf("\n%d). %d - %s",ptr->no_urut, ptr->nim, ptr->nama);
        ptr = ptr->next;
    }
    return start;
}

// menambahkan data mahasiswa di depan
struct node *insert_beg(struct node *start){
    struct node *new_node;
    int nim;
    char nama[20];
    printf("Inserting at the beginning \n");
	printf("\nMasukan NIM : ");
	scanf("%d",&nim);
	printf("Masukan NAMA : ");
	scanf("%s",nama );
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->nim = nim;
    new_node->no_urut = no_urut;
    no_urut++;
    strcpy(new_node->nama, nama);
    new_node->prev= NULL;
    new_node->next = start;
    start->prev = new_node;
    start = new_node;
    return start;
}


//menambahkan data mahasiswa di akhir
struct node * insert_end(struct node *start){
    struct node *new_node, *ptr;
    int nim;
    char nama[20];
    printf("\nMasukan NIM : ");
	scanf("%d",&nim);
	printf("Masukan NAMA : ");
	scanf("%s",nama );
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->nim = nim;
    new_node->no_urut = no_urut;
    no_urut++;
    strcpy(new_node->nama, nama);
    ptr = start;
    while(ptr->next != NULL){
        ptr= ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;
    return start;
}

// add before
struct node *insert_before(struct node * start){
    struct node *new_node, *ptr;
    printf("Insert Before \n");
    int nim, no;
    char nama[20];
    printf("\nMasukan NIM : ");
	scanf("%d",&nim);
	printf("Masukan NAMA : ");
	scanf("%s",nama );
    printf("Masukan no_urut : ");
    scanf("%d", &no);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->nim = nim;
    strcpy(new_node->nama, nama);
    new_node->no_urut = no_urut;
    no_urut++;
    ptr = start;
    while(ptr->no_urut !=no){
        ptr = ptr->next;
    }
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;
    return start;
}


//add after
struct node *insert_after(struct node * start){
    struct node *new_node, *ptr;
    int nim, no;
    char nama[20];
    printf("Insert After\n");
    printf("\nMasukan NIM : ");
	scanf("%d",&nim);
	printf("Masukan NAMA : ");
	scanf("%s",nama );
    printf("Masukan no urut : ");
    scanf("%d", &no);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->nim = nim;
    new_node->no_urut = no_urut;
    no_urut++;
    strcpy(new_node->nama, nama);
    ptr = start;
    while(ptr->no_urut != no){
        ptr= ptr->next;
    }
    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;
    return start;
}


//delete depan
struct node *delete_beg(struct node *start){
    printf("Delete at the beginning \n");
    struct node *ptr;
    ptr = start;
    start = start->next;
    start->prev = NULL;
    free(ptr);
    return start;
}


//delete end
struct node * delete_end(struct node *start){
    printf("Delete at the end \n");
    struct node *ptr;
    ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    return start;

}



//delete after
struct node * delete_after(struct node *start){
    struct node *ptr, *temp;
    int no_urut;
    printf("Delete After \n");
    printf("Masukan NO URUT: ");
    scanf("%d",&no_urut);
    ptr = start;
    while(ptr->no_urut != no_urut){
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
    return start;
}


//delete at
struct node *delete_at(struct node *start){
    struct node *ptr, *temp;
    int no_urut;
    printf("Delete at\n");
    printf("Masukan NO URUT: ");
    scanf("%d", &no_urut);
    ptr = start;
    while(ptr->no_urut != no_urut){
        ptr = ptr->next;
    }
    if(ptr == start){
        start = delete_beg(start);
    }else{
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(temp);
    }
    return start;
}

struct node * delete_list(struct node *start){
    while(start!=NULL){
        start = delete_beg(start);
    }

    return start;
}
