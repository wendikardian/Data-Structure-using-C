#include<stdio.h>
typedef struct titik{
    int x;
    int y;
}Titik;

typedef struct garis{
    Titik titikAwal;
    Titik titikAkhir;
}Garis;

typedef struct persegi{
    Garis sisi1;
    Garis sisi2;
    Garis sisi3;
    Garis sisi4;
}Persegi;


void input(Persegi *);
void output(Persegi);

void input(Persegi *a){
    printf("Untuk sisi 1 : ");
    scanf("%d %d %d %d", &a->sisi1.titikAwal.x, &a->sisi1.titikAwal.y, &a->sisi1.titikAkhir.x, &a->sisi1.titikAkhir.y);
    printf("Untuk sisi 2 : ");
    scanf("%d %d %d %d", &a->sisi2.titikAwal.x, &a->sisi2.titikAwal.y, &a->sisi2.titikAkhir.x, &a->sisi2.titikAkhir.y);
    printf("Untuk sisi 3 : ");
    scanf("%d %d %d %d", &a->sisi3.titikAwal.x, &a->sisi3.titikAwal.y, &a->sisi3.titikAkhir.x, &a->sisi3.titikAkhir.y);
    printf("Untuk sisi 4 : ");
    scanf("%d %d %d %d", &a->sisi4.titikAwal.x, &a->sisi4.titikAwal.y, &a->sisi4.titikAkhir.x, &a->sisi4.titikAkhir.y);
    
    
}


void output(Persegi a){
    printf("sisi sisi di persegi ini adalah : \n");
    printf("Sisi 1 (x,y) (x,7) : (%d, %d) (%d, %d)\n", a.sisi1.titikAwal.x, a.sisi1.titikAwal.y, a.sisi1.titikAkhir.x, a.sisi1.titikAkhir.y);
    printf("Sisi 2 (x,y) (x,7) : (%d, %d) (%d, %d)\n", a.sisi2.titikAwal.x, a.sisi2.titikAwal.y, a.sisi2.titikAkhir.x, a.sisi2.titikAkhir.y);
    printf("Sisi 3 (x,y) (x,7) : (%d, %d) (%d, %d)\n", a.sisi3.titikAwal.x, a.sisi3.titikAwal.y, a.sisi3.titikAkhir.x, a.sisi3.titikAkhir.y);
    printf("Sisi 4 (x,y) (x,7) : (%d, %d) (%d, %d)\n", a.sisi4.titikAwal.x, a.sisi4.titikAwal.y, a.sisi4.titikAkhir.x, a.sisi4.titikAkhir.y);
}

int main(){
    Persegi persegiGroup;
    input(&persegiGroup);
    output(persegiGroup);


    return 1;
}