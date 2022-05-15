#include<stdio.h>
#include<stdlib.h>

typedef struct vertex{
    char label;
    struct edge *child;
}Vertex; 

typedef struct edge{
    struct vertex *dest;
    struct vertex *sibling;
}Edge;


Vertex * createVertex(char label){
    Vertex *new = (Vertex *)malloc(sizeof(Vertex));
    new->label = label;
    new->child = NULL;
    return new;
}

int main(){


    return 0;
}