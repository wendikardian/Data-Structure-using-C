#include<stdio.h>
#include<stdlib.h>

typedef struct vertex{
    int data;
    struct vertex *child;
    struct vertex *sibling;
}Vertex; 

typedef struct {
    struct vertex *root;
}Tree;

void createTree(int data, Tree *T){
    Vertex *new = (Vertex *) malloc(sizeof(Vertex));
    new->data = data;
    new->child = NULL;
    new->sibling = NULL;
    (*T).root = new;
}

void addChild(int data, Vertex *root){
    if(root!= NULL){
        Vertex *new = (Vertex *) malloc(sizeof(Vertex));
        new->data = data;
        new->child = NULL;
        if(root->child == NULL){
            new->sibling = NULL;
            root->child = new;
        }else{
            if(root->child->sibling == NULL){
                new->sibling = root->child;
                root->child->sibling = new;
            }else{
                Vertex *ptr = root->child;
                while(ptr->sibling != root->child){
                    ptr = ptr->sibling;
                }
                ptr->sibling = new;
                new->sibling = root->child;
            }
        }
    }
}

Vertex *findVertex(int data, Vertex *root){
    Vertex *result = NULL;
    if(root!= NULL){
        if(root->data == data){
            result = root;
        }else{
            Vertex *ptr = root->child;
            if(ptr!= NULL){
                if(ptr->sibling == NULL){
                    if(ptr->data == data){
                        result = ptr;
                    }else{
                        result = findVertex(data, ptr);
                    }
                }else{
                    int find = 0;
                    while(ptr->sibling != root->child && find == 0){
                        if(ptr->data == data){
                            result = ptr;
                            find = 1;
                        }else{
                            result = findVertex(data, ptr);
                            ptr = ptr->sibling;
                        }
                    }
                    if(find = 1){
                        if(ptr->data == data){
                            result = ptr;
                        }else{
                            result = findVertex(data, ptr);
                        }
                    }
                }
            }
        }
    }
    return result;
}

// void preOrder(Vertex *root){
//     if(root!= NULL){
//         printf(" %d ", root->data);
//         Vertex *ptr = root->child;
//         if(ptr!= NULL){
//             if(ptr->sibling == NULL){
//                 preOrder(ptr);
//             }else{
//                 while(ptr->sibling != root->child){
//                     preOrder(ptr);
//                     ptr = ptr->sibling;
//                 }
//                 preOrder(ptr);
//             }
//         }
//     }
// }

void preOrder(Vertex *root){
    if(root!= NULL){
        printf("%d ", root->data);
        if(root->child != NULL){
            Vertex *ptr = root->child;
            if(ptr->sibling == NULL){
                preOrder(ptr);
            }else{
                while(ptr->sibling != root->child){
                    preOrder(ptr);
                    ptr = ptr->sibling;
                }
                preOrder(ptr);
            }
        }
    }
}


void postOrder(Vertex *root){
    if(root!= NULL){
        Vertex *ptr = root->child;
        if(ptr!= NULL){
            if(ptr->sibling == NULL){
                preOrder(ptr);
            }else{
                while(ptr->sibling != root->child){
                    preOrder(ptr);
                    ptr = ptr->sibling;
                }
                preOrder(ptr);
            }
        }
        printf(" %d ", root->data);
    }
}

int main(){
    Tree T;
    createTree(12, &T);
    addChild(20,T.root);
    addChild(30,T.root);
    addChild(40,T.root);
    preOrder(T.root);
    printf("\n");
    postOrder(T.root);
    return 0;
}