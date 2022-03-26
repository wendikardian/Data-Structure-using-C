// #include <stdio.h>

// int main(){
//     int i;
//     int array[4] = {14,23,15,23};

//     for(i = 0; i< 4 ; i++){
//         printf("%d ", array[i]);
//     }
// }

// #include <stdio.h>

// int main(){
//     int array[20];
//     strcpy(array, "Hello");
//     puts(array);
// }

// #include <stdio.h>

// int main(){
//     int i;
//     int array[4] = {14,23,15,23};

//     for(i = 0; i< 4 ; i++){
//         printf("%d ", array[i]);
//     }
// }


// #include <stdio.h>
// #include <string.h>

// int main(){
//     char array[20];
//     char secondArray[30] = {"Hello, World"};
//     strcpy(array, secondArray);
//     puts(array);
//     gets(array);
//     puts(array);

//     return 0;
// }


// #include<stdio.h>
// #include<string.h>

// int main(){
//     int i, array[5];
//     for(i = 0; i< 5; i++){
//         printf("Array ke-[%d] : ", i);
//         scanf("%d", &array[i]);
//     }

//         printf("\n\n ");
//     for(i = 0; i<5; i++){
//         printf("%d   ", array[i]);
//     }
// }


// #include <stdio.h>

// void main(){
//     char huruf[5] = {'W', 'E', 'N', 'D', 'I'} ;
//     printf("%c", huruf[2]);
// }

// #include<stdio.h>

// void main(){
//     int total = 20;
//     int ukuranSepatu[20];
//     int i;
//     for(i = 0; i<total; i++){
//         printf("Ukuran sepatu siswa ke %d : ", i+1);
//         scanf("%d", &ukuranSepatu[i]);
//     }

//     for(i = 0; i<total; i++){
//         printf("%d ", ukuranSepatu[i]);
//     }

// }


#include <stdio.h>
#include <stdlib.h>

void main(){
    int cols, rows;
    // int *mat = (int *)calloc(rows * cols, sizeof(int));

    
    scanf("%d", &rows);
    scanf("%d", &cols);
    int matriks[rows][cols];
    int i,j;
    for(i=0; i<rows; i++){
        for(j = 0; j<rows; j++){
            scanf("%d", &matriks[i][j]);
        }
    }

    printf("\n\n");

    for(i=0; i<rows; i++){
        for(j = 0; j<rows; j++){
            printf("%d ", matriks[i][j]);
        }
        printf("\n");
    }
}