#include<stdio.h>
// Wendi Kardian (2100016) - PILKOM A

int main(){
    // deklarasi variabel untuk menampung panjang array
    int arrayLength;
    // menerima input user untuk panjang array yang akan dibuat
    scanf("%d", &arrayLength);
    // Deklarasi array 1 dimensi yang panjangnya tergantung input dari user
    int array[arrayLength];
    // Deklarasi variabel untuk iterasi perulangan
    int i;
    for(i = 0; i< arrayLength; i++){
        // Proses input data kedalam array hingga penuh sesuai input user
        scanf("%d", &array[i]);
    }
    // Menentukan titik tengah pada array
    int mid;
    if(arrayLength%2 == 0){
        // Apabila blangan itu genap maka nilai tengahnya ada pembagian bilangan bulat panjang array tersebut dibagi dengan 2 dan dikurangi 1 (agar bilangannya itu bulat ke kiri)
        mid = (arrayLength/ 2)-1;
    }else{
        // Menentukan nilai tengah apabila panjang array ganjil 
        mid = arrayLength/2;
    }
    // Mencetak nilai pertama pada array
    printf("%d\n", array[0]);
    // Mencetak nilai tengah pada array
    printf("%d\n", array[mid]);
    // Mencetak nilai akhir pada array
    printf("%d\n", array[arrayLength-1]);
}