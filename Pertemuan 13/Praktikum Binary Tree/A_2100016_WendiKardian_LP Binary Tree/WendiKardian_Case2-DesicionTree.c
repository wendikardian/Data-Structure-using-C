// Wendi Kardian (2100016)
// Binary Tree 
// Case 2 - Decision Tree 


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

// ADT untuk binary tree
typedef struct vertex{
    char label[100]; //label disini akan berisikan pertanyaan untuk setiap desicion yang dibuat
    struct vertex* right;
    struct vertex* left;
}Vertex;


// ADT untuk tree yang berisikan root atau akar dari tree itu
typedef struct tree{
    Vertex *root;
}Tree;

// Menginisialisasikan tree baru untuk root yang nanti akan berisikan label/data
void createTree(char a[], Tree *T){
    Vertex *new;
    new = (Vertex *)malloc(sizeof(Vertex));
    strcpy(new->label, a);
    new->right = NULL;
    new->left = NULL;
    (*T).root = new;
}

// Menambahkan daun/vertex yang berada disebelah kanan
void addRight(char c[], Vertex *root){
    if(root->right == NULL){ //apabila sebelah kanan masih kosong
        Vertex *new = (Vertex *)malloc(sizeof(Vertex));
        strcpy(new->label, c);
        new->right = NULL;
        new->left = NULL;
        root->right = new;
    }else{ //apabila sebelah kanan sudah di isi
        printf("The right side of the tree already contain\n");
    }
}

// Menambahkan daun/vertex yang berada disebelah kiri
void addLeft(char c[], Vertex *root){
    if(root->left == NULL){ //apabila sebelah kiri masih kosong
        Vertex *new = (Vertex *)malloc(sizeof(Vertex));
        strcpy(new->label, c);
        new->right = NULL;
        new->left = NULL;
        root->left = new;
    }else{ //apabila sebelah kiri sudah terpenuhi
        printf("The left side of the tree already contain\n");
    }
}

// Menghapus semua child yang berada dalam tree tersebut
void delAll(Vertex *root){
    if(root != NULL){
        delAll(root->left);
        delAll(root->right);
        free(root);
    }
}

// Menghapus child yang berada disebelah kanan dari root atau akar
void delRight(Vertex *root){
    if(root != NULL){
        if(root->right != NULL){
            delAll(root->right);
            root->right = NULL;
        }
    }
}

// Menghapus child yang berada disebelah kiri dari root atau akar
void delLeft(Vertex *root){
    if(root != NULL){
        if(root->left != NULL){
            delAll(root->left);
            root->left = NULL;
        }
    }
}



int main(){

    // Proses penambahan pertanyaan kedalam struktur tree
    Tree T;
    createTree("Apakah usia mu diatas 18 tahun ? ", &T);
    addLeft("Apakah anda sudah lulus dari sekolah/kuliah ? ", T.root);
    addRight("Apakah anda sudah menentukan jurusan kuliah ?", T.root);
    Vertex* atas18 = T.root->left;
    Vertex* bawah18 = T.root->right;
    addLeft("Apakah anda sudah merasa kerja sesuai dengan jurusan dan passion yang anda miliki ?", atas18);
    addRight("Apakah sekarang anda merasa nyaman dengan jurusan kuliah anda ?", atas18);
    addLeft("Fine, berarti anda berada di jalan yang tepat dalam hidup anda, semoga anda bahagia :)", atas18->left);
    addRight("Semangat ! jangan putus asa, jangan menyerah untuk menentukan tujuan hidup anda", atas18->left);
    addLeft("Semangat, mari bekerja keras untuk menggapai mimpi mu :)", atas18->right);
    addRight("Mari semangat untuk menentukan tujuan hidup, rencanakan apa yang akan kau lakukan kedepannya", atas18->right);
    addLeft("Apakah anda yakin dengan keputusan anda ? ", bawah18);
    addRight("Apakah anda sudah menemukan minat dan bakat mu ? ", bawah18);
    addLeft("Oke, Goodluck :) ", bawah18->left);
    addRight("jangan lupa pikirkan ulang dan bulatkan tekad yah :)", bawah18->left);
    addLeft("Mari coba cari-cari jurusan dari sekarang yah, jangan sampai nyesel :)", bawah18->right);
    addRight("Semangat, jangan lupa untuk belajar untuk mengenali diri mu sendiri yah :)", bawah18->right);

    // Proses input pertanyaan dari user
    int desicion;
    printf("=====================\n");
    printf("== QUOTES DESICION ==\n");
    printf("=====================\n");

    Vertex *question = T.root;
    
    int j;
   
    // perulangan untuk melakukan pertanyaan dan penyelusuran tree 
    // perulangan akan diulang sampai mencapai daun paling ujung dari tree tersebut
    while(question != NULL && question != NULL){
        printf("\n%s ", question->label);
        if(question->left != NULL && question->right != NULL){
            printf("\n1. Ya\n2. Tidak\n");
            scanf("%d", &desicion);
            if(desicion == 1){
                question = question->left;
            }else{
                question = question->right;
            }
        }else{
            break;
        }
    }

    
 // for(j = 0; j<4; j++){
    //     printf("\n%s ", question->label);
    //     if(j != 3){
    //         printf("\n1. Ya\n2. Tidak\n");
    //         scanf("%d", &desicion);
    //         if(desicion == 1){
    //             question = question->left;
    //         }else{
    //             question = question->right;
    //         }
    //     }
        
    // }


    return 0;
}