#include <stdio.h>

int usia[10] = {};
int dataUsia;
int i;
int main(){
    for(i = 0; i< 10; i++){
        printf("Masukan Data Usia : ");
        scanf("%d", &dataUsia);
        usia[i] = dataUsia;
    }
    
    printf("\n\n");
    printf("Data Usia adalah : ");
    for(i = 0; i< 10; i++){
        printf("%d", &usia[j]);
    }

}