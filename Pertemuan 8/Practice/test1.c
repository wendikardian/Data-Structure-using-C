#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct barang{
    int id;
    char nama[20];
    int harga;
}barang;

int main(){
    barang toko[100];
    int i, length;
    scanf("%d", &length);
    for(i=0; i<length; i++){
        scanf("%d", &toko[i].id);
        scanf("%s", &toko[i].nama);
        scanf("%d", &toko[i].harga);
    }

    int j, k=0;
    scanf("%d", &j);
    while(toko[k].id != j){
        k++;
    }

    printf("%d\n", toko[k].id);
    printf("%s\n", toko[k].nama);
    printf("%d\n", toko[k].harga);
    
    return 0;	
}