#include <stdio.h>
int N, M;
void createAdjMatrix(int Adj[][N + 1],
                     int arr[][2])
{
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            Adj[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        int x = arr[i][0];
        int y = arr[i][1];
        Adj[x][y] = 1;
        Adj[y][x] = 1;
    }
}
void printAdjMatrix(int Adj[][N + 1])
{

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            printf("%d ", Adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Rama = 1\n");
    printf("Ella = 2\n");
    printf("Katie = 3\n");
    printf("Lee = 4\n");
    printf("Bob = 5\n");
    printf("Sam = 6\n");
    printf("Zahir = 7\n");
    printf("Swati = 8\n");
    printf("Tom = 9\n");
    printf("Arun = 10\n");
    N = 10;
    int arr[][2]
        = { { 1, 2 }, { 1, 5 }, { 1, 3 }, {2, 5}, {3, 4}, {3, 8},
            {4, 5}, {4, 6}, {4, 7}, {4, 8}, {5, 6}, {5, 7}, {5, 9}, 
            {6, 7}, {6, 9}, {6, 10}, {7, 8}, {7, 10}  };
    M = sizeof(arr) / sizeof(arr[0]);
    int Adj[N + 1][N + 1];
    createAdjMatrix(Adj, arr);
    printAdjMatrix(Adj);
    return 0;
}