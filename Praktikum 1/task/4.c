#include<stdio.h>
// Wendi Kardian (2100016) - PILKOM A

void main(){
    // Deklarasi variabel untuk menampung panjangnnya array 2 dimensi
    // yang nantinya akan menjadi input yang akan di isi oleh user
    int row;
    scanf("%d", &row);
    // Deklarasi array 2 dimensi yang panjangnya ditentukan oleh input user
    char matriks[row][row];
    // Proses pengisian array dimana semakin bawah baris maka semakin sedikit kolom yang akan diisikannya
    int i,j;
    for(i = 0; i<row; i++){
        // Perlu dikurangi variabel i dalam iterasi tersebut agar semakin bawah barisnya
        // Maka kolom yang akan terbuat akan semakin sedikit
        for(j=0;j<row-i; j++){
            matriks[i][j] = '*';
        }
    }

    // Proses cetak array sesuai yang sudah diisikan sebelumnya
    for(i = 0; i<row; i++){
        for(j=0;j<row-i; j++){
            printf("%c ", matriks[i][j]);
        }
        printf("\n");
    }
}