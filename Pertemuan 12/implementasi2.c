#include<stdio.h>
#include<stdlib.h>

typedef struct vertex{
    char label;
    struct vertex *sibling;
    struct vertex *child;
}Vertex;

typedef struct tree{
    struct vertex *root;
}Tree;

Vertex *root = NULL;

Vertex * createVertex(char label){
    Vertex *new = (Vertex*)malloc(sizeof(Vertex));
    new->label =  label;
    new->sibling = NULL;
    new->child = NULL;
    return new;
}


Vertex* addChild(char c, Vertex *root){
    Vertex *ptr = root;
    while(ptr->label != parent){
        while(ptr->sibling != NULL){
            ptr = ptr->sibling;
        }
    }
}

int main(){
    root = createVertex('A');
    printf("%c", root->label);
    return 0;
}