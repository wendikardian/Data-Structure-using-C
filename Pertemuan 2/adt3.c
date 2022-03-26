#include<stdio.h>

typedef struct dosen{
    char nip[10];
    char nama[20];
    char tanggalLahir[20];
}Dosen;

int main(){
    Dosen dataDosen[3];
    int i;
    for(i=0; i<3; i++){
        printf("NIP : ");
        scanf("%s", &dataDosen[i].nip);
        printf("NAMA : ");
        scanf("%s", dataDosen[i].nama);
        printf("TGL : ");
        scanf(" %s", dataDosen[i].tanggalLahir);
    }

    for(i = 0; i<3; i++){
        printf("Data dosen ke %d\n",i+1);
        printf("Nama : %s \n", dataDosen[i].nama);
        printf("NIP : %s \n",dataDosen[i].nip);
        printf("Tanggal Lahir : %s \n", dataDosen[i].tanggalLahir);
        printf("\n\n");
    }
}