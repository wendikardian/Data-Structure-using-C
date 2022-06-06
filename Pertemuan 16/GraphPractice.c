#include<stdio.h>
#include<stdlib.h>

typedef struct vertex{
    int data;
    struct vertex *next;
    struct edge *arc;
}Vertex;

typedef struct edge{
    struct edge *next;
    struct vertex *destination;
}Edge;

typedef struct{
    Edge *first;
}Graph;


void createEmpty(Graph *G){
    (*G).first = NULL;
}

