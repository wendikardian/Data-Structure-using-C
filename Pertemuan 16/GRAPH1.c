#include<stdio.h>
#include<stdlib.h>

typedef struct vertex{
    int data;
    struct vertex *next;
    struct edge *arc;
}Vertex;

typedef struct edge{
    int weight;
    struct vertex *destination;
    struct edge *next;
}Edge;

typedef struct{
    Vertex *first;
}Graph;


void createEmpty(Graph *G){
    (*G).first = NULL;
}
void addVertex(Graph *G, int data){
    Vertex *new = (Vertex *) malloc(sizeof(Vertex));
    new->data = data;
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

void addEdge(Vertex *first, Vertex *last, int weight){
    Edge *new = (Edge *) malloc(sizeof(Edge));
    new->weight = weight;
    new->destination = last;
    new->next = NULL;
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

Vertex* findVertex(int data, Graph G){
    Vertex *result = NULL;
    Vertex *ptr = G.first;
    int found = 0;
    while(ptr->next != NULL && found !=1 ){
        if(ptr->data == data){
            found = 1;
            result = ptr;
        }else{
            ptr = ptr->next;
        }
    }
    return result;
}

void printGraph(Graph G){
    Vertex *ptr = G.first;
    if(ptr!= NULL){
        while(ptr!= NULL){
            printf("Vertex  :  %d\n", ptr->data);
            Edge *relation = ptr->arc;
            if(relation!= NULL){
                while(relation!= NULL){
                    printf("Connect to : %d with weight %d \n\n------\n", relation->destination->data, relation->weight); 
                    relation = relation->next;
                }
            }else{
                printf(" -_- No Connection\n\n------\n");
            }
            ptr = ptr->next;
        }
    }else{
        printf("Empty Graph\n");
    }
}



int main(){
    Graph G;
    createEmpty(&G);
    addVertex(&G, 12);
    addVertex(&G, 14);
    addVertex(&G, 16);
    addVertex(&G, 18);
    Vertex *duabelas = findVertex(12, G);
    Vertex *empatbelas = findVertex(14, G);
    Vertex *enambelas = findVertex(16, G);
    Vertex *delapanbelas = findVertex(18, G);
    addEdge(duabelas, empatbelas, 1020);
    addEdge(empatbelas, enambelas, 1060);
    printGraph(G);
    return 0;
}