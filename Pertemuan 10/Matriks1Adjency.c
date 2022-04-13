#include <stdio.h>
#include <stdlib.h>
#define maxVertex 20
int adj[maxVertex][maxVertex];
int n;

void createGraph(){
    int i, max_edges, origin, destin;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    max_edges = n * (n-1);
    for(i = 1; 1<= max_edges; i++){
        printf("masukan titik (0,0) untuk keluar : ");
        scanf("%d %d", &origin, &destin);
        if(origin == 0 && destin == 0){
            break;
        }
        if(origin > n || destin > n || origin <= 0 || destin <= 0){
            printf("\nInput Salah");
        }else{
            adj[origin][destin] = 1;
        }

    }
}

void insert_graph(){
    int i;
    n++;
    printf("\nNode yang dimasukan adalah : %d", n);
    for(i = 1; i<= n; i++){
        adj[i][n] = 0;
        adj[n][i] = 0;
    }
}


void displayGraph(){
    int i, j;
    for(i = 1; i<= n; i++){
        for(j = 1; j<= n; j++){
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
}

void deleteGraph(char u){
    int i, j;
    if(n == 0){
        printf("\nGraph kosong");
    }
    else if(u > n){
        printf("Node tidak ada di dalam graph");
    }else{
        for(i = u; i<= n; i++){
            for(j = 1; j<= n; j++){
                adj[j][i] = adj[j][i+1];
                adj[i][j] = adj[i+1][j];
            }
        }
    }
}




int main(){
    int option;
    int node, origin, destin;
    createGraph();
    do{
        printf("\n 1. Insert data");
        printf("\n 2. Delete data");
        printf("\n 3. Display Graph");
        printf("\n 4. Delete Graph");
        printf("\n\n Masukan pilihan anda");
        scanf("%d", &option);
        switch(option){
            case 1:
                insert_graph();
                break;
            case 2:
                printf("Node yang mau di hapus : ");
                scanf("%d", &node);
                deleteGraph(node);
                break;
            case 3:
                displayGraph();
                break;
            case 4:
                printf("\n\n Bye");
                break;
            default :
                printf("\nInput salah\n");
                break;
        }
        
    }while(option != 4);
}