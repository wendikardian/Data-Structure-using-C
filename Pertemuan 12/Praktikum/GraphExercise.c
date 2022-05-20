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


Vertex *findVertex(char c, Graph G){
    Vertex *result = NULL;
    Vertex *ptr = G.first;

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

void delVertex(char c, Graph *G){
    Vertex *del = (*G).first;
    if(del != NULL){
        Vertex *prev = NULL;
        int find = 0;
        while((del != NULL) && (find == 0)){
            if(del->label == c){
                find == 1;
            }else{
                prev = del;
                del = del->next;
            }
        }
        if(find == 1){
            Vertex *ptr;
            ptr = (*G).first;

            while(ptr != NULL){
                if(ptr != del){
                    delEdge(del->label, ptr);
                }
                ptr = ptr->next;
            }
            delAll(del);

            if(prev == NULL){
                (*G).first = del->next;
                del->next = NULL;
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

void printGraph(Graph G){
    Vertex *ptr = G.first;
    if(ptr != NULL){
        while(ptr != NULL){
            printf("Simpul : %c\n", ptr->label);
            Edge *ptr_vertex = ptr->arc;
            while(ptr_vertex != NULL){
                printf("    - to vertex : %c with weight %d \n", ptr_vertex->destination->label, ptr_vertex->label);
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
    addVertex('A', &G);
    addVertex('B', &G);
    addVertex('C', &G);
    addVertex('D', &G);
    addVertex('E', &G);
    addVertex('F', &G);

    Vertex *begin = findVertex('A', G);
    Vertex *end = findVertex('B', G);
    if((begin != NULL) && (end != NULL)){
        addEdge(begin, end, 3);
    }

    begin = findVertex('B', G);
    end = findVertex('D', G);
    if((begin != NULL) && (end != NULL)){
        addEdge(begin, end, 3);
    }

    end = findVertex('E', G);
    if((begin != NULL) && (end != NULL)){
        addEdge(begin, end, 7);
    }

    begin = findVertex('C', G);
    end = findVertex('A', G);
    if((begin != NULL) && (end != NULL)){
        addEdge(begin, end, 3);
    }
    
    begin = findVertex('D', G);
    if((begin != NULL) && (end != NULL)){
        addEdge(begin, end, 8);
    }

    end = findVertex('C', G);
    if((begin != NULL) && (end != NULL)){
        addEdge(begin, end, 3);
    }

    begin = findVertex('E', G);
    end = findVertex('D', G);
    if((begin != NULL) && (end != NULL)){
        addEdge(begin, end, 4);
    }

    
    end = findVertex('F', G);
    if((begin != NULL) && (end != NULL)){
        addEdge(begin, end, 4);
    }

    begin = findVertex('F', G);
    end = findVertex('D', G);
    if((begin != NULL) && (end != NULL)){
        addEdge(begin, end, 2);
    }

    printf("==== DATA GRAPH ======\n\n");
    printGraph(G);

    // begin = findVertex('D', G);
    // if(begin != NULL){
    //     delEdge('C', begin);
    // }

    begin = findVertex('D', G);
    
    // G.first = NULL;
    delAll(begin);

    printf("\n\n==== AFTER DELETED ======\n\n");
    printGraph(G);
    return 0;
}