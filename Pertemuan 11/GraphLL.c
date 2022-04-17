#include<stdio.h>
#include<stdlib.h>

struct node{
    char vertex;
    struct node *next;
};

struct node *gnode;

struct node *createNode(int vertex){
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

void createGraph(struct node *Adj[], int no_of_nodes){
    struct node *new_node, *last;
    int i,j, n, val;
    for(i = 0; i<no_of_nodes; i++){
        last = NULL;
        printf("\nEnter the number of %d : ", i);
        scanf("%d", &n);
        for (j = 1; j<= n; j++){
            printf("\nEnter the neighbour %d of %d : ", j , i);
            scanf("%d", &val);
            new_node = createNode(val);
            if(Adj[i] = NULL){
                Adj[i] = new_node;
            }else{
                last->next = new_node;
            }
            last = new_node;
        }
    }
}

void displayGraph(struct node *adj[], int no_of_nodes){
    struct node *ptr;
    int i;
    for(i = 0; i< no_of_nodes; i++){
        ptr = adj[i];
        printf("\nThe neighbours of node %d are : ", i);
        while(ptr != NULL){
            printf("%d\t", ptr->vertex);
            ptr= ptr->next;
        }
    }
}


void deleteGraph(struct node *Adj[], int no_of_nodes){
    int i;
    struct node *temp, *ptr;
    for(i = 0; i<= no_of_nodes; i++){
        ptr = Adj[i];
        while(ptr != NULL){
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
        Adj[i] =NULL;
    }
}