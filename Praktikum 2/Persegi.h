#include<stdio.h>

typedef struct titik{
    int X;
    int Y;
}Titik; 

typedef struct garis{
    Titik awal;
    Titik akhir;
}Garis;

typedef struct persegi{
    Garis sisi1;
    Garis sisi2;
    Garis sisi3;
    Garis sisi4;
}Persegi;


Persegi inputPersegi(Persegi p){
    printf("Untuk sisi1 : \n");
    scanf("%d %d %d %d", (&p.sisi1.awal.X), (&p.sisi1.awal.Y),(&p.sisi1.akhir.X), (&p.sisi1.akhir.Y));
    printf("Untuk sisi2 : \n");
    scanf("%d %d %d %d", (&p.sisi2.awal.X), (&p.sisi2.awal.Y),(&p.sisi2.akhir.X), (&p.sisi2.akhir.Y));
    printf("Untuk sisi3 : \n");
    scanf("%d %d %d %d", (&p.sisi3.awal.X), (&p.sisi3.awal.Y),(&p.sisi3.akhir.X), (&p.sisi3.akhir.Y));
    printf("Untuk sisi4 : \n");
    scanf("%d %d %d %d", (&p.sisi4.awal.X), (&p.sisi4.awal.Y),(&p.sisi4.akhir.X), (&p.sisi4.akhir.Y));
    return p;
}

void printPersegi(Persegi p){
    printf("Persegi yang dibentuk terdiri dari 4 sisi yang tersusun:\n");
    printf("Sisi 1 dari titik (%d,%d) ke (%d,%d)\n",p.sisi1.awal.X, 
    p.sisi1.awal.Y, p.sisi1.akhir.X, p.sisi1.akhir.Y);
    printf("Sisi 2 dari titik (%d,%d) ke (%d,%d)\n",p.sisi2.awal.X, 
    p.sisi2.awal.Y, p.sisi2.akhir.X, p.sisi2.akhir.Y);
    printf("Sisi 3 dari titik (%d,%d) ke (%d,%d)\n",p.sisi3.awal.X, 
    p.sisi3.awal.Y, p.sisi3.akhir.X, p.sisi3.akhir.Y);
    printf("Sisi 4 dari titik (%d,%d) ke (%d,%d)\n",p.sisi4.awal.X, 
    p.sisi4.awal.Y, p.sisi4.akhir.X, p.sisi4.akhir.Y);
}