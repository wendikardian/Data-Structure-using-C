#include<stdio.h>
#include<stdlib.h>

typedef struct simpul{
    char idSimpul;
    struct simpul * next;
    struct edge * tujuan;
}Simpul;

typedef struct edge{
    int cost;
    struct simpul *tujuan;
    struct edge *next;
}Edge;

typedef struct graph{
    struct simpul *first;
}Graph;


Graph *createGraph(struct graph *g){
    g->first = NULL;
    return g;
}

void createSimpul(Graph *G, char a){
    Simpul *simpulBaru;
    // printf("%c", a);
    printf("HELLo");
    simpulBaru = (Simpul *)malloc(sizeof(Simpul));
    simpulBaru->idSimpul = a;
    simpulBaru->tujuan = NULL;
    simpulBaru->next = NULL;
    if(G->first == NULL){
        G->first = simpulBaru;
    }else{
        Simpul *ptr = G->first;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = simpulBaru;
    }

}

void addEdge(Simpul *awal, Simpul *akhir, int nilaiJalur){
    Edge *new_edge = (Edge *) malloc(sizeof(Edge));
    new_edge->cost = nilaiJalur;
    new_edge->tujuan = akhir;
    Edge *ptr = awal->tujuan;
    if(ptr == NULL){
        ptr = new_edge;
    }else{
        printf("%d", ptr);
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_edge;
    }
}

int main(){ 
    Graph *pertemanan;
    pertemanan->first = NULL;
    createSimpul(pertemanan, 'A');
    addEdge(pertemanan->first, pertemanan->first, 2);
    // printf("\n%c", pertemanan->first->idSimpul);
}