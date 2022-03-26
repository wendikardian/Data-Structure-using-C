#include<stdio.h>
#include<string.h>
#include<math.h>
// Wendi Kardian (2100016), PILKOM A

void main(){
    // Variabel total digunakan untuk data yang nanti akan user input
    int total;
    // Variabel row digunakan untuk data panjang baris dan kolom suatu array 3 dimensi 
    int row;
    // Proses pengecekan panjang row yang nanti akan dialokasikan untuk membuat array
    scanf("%d", &total);
    // Proses menentukan row berdasarkan panjang array dari user input
    int k;
    for(k= 0; k<=total; k++){
        // Proses pengecekan range untuk panjang array tertentu
        // Hingga dapat ditentukan ordo dari array tersebut
        if(k*k < total && (k+1)*(k+1) >= total){
            row = k+1;
            break;
        }
    }

    // Deklarasi array 3 dimensi dimana :
    // dimensi 1 untuk baris, dimensi 2 untuk kolom, dimensi 3 untuk menampung string
    char matriks[row][row][10];
    int i,j;
    int count=0;
    // Proses looping untuk menerima input dari user kedalam array 3 dimensi
    for(i= 0; i<row; i++){
        for(j=0;j<row; j++){
            // Proses pengecekan apabila jumlah iterasi untuk input sudah memenuhi
            if(count == total){
                break;
            }
            scanf("%s",&matriks[i][j]);
            // Penambahan nilai count 1, apabila sudah memasukan input
            count += 1;
            
        }
    }
    // Mereset nilai count
    count =0;
    // Proses iterasi untuk menampilkan array 3 dimensi yang sudah di input oleh user
    for(i= 0; i<row; i++){
        for(j=0;j<row; j++){
            // Proses pengecekan apabila jumlah iterasi untuk input sudah memenuhi
            if(count == total){
                break;
            }
            printf("%s   ", matriks[i][j]);
            count +=1;
            
        }
        printf("\n");
    }
}