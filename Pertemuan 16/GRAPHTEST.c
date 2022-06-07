#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct vertex{
    char nama[20];
    struct vertex *next;
    struct edge *arc;
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
        while(ptr != NULL){
            // printf("%s \n", ptr->nama);
            Edge *ptrEdge = ptr->arc;
            if(ptrEdge != NULL){
                while(ptrEdge != NULL){
                    printf("rumah %s %d meter ke rumah %s\n", ptr->nama, ptrEdge->jarak, ptrEdge->destination->nama);
                    ptrEdge = ptrEdge->next;
                }
            }
            ptr = ptr->next;
        }
    }
}

Vertex *findVertex(Graph *G, char nama[]){
    Vertex *ptr = (*G).first;
    if(ptr != NULL){
        while(ptr != NULL){
            if(strcmp(ptr->nama, nama) == 0){
                return ptr;
            }else{
                ptr =ptr->next;
            }
        }
    }
    return NULL;
}

// void findShort(Vertex *first, Vertex *last){
//     Edge *ptr = first->arc;
//     int total = 0;
//     if(ptr != NULL){
//         while(ptr != NULL){
//             while(ptr!=NULL){
//                 if(ptr->destination == first){
//                     printf("%")
//                 }
//             }
            
//         }
//     }
// }

int main(){
    Graph G;
    createEmpty(&G);
    addVertex(&G, "kiki");
    addVertex(&G, "anton");
    addVertex(&G, "teti");
    addVertex(&G, "malik");
    addVertex(&G, "amel");
    addVertex(&G, "budi");
    addVertex(&G, "rudi");
    Vertex *rumahKiki = findVertex(&G, "kiki");
    Vertex *rumahAnton = findVertex(&G, "anton");
    Vertex *rumahTeti = findVertex(&G, "teti");
    Vertex *rumahMalik = findVertex(&G, "malik");
    Vertex *rumahAmel = findVertex(&G, "amel");
    Vertex *rumahRudi = findVertex(&G, "rudi");
    Vertex *rumahBudi = findVertex(&G, "budi");
    addEdge(rumahKiki, rumahAnton, 2);
    addEdge(rumahKiki, rumahTeti, 8);
    addEdge(rumahAnton, rumahKiki, 2);
    addEdge(rumahAnton, rumahMalik, 3);
    addEdge(rumahAnton, rumahAmel, 6);
    addEdge(rumahTeti, rumahKiki,8);
    addEdge(rumahTeti, rumahMalik,4);
    addEdge(rumahTeti, rumahRudi,10);
    addEdge(rumahMalik,rumahAnton,3);
    addEdge(rumahMalik,rumahTeti,4);
    addEdge(rumahMalik,rumahAmel,3);
    addEdge(rumahAmel,rumahAnton,6);
    addEdge(rumahAmel,rumahMalik,3);
    addEdge(rumahAmel,rumahRudi,11);
    addEdge(rumahAmel,rumahBudi,5);
    addEdge(rumahBudi ,rumahAmel,5);
    addEdge(rumahRudi,rumahAmel,11);
    addEdge(rumahRudi,rumahTeti,10);
    printGraph(&G);   
    Vertex* arrRumah[10] = {rumahKiki, rumahAnton, rumahTeti, rumahMalik, rumahAmel, rumahRudi, rumahBudi};

}