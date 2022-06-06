#include<stdio.h>
#include<stdlib.h>

typedef struct vertex{
    int data;
    struct vertex* child;
    struct vertex* sibling;
}Vertex; 

typedef struct {
    Vertex *root;
}Tree;

void makeTree(int c, Tree *T){
    Vertex *new;
    new = (Vertex *) malloc(sizeof(Vertex));
    new->data = c;
    new->child = NULL;
    new->sibling = NULL;
    (*T).root = new;
}


void addChild(int c, Vertex *root){
    if(root != NULL){
        Vertex *new = (Vertex *) malloc(sizeof(Vertex));
        new->data = c;
        new->child = NULL;
        if(root->child == NULL){
            new->sibling = NULL;
            root->child = new;
        }else{
            if(root->child->sibling == NULL){
                new->sibling = root->child;
                root->child->sibling = new;
            }else{
                Vertex *last = root->child;
                while(last->sibling != root->child){
                    last = last->sibling;
                }
                new->sibling = root->child;
                last->sibling = new;
            }
        }
    }
}


void delAll(Vertex *root){
    if(root!= NULL){
        if(root->child != NULL){
            if(root->child->sibling == NULL){
                delAll(root->child);
                free(root);
            }else{
                Vertex *ptr;
                Vertex *process;
                ptr = root->child;
                while(ptr->sibling != root->child){
                    process = ptr;
                    ptr = ptr->sibling;
                }
                free(root);
            }
        }else{
            free(root);
        }
    }
}

Vertex *findVertex(int c, Vertex *root){
    Vertex *result = NULL;
    if(root!= NULL){
        if(root->data == c){
            result = root;
        }else{
            Vertex *ptr = root->child;
            if(ptr!= NULL){
                if(ptr->sibling == NULL){
                    if(ptr->data == c){
                        result = ptr;
                    }else{
                        result = findVertex(c, ptr);
                    }
                }else{
                    int find = 0;
                    while((ptr->sibling != root->sibling) && (find != 1)){
                        if(ptr->data == c){
                            result = ptr;
                            find = 1;
                        }else{
                            result = findVertex(c, ptr);
                            ptr = ptr->sibling;
                        }
                    }
                    if(find == 0){
                        if(ptr->data == c){
                            result = ptr;

                        }else{
                            result = findVertex(c, ptr);
                        }
                    }
                }
            }
        }
    }
    return result;
}

void preOrder(Vertex *root){
    if(root!= NULL){
        printf(" %d ", root->data);
        Vertex *ptr = root->child;
        if(ptr != NULL){
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
        if(ptr != NULL){
            if(ptr->sibling == NULL){
                postOrder(ptr);
            }else{
                while(ptr->sibling != root->child){
                    postOrder(ptr);
                    ptr = ptr->sibling;
                }
                postOrder(ptr);
            }
        }
        printf(" %d ",root->data);
    }
}

int main()
{
    return 0;
}