// Wendi Kardian (2100016)
// Binary Tree


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct vertex{
    char label;
    struct vertex* right;
    struct vertex* left;
}Vertex;

typedef struct tree{
    Vertex *root;
}Tree;

void createTree(char a, Tree *T){
    Vertex *new;
    new = (Vertex *)malloc(sizeof(Vertex));
    new->label = a;
    new->right = NULL;
    new->left = NULL;
    (*T).root = new;
}

void addRight(char c, Vertex *root){
    if(root->right == NULL){
        Vertex *new = (Vertex *)malloc(sizeof(Vertex));
        new->label = c;
        new->right = NULL;
        new->left = NULL;
        root->right = new;
    }else{
        printf("The right side of the tree already contain\n");
    }
}

void addLeft(char c, Vertex *root){
    if(root->left == NULL){
        Vertex *new = (Vertex *)malloc(sizeof(Vertex));
        new->label = c;
        new->right = NULL;
        new->left = NULL;
        root->left = new;
    }else{
        printf("The left side of the tree already contain\n");
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
    if(root != NULL){
        if(root->right != NULL){
            delAll(root->right);
            root->right = NULL;
        }
    }
}

void delLeft(Vertex *root){
    if(root != NULL){
        if(root->left != NULL){
            delAll(root->left);
            root->left = NULL;
        }
    }
}


void preOrder(Vertex *root){
    if(root != NULL){
        printf("%c ", root->label);
        preOrder(root->left);
        preOrder(root->right);
    }
}


void inOrder(Vertex *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%c ", root->label);
        inOrder(root->right);
    }
}

void postOrder(Vertex *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ", root->label);
    }
}

// void copyTree(Vertex *root1, Vertex **root2){
//     if(root1 != NULL){
//         (*root2) = (Vertex *)malloc(sizeof(Vertex));
//         (*root2)->label = root1->label;
//         if(root1->left != NULL){
//             copyTree(root1->left, (*root2)->left);
//         }
//         if(root1->right != NULL){
//             copyTree(root1->right, (*root2)->right);
//         }
//     }
// }

int isEqual(Vertex *root1, Vertex *root2){
    int result = 1;
    if((root1 != NULL) && (root2 != NULL)) {
        if(root1->label != root2->label){
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
    createTree('A', &T);
    addLeft('B', T.root);
    addRight('C', T.root);
    addLeft('D', T.root->left);
    addRight('E', T.root->left);
    addRight('F', T.root->right);
    preOrder(T.root);
    printf("\n");
    postOrder(T.root);
    printf("\n");
    inOrder(T.root);
    printf("\n");
}