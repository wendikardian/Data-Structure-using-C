#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mahasiswa{
    int nim;
    int usia;
    char nama[20];
}Mahasiswa;


void isiData(Mahasiswa *mahasiswaUpi){
    printf("NIM : ");
    scanf("%d",&mahasiswaUpi->nim);
    printf("Nama: ");
    scanf("%s",mahasiswaUpi->nama);
    printf("usia : ");
    scanf("%d",&mahasiswaUpi->usia);
}

void printData(Mahasiswa *mahasiswaUpi){
    printf("\nNim     : %d", mahasiswaUpi->nim);
    printf("\nNama    : %s", mahasiswaUpi->nama);
    printf("\nUsia    : %d", mahasiswaUpi->usia);
}

int main(){
    Mahasiswa mahasiswaUpi[20]; //deklarasi array berdasarkan adt yang udah di buat
    int total;
    printf("Masukan berapa banyak data yang mau di input: ");
    scanf("%d", &total);
    //cetak data
    int i;
    //buat ngisi data
    for(i=0; i<total; i++){
        isiData(&mahasiswaUpi[i]);
    }
    for(i = 0; i< total; i++){
        printf("\n\nData mahasiswa ke %d \n", i+1);
        printData(&mahasiswaUpi[i]);
    } 
}
