#include <stdio.h>
#include <stdlib.h>

typedef struct mahasiswa{
    char nama[30];
    int usia;
    char nim[10];
}Mahasiswa;


int main(){
    Mahasiswa mahasiswaUpi[20];
    int total;
    scanf("%d", &total);
    int i;
    for(i = 0; i<total; i++){
        scanf("%s",mahasiswaUpi[i].nama);
        scanf("%d",&mahasiswaUpi[i].usia);
        scanf("%s",mahasiswaUpi[i].nim);
    }
    for(i = total-1; i>=0; i--){
        printf("%s\n", mahasiswaUpi[i].nama);       
        printf("%d\n", mahasiswaUpi[i].usia);       
        printf("%s\n", mahasiswaUpi[i].nim);       
    }
    return 0;
}