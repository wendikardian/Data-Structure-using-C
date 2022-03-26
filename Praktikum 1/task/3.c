#include<stdio.h>
#include<string.h>
// Wendi Kardian (2100016) - PILKOM A

void main(){
    // Variabel untuk menentukan panjang ordo dan simbol apa yang akan dituliskan
    int row;
    char simbols;
    // Input untuk simbol yang akan ditampilkan
    scanf("%d", &row);
    scanf(" %c", &simbols);
    // mendeklarasikan array berdasarkan ordo yang diinputkan oleh user
    char matriks[row][row];

    // Proses input char dari input user kedalam array
    int i,j;
    for(i = 0; i<row; i++){
        for(j=0;j<row; j++){
            matriks[i][j] = simbols;
        }
    }

    // Proses menampilkan data dari array 2 dimensi yang sudah di isi
    // Proses untuk melakukan looping untuk mencetak berdasarkan baris
    for(i = 0; i<row; i++){
        // Proses untuk melakukan looping untuk mencetak berdasarkan kolom
        for(j=0;j<row; j++){
            printf("%c ", matriks[i][j]);
        }
        printf("\n");
    }
}