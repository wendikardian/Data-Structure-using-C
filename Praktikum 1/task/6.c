#include<stdio.h>
#include<string.h>
// Wendi Kardian (2100016), PILKOM - A

// Fungsi polindrom yang menerima 2 parameter
// Parameter 1 : array word yang bertipe data char yang berisikan kata untuk dicek polindrom atau bukan
// Parameter 2 : panjang array char yang akan dicek polindrom atau bukan
int polindrom(char word[], int length){
    // Variabel start digunakan untuk  menghitung jumlah huruf yang sama dari yang awal dengan yang akhir
    // Variabel i digunakan untuk iterasi
    int start = 0, i;
    // Proses perulangan untuk mengecek apakah kata tersebut polindrom atau bukans
    // Proses pengecekan digunakan dari index ke 0 hingga pertengahan array tersebut
    for(i = 0; i<length/2;i++){
        // Proses pengecekan disamakan dari paling kanan dibandingkan ke paling kiri, hingga index array berada di tengah-tengah
        if(word[i] == word[length - i - 1]){
            // Ketika array yang berbalikan (kanan-kiri) itu sama berarti variabel start akan bertambah, yang berarti char itu sama
            start++;
        }
    }
    // Variabel result digunakan untuk nilai kembali
    int result;
    // Apabila jumlah start sama dengan index tengah array tersebut maka kata tersebut polindrom
    if(start == i){
        result = 1;
    }
    // Apabila jumlah start tidak sama dengan index tengah array tersebut maka kata tersebut tidak polindrom
    else{
        result = 0;
    }
    // Jika result = 1 berarti kata tersebut polindrom, jika result = 0 kata tersebut bukan polindrom
    // Nilai result akan dikembalikan ke prosedur utama
    return result;
}

void main(){
    // Deklarasi array 1 dimensi untuk menampung data kata yang akan diinputkan oleh user
    char word[20];
    int length;
    int start = 0;

    gets(word);
    // variabel length merupakan variabel yang berisikan panjang array yang diinputkan user
    length = strlen(word);

    // Memanggil fungsi polindrom dimana nilai kembalinya disimpan di variabel result
    int result = polindrom(word, length);

    // Jika result = 1 berarti kata tersebut polindrom, jika result = 0 kata tersebut bukan polindrom
    if(result == 1){
        printf("polindrom");
    }else{
        printf("Bukan polindrom"); 
    }
}