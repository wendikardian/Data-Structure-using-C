#include<stdio.h>
#include<stdlib.h>

typedef struct vertex{
    int data;
    struct vertex *next;
    struct edge *arc;
}Vertex;

typedef struct edge{
    int weight;
    struct edge *next;
    struct vertex *destination;
}Edge;

typedef struct{
    Edge *first;
}Graph;


void createEmpty(Graph *G){
    (*G).first = NULL;
}

void addVertex(int c, Graph *G){
    Vertex *new;
    new = (Vertex *)malloc(sizeof(Vertex));
    new->data = c;
    new->next = NULL;
    new->arc = NULL;
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


void addEdge(Vertex *first, Vertex *dest, int weight){
    Edge* new = (Edge *)malloc(sizeof(Edge));
    new->weight = weight;
    new->next = NULL;
    new->destination = dest;
    if(first->arc == NULL){
        first->arc = new;
    }else{
        Edge *ptr = first->arc;
        while(ptr->next != NULL){
            ptr= ptr->next;
        }
        ptr->next = new;
    }

}


Vertex* findVertex(int c,Graph g){
    Vertex *result = NULL;
    Vertex *ptr = g.first;
    int find = 0;
    while(ptr!= NULL && find == 0){
        if(ptr->data == c ){
            result = ptr;
            find = 1;
        }else{
            ptr= ptr->next;
        }
    }
    return result;
}

void printfGraph(Graph G){
    Vertex *ptr = G.first;
    if(ptr != NULL){
        while(ptr != NULL){
            printf("Vertex : %d\n", ptr->data);
            Edge *edge = ptr->arc;
            while(edge!= NULL){
                printf(" - Jalur ke %d dengan beban %d \n", edge->destination->data, edge->weight); 
                edge = edge->next;
            }
            ptr = ptr->next;
        }
    }
    printf("\nGraf Kosong");
}

int main(){
    Graph G;
    createEmpty(&G);
    addVertex(1, &G);
    addVertex(2, &G);
    addVertex(3, &G);
    addVertex(4, &G);
    addVertex(5, &G);
    addVertex(6, &G);
    Vertex *first = findVertex(1, G);
    Vertex *last = findVertex(2, G);
    if(first != NULL && last != NULL){
        addEdge(first, last, 102);
    }
    printfGraph(G);
}