// Wendi Kardian (2100016)
// Binary Tree 
// Case 1 - Silsilah Keluarga 


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

// ADT untuk binary tree
typedef struct vertex{
    char label[20];
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

// Mencetak data secara preorder dengan urutan root-kiri-kanan
void preOrder(Vertex *root){
    if(root != NULL){
        printf("%s ", root->label);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Mencetak data secara inorder dengan urutan kiri-root-kanan
void inOrder(Vertex *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%s ", root->label);
        inOrder(root->right);
    }
}

// Mencetak data secara postorder dengan urutan kiri-kanan-root
void postOrder(Vertex *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%s ", root->label);
    }
}

// Mengecek apakah isi kedua tree itu sama
int isEqual(Vertex *root1, Vertex *root2){
    int result = 1;
    if((root1 != NULL) && (root2 != NULL)) {
        if(strcmp(root1->label, root2->label) != 0){
            result = 0;
        }else{
            isEqual(root1->left, root2->left);
            isEqual(root1->right, root2->right);
        }
    }else{
        if((root1 != NULL) || (root2 != NULL)){
            result = 0;
        }
    }

    return 0;
}

int main(){
    Tree T;
    createTree("Jaemin", &T);
    addLeft("Jisung", T.root);
    addRight("SeulGi", T.root);
    Vertex* firstLeft = T.root->left;
    Vertex* firstRight = T.root->right;
    addLeft("MarkLee", firstLeft);
    addRight("Irene", firstLeft);
    addLeft("RenJun", firstRight);
    addRight("Yeri", firstRight);
    Vertex* Irene = firstLeft->right;
    addLeft("Chenle", Irene);
    Vertex* Renjun = firstRight->left;
    addLeft("Haechan", Renjun);
    addRight("Jeno", Renjun);
    Vertex* Jeno = Renjun->right;
    addLeft("Joy", Jeno);
    printf("\n====Data PreOrder=====\n");
    preOrder(T.root);
    printf("\n\n====Data PostOrder=====\n");
    postOrder(T.root);
    printf("\n\n====Data InOrder=====\n");
    inOrder(T.root);
    printf("\n");

    return 0;
}