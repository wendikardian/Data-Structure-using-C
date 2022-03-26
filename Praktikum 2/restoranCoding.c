#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct makanan{
    char nama[20];
    int harga;
    int total;
}Makanan;

int main() {

    int total,i;
    scanf("%d", &total);
    Makanan listMakanan[total];

    for(i = 0; i<total; i++){
        fgets(listMakanan[i].nama,sizeof(listMakanan[i].nama), stdin);
        gets(listMakanan[i].nama);
        scanf("%d", &listMakanan[i].harga);
        scanf("%d", &listMakanan[i].total);        
    }


    int totalHarga = 0;
    int perMenu;
    for(i=0; i<total;i++){
        perMenu = 0;
        perMenu = listMakanan[i].harga * listMakanan[i].total;
        totalHarga += perMenu;
    }

    printf("%d", totalHarga);

    
    return 0;
}
