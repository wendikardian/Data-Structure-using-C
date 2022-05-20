#include<stdio.h>
#include<malloc.h>

typedef struct vertex{
    char label;
    struct vertex *next;
    struct edge *arc;
}Vertex;

typedef struct edge{
    int label;
    struct edge *next;
    struct vertex *destination;
}Edge;


typedef struct {
    Vertex *first;
}Graph;


void createGraph(Graph *G){
    (*G).first = NULL;
}

void addVertex(char c, Graph *g){
    Vertex *new;
    new = (Vertex *)malloc(sizeof(Vertex));
    new->label = c;
    new->next = NULL;
    new->arc = NULL;

    if((*g).first == NULL){
        (*g).first = new;
    }else{
        Vertex *last = (*g).first;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = new;

    }
}

void addEdge(Vertex *first, Vertex *dest, int weight){
    Edge *new;
    new = (Edge *)malloc(sizeof(Edge));
    new->label = weight;
    new->next = NULL;
    new->destination = dest;

    if(first->arc == NULL){
        first->arc = new;
    }else{
        Edge *last = first->arc;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = new;
    }
}


Edge *findSimpul(char c, Graph G){
    Edge *result = NULL;
    Edge *ptr = G.first;

    int find = 0;
    while((ptr != NULL) && (find == 0)){
        if(ptr->label == c){
            result = ptr;
            find = 1;
        }else{
            ptr = ptr->next;
        }
    }
    return result;
}


void delEdge(char cdest, Vertex *first){
    Edge *del = first->arc;
    if(del != NULL){
        Edge *prev = NULL;
        int find = 0;
        while((del != NULL) && (find == 0)){
            if(del->destination->label == cdest){
                find = 1;
            }else{
                prev = del;
                del = del->next;
            }
        }
        if(find == 1){
            if(prev == NULL){
                first->arc = del->next;
            }else{
                if(del->next == NULL){
                    prev->next = NULL;
                }else{
                    prev->next = del->next;
                    del->next = NULL;
                }
            }
            free(del);
        }else{
            printf("Vertex not found \n");
        }
    }else{
        printf("Vertex not found \n");
    }
}

void delAll(Vertex *first){
    Edge *ptr;
    ptr = first->arc;
    Edge *del;
    while(ptr != NULL){
        del = ptr;
        ptr= ptr->next;
        first->arc = ptr;
        del->next = NULL;
        free(del);
    }
}

void printGraph(Graph G){
    Vertex *ptr = G.first;
    if(ptr != NULL){
        while(ptr != NULL){
            printf("Simpul : %c\n", ptr->label);
            Vertex *ptr_vertex = ptr->arc;
            while(ptr_vertex != NULL){
                printf("    - to vertex : %c with weight %d \n", ptr_vertex->label, ptr_vertex->label);
                ptr_vertex = ptr_vertex->next;
            }
            ptr= ptr->next;
        }
    }else{
        printf("Graph Empty\n");
    }
}


int main(){

    Graph G;
    createGraph(&G);
    return 0;
}