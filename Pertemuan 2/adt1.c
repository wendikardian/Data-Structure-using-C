#include<stdio.h>
#include<string.h>

typedef struct mahasiswa{
    int nim;
    char nama[20];
    int usia;
    char kelas[10];
}Mahasiswa;

int main(){
    int i;
    Mahasiswa dataMahasiswa[3];

    for(i=0; i<3; i++){
        printf("NIM : ");
        scanf("%d",&dataMahasiswa[i].nim);
        printf("Nama : ");
        scanf("%s",dataMahasiswa[i].nama);   
        // gets(dataMahasiswa[i].nama);
        printf("Usia : ");
        scanf("%d",&dataMahasiswa[i].usia);   
        printf("Kelas : ");
        // gets(dataMahasiswa[i].nama);
        scanf(" %s",dataMahasiswa[i].kelas);   
    }

    for(i = 0; i<3; i++){
        printf("Data Mahasiswa ke %d\n",i+1);
        printf("Nama : %s \n", dataMahasiswa[i].nama);
        printf("NIM : %d \n",dataMahasiswa[i].nim);
        printf("Usia : %d \n",dataMahasiswa[i].usia);
        printf("Kelas : %s \n",dataMahasiswa[i].kelas);
        printf("\n\n");
    }

    return 0;
}