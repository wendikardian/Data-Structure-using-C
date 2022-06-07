#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct vertex{
    char nama[20];
    struct vertex *next;
    struct vertex *arc;
}Vertex;

typedef struct edge{
    int jarak;
    struct vertex *destination;
    struct edge *next;
}Edge;

typedef struct graph{
    Vertex *first;
}Graph;

void createEmpty(Graph *G){
    (*G).first = NULL;
}

void addVertex(Graph *G, char nama[]){
    Vertex *new = (Vertex *)malloc(sizeof(Vertex));
    strcpy(new->nama, nama);
    new->next = NULL;
    new->arc= NULL;
    if((*G).first == NULL){
        (*G).first = new;
    }else{
        Vertex *ptr = (*G).first;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new;
    }
}

void addEdge(Vertex *first, Vertex *last, int jarak){
    Edge *new = (Edge*)malloc(sizeof(Edge));
    new->jarak = jarak;
    new->next = NULL;
    new->destination = last;
    if(first->arc == NULL){
        first->arc = new;
    }else{
        Edge *ptr = first->arc;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new;
    }
}


void printGraph(Graph *G){
    Vertex *ptr = (*G).first;
    if(ptr!= NULL){
        while(ptr->next != NULL){
            Edge *ptrEdge = ptr->arc;
            if(ptrEdge != NULL){
                while(ptrEdge->next != NULL){
                    printf("rumah %s %d meter ke rumah %s\n", ptr->nama, ptrEdge->jarak, ptrEdge->destination->nama);
                    ptrEdge = ptrEdge->next;
                }
            }
            ptr = ptr->next;
        }
    }
}


int main(){
    Graph G;
    createEmpty(&G);
}