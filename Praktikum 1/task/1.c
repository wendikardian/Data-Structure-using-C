#include<stdio.h>
// Wendi Kardian (2100016) - PILKOM A

void main(){
    // Mendeklarasikan array 2 dimensi dengan tipedata char dimana array dimensi pertama digunakan
    // untuk menampung data nama-nama bulan dari januari hingga desember
    // lalu array pada dimensi ke-2 digunakan untuk menampung kumpulan character yang membentuk string bulan
    char month[12][12] ={"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
    // Mendeklarasikan tipe data integer untuk inputan user yang menampung urutan bulan
    int data;
    //Menerima inputan user yang akan dimasukan ke variabel data
    scanf("%d",&data);
    // Mencetak array data berdasarkan inputan user yang dikurangi satu hingga menjadi index array bulan tersebut
    
    // Mengecek apakah data yang diinput user sudah benar (0<x<13) sesuai dengan jumlah bulan
    if(data >= 1 && data<= 12){
        printf("%s",month[data-1]);
    }else{
        printf("Tidak ada bulan %d", data);
    }

}