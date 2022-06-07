#include<stdio.h>
#include<stdlib.h>

typedef struct vertex{
    int data;
    struct vertex *right;
    struct vertex *left;
}Vertex;

typedef struct tree{
    Vertex *root;
}Tree;
   
void makeTree(int c, Tree *T){
    Vertex *new;
    new = (Vertex*)malloc(sizeof(Vertex));
    new->data = c;
    new->right = NULL;
    new->left = NULL;
    (*T).root = new;
}


void addRight(int c, Vertex *root){
    if(root->right == NULL){
        Vertex *new;
        new = (Vertex*)malloc(sizeof(Vertex));
        new->data = c;
        new->right = NULL;
        new->left = NULL;
        root->right = new;
    }else{
        printf("The right side of the root is not empty\n");
    }
}

void addLeft(int c, Vertex *root){
    if(root->left == NULL){
        Vertex *new = (Vertex *)malloc(sizeof(Vertex));
        new->data = c;
        new->left = NULL;
        new->right = NULL;
        root->left = new;
    }else{
        printf("The left side of the root is not empty\n");
    }
}

void delAll(Vertex *root){
    if(root != NULL){
        delAll(root->left);
        delAll(root->right);
        free(root);
    }
}

void delRight(Vertex *root){
    if(root!= NULL){
        if(root->right != NULL){
            delAll(root->right);
            root->right = NULL;
        }
    }
}
void delLeft(Vertex *root){
    if(root!= NULL){
        if(root->left != NULL){
            delAll(root->left);
            root->left = NULL;
        }
    }
}

void preOrder(Vertex *root){
    if(root!= NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Vertex *root){
    if(root!= NULL){
        preOrder(root->left);
        printf("%d ", root->data);
        preOrder(root->right);
    }
}
void postOrder(Vertex *root){
    if(root!= NULL){
        preOrder(root->left);
        preOrder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    Tree T;
    makeTree(1, &T);
    addLeft(2, T.root);
    addRight(3, T.root);
    postOrder(T.root);
    return 0;
}